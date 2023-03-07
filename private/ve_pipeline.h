//
// Created by marvi on 07.03.2023.
//

#ifndef VULKANENGINE_VE_PIPELINE_H
#define VULKANENGINE_VE_PIPELINE_H

#include <string>
#include <vector>

namespace ve {
    class VePipeline {
    public:
        VePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
    };
}

#endif //VULKANENGINE_VE_PIPELINE_H
