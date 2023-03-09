//
// Created by marvi on 07.03.2023.
//

#ifndef VULKANENGINE_VE_PIPELINE_H
#define VULKANENGINE_VE_PIPELINE_H

#include "ve_device.hpp"
#include <string>
#include <vector>

namespace ve {

    struct PipelineConfigInfo{
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout  pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class VePipeline {
    public:
        VePipeline(VeDevice &device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo configInfo);
        ~VePipeline();

        VePipeline(const VePipeline&) = delete;
        void operator=(const VePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        VeDevice& veDevice;
        VkPipeline  graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}

#endif //VULKANENGINE_VE_PIPELINE_H
