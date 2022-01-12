#pragma once

struct ID3D11Device;
struct IDXGISwapChain;
struct ID3D11RenderTargetView;
struct ID3D11DepthStencilView;
struct ID3D11Resource;
struct ID3D11Texture2D;
struct ID3D11DeviceContext;

namespace Talon
{
	class Window;
}

namespace Pteron
{
	class DeviceManager
	{
	public:
		void Initialize(Talon::Window* window);
		void ShutDown();

		void Resize();

	private:
		DeviceManager();
		DeviceManager(const DeviceManager&) = delete;
		virtual ~DeviceManager();

		DeviceManager& operator=(const DeviceManager&) = delete;

		void CreateDeviceAndSwapChain(Talon::Window* window);
		void CreateDepthStencilBuffer(Talon::Window* window);

		Talon::Window* m_Window;

		ID3D11Device* m_Device;
		IDXGISwapChain* m_SwapChain;
		ID3D11RenderTargetView* m_RenderTargetView;
		ID3D11DepthStencilView* m_DepthStencilView;
		ID3D11Texture2D* m_DepthStencilTexture;
		ID3D11Texture2D* m_BackBufferTexture;

		ID3D11DeviceContext* m_Context;

	public:
		static DeviceManager* GetInstance() { return s_Instance; }
		static void Create() { s_Instance = new DeviceManager(); }
		static void Destroy() { delete s_Instance; s_Instance = nullptr; }
	private:
		static DeviceManager* s_Instance;
	};
}
