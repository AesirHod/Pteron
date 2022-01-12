#include <d3d11.h>

#include "DeviceManager.h"
#include "Talon/Window/Window.h"

using namespace Talon;

namespace Pteron
{
	DeviceManager* DeviceManager::s_Instance = nullptr;

	DeviceManager::DeviceManager()
		: m_Window(nullptr)
		, m_Device(nullptr)
		, m_SwapChain(nullptr)
		, m_RenderTargetView(nullptr)
		, m_DepthStencilView(nullptr)
		, m_DepthStencilTexture(nullptr)
		, m_BackBufferTexture(nullptr)
		, m_Context(nullptr)
	{
	}

	DeviceManager::~DeviceManager()
	{
	}

	void DeviceManager::Initialize(Window* window)
	{
		CreateDeviceAndSwapChain(window);
		CreateDepthStencilBuffer(window);
	}

	void DeviceManager::ShutDown()
	{
		m_Device->Release();
		m_SwapChain->Release();
		m_RenderTargetView->Release();
		m_DepthStencilView->Release();
		m_DepthStencilTexture->Release();
		m_BackBufferTexture->Release();

		m_Context->Release();
	}

	void DeviceManager::CreateDeviceAndSwapChain(Window* window)
	{
		HRESULT result;

		m_Window = window;

		int width = 0;
		int height = 0;
		m_Window->GetClientSize(width, height);

		float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

		// TODO - Setup camera.

		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = m_Window->GetHwnd();
		swapChainDesc.Windowed = true;
		swapChainDesc.BufferDesc.Width = 0;
		swapChainDesc.BufferDesc.Height = 0;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

		result = D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			&featureLevel,
			1,
			D3D11_SDK_VERSION,
			&swapChainDesc,
			&m_SwapChain,
			&m_Device,
			nullptr,
			&m_Context
		);

		result = m_SwapChain->GetBuffer(0, __uuidof(m_BackBufferTexture), (void**)&m_BackBufferTexture);
		result = m_Device->CreateRenderTargetView(m_BackBufferTexture, NULL, &m_RenderTargetView);

		D3D11_VIEWPORT viewport;
		viewport.Width = static_cast<float>(width);
		viewport.Height = static_cast<float>(height);
		viewport.TopLeftY = viewport.TopLeftX = 0;
		viewport.MinDepth = 0;
		viewport.MaxDepth = 1;

		m_Context->RSSetViewports(1, &viewport);

		m_Context->OMSetRenderTargets(1, &m_RenderTargetView, nullptr);
	}

	void DeviceManager::CreateDepthStencilBuffer(Window* window)
	{
		HRESULT result;

		int width = 0;
		int height = 0;
		m_Window->GetClientSize(width, height);

		D3D11_TEXTURE2D_DESC depthBufferDesc;
		ZeroMemory(&depthBufferDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

		depthBufferDesc.ArraySize = 1;
		depthBufferDesc.MipLevels = 1;
		depthBufferDesc.Format = DXGI_FORMAT_D32_FLOAT;
		depthBufferDesc.Width = width;
		depthBufferDesc.Height = height;
		depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthBufferDesc.CPUAccessFlags = 0;
		depthBufferDesc.SampleDesc.Count = 1;
		depthBufferDesc.SampleDesc.Quality = 0;
		depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		depthBufferDesc.MiscFlags = 0;

		if (m_DepthStencilTexture)
		{
			m_DepthStencilTexture->Release();
			m_DepthStencilTexture = nullptr;
		}

		result = m_Device->CreateTexture2D(&depthBufferDesc, NULL, &m_DepthStencilTexture);

		D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
		ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

		depthStencilViewDesc.Texture2DArray.ArraySize = 0;
		depthStencilViewDesc.Texture2DArray.FirstArraySlice = 0;
		depthStencilViewDesc.Texture2DArray.MipSlice = 0;
		depthStencilViewDesc.Format = DXGI_FORMAT_D32_FLOAT;
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

		if (m_DepthStencilView)
		{
			m_DepthStencilView->Release();
			m_DepthStencilView = nullptr;
		}

		result = m_Device->CreateDepthStencilView(m_DepthStencilTexture, &depthStencilViewDesc, &m_DepthStencilView);

		m_Context->OMSetRenderTargets(1, &m_RenderTargetView, m_DepthStencilView);
	}

	void DeviceManager::Resize()
	{
		HRESULT result;

		int width = 0;
		int height = 0;
		m_Window->GetClientSize(width, height);

		float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

		// TODO - Setup camera.

		if (m_RenderTargetView)
		{
			m_RenderTargetView->Release();
			m_RenderTargetView = nullptr;
		}

		if (m_BackBufferTexture)
		{
			m_BackBufferTexture->Release();
			m_BackBufferTexture = nullptr;
		}

		if (m_DepthStencilView)
		{
			m_DepthStencilView->Release();
			m_DepthStencilView = nullptr;
		}

		result = m_SwapChain->ResizeBuffers(
			1,
			width,
			height,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
		);

		result = m_SwapChain->GetBuffer(0, __uuidof(m_BackBufferTexture), (void**)&m_BackBufferTexture);
		result = m_Device->CreateRenderTargetView(m_BackBufferTexture, NULL, &m_RenderTargetView);

		CreateDepthStencilBuffer(m_Window);

		D3D11_VIEWPORT viewport;
		viewport.Width = static_cast<float>(width);
		viewport.Height = static_cast<float>(height);
		viewport.TopLeftY = viewport.TopLeftX = 0;
		viewport.MinDepth = 0;
		viewport.MaxDepth = 1;

		m_Context->RSSetViewports(1, &viewport);

		m_Context->OMSetRenderTargets(1, &m_RenderTargetView, m_DepthStencilView);
	}
}
