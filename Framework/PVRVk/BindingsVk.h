/*!
\brief Vulkan bindings with device-specific (where applicable) or instance-specific (where not) function pointers.
The PowerVR Framework uses them to allow the efficient, direct-to-device function calling allowed by vulkan. 
Current iteration only supports a single device as the function pointers are loaded with the global vk:initVk.
\file PVRVk/BindingsVk.h
\author PowerVR by Imagination, Developer Technology Team
\copyright Copyright (c) Imagination Technologies Limited.
*/
//!\cond NO_DOXYGEN
#pragma once
#include "PVRVk/HeadersVk.h"

#include <algorithm>
#include <vector>
#include <memory>
#include <string.h>

#define PVR_VULKAN_FUNCTION_POINTER_DECLARATION(function_name) static PFN_vk##function_name function_name;

/// <summary>This class contains function pointers to all Vulkan functions. These function pointers will be
/// populated on the initVk call. Use normally, using the vk class as a namespace. For example
/// vk::CmdBindPipeline(...);</summary>
class vk
{
public:
	static void initVk(VkInstance instance, VkDevice device);

	static bool initVulkan();

	static bool initVulkanInstance(VkInstance instance);

	static bool initVulkanDevice(VkDevice device);

#undef CreateSemaphore
#undef CreateEvent

	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(AcquireNextImageKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(AllocateCommandBuffers);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(AllocateDescriptorSets);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(AllocateMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(BeginCommandBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(BindBufferMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(BindImageMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBeginQuery);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBeginRenderPass);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBindDescriptorSets);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBindIndexBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBindPipeline);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBindVertexBuffers);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdBlitImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdClearAttachments);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdClearColorImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdClearDepthStencilImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdCopyBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdCopyBufferToImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdCopyImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdCopyImageToBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdCopyQueryPoolResults);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDispatch);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDispatchIndirect);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDraw);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDrawIndexed);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDrawIndexedIndirect);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdDrawIndirect);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdEndQuery);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdEndRenderPass);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdExecuteCommands);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdFillBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdNextSubpass);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdPipelineBarrier);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdPushConstants);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdResetEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdResetQueryPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdResolveImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetBlendConstants);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetDepthBias);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetDepthBounds);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetLineWidth);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetScissor);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetStencilCompareMask);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetStencilReference);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetStencilWriteMask);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdSetViewport);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdUpdateBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdWaitEvents);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CmdWriteTimestamp);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateBufferView);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateCommandPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateComputePipelines);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateDescriptorPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateDescriptorSetLayout);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateDevice);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateFence);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateFramebuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateGraphicsPipelines);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateImageView);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreatePipelineCache);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreatePipelineLayout);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateQueryPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateRenderPass);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateSampler);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateSemaphore);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateShaderModule);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyBufferView);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyCommandPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyDescriptorPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyDescriptorSetLayout);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyDevice);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyFence);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyFramebuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyImage);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyImageView);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyPipeline);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyPipelineCache);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyPipelineLayout);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyQueryPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyRenderPass);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroySampler);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroySemaphore);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyShaderModule);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DeviceWaitIdle);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EndCommandBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EnumerateDeviceExtensionProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EnumerateDeviceLayerProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EnumerateInstanceExtensionProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EnumerateInstanceLayerProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(FlushMappedMemoryRanges);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(FreeCommandBuffers);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(FreeDescriptorSets);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(FreeMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetBufferMemoryRequirements);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetDeviceMemoryCommitment);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetDeviceProcAddr);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetDeviceQueue);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetEventStatus);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetFenceStatus);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetImageMemoryRequirements);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetImageSparseMemoryRequirements);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetImageSubresourceLayout);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetInstanceProcAddr);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceFeatures);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceFormatProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceImageFormatProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceMemoryProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceQueueFamilyProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceSparseImageFormatProperties);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPipelineCacheData);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetQueryPoolResults);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetRenderAreaGranularity);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(InvalidateMappedMemoryRanges);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(MapMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(MergePipelineCaches);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(QueueBindSparse);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(QueueSubmit);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(QueueWaitIdle);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(ResetCommandBuffer);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(ResetCommandPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(ResetDescriptorPool);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(ResetEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(ResetFences);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(SetEvent);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(UnmapMemory);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(UpdateDescriptorSets);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(WaitForFences);

	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateInstance);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateSwapchainKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyInstance);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroySurfaceKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroySwapchainKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(EnumeratePhysicalDevices);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceSurfaceCapabilitiesKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceSurfaceFormatsKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceSurfacePresentModesKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceSurfaceSupportKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetSwapchainImagesKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(QueuePresentKHR);

	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateDebugReportCallbackEXT);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DebugReportMessageEXT);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(DestroyDebugReportCallbackEXT);

	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceProperties2KHR);

#ifdef ANDROID
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateAndroidSurfaceKHR);
#elif defined(VK_USE_PLATFORM_WIN32_KHR)
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateWin32SurfaceKHR);
	// expose both of them so one of them get used.
#elif defined(VK_USE_PLATFORM_XLIB_KHR) || defined(VK_USE_PLATFORM_XCB_KHR)
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateXlibSurfaceKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateXcbSurfaceKHR);
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateWaylandSurfaceKHR);
#elif defined(VK_USE_PLATFORM_IOS_MVK)
    PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateIOSSurfaceMVK);
#elif defined(VK_USE_PLATFORM_MACOS_MVK)
    PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateMacOSSurfaceMVK);
#else
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetPhysicalDeviceDisplayPropertiesKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(GetDisplayModePropertiesKHR);
	PVR_VULKAN_FUNCTION_POINTER_DECLARATION(CreateDisplayPlaneSurfaceKHR);
#endif
};

#undef PVR_VULKAN_FUNCTION_POINTER_DECLARATION
//!\endcond
