// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file PublisherMain.cpp
 */
#include "PublisherModule.hpp"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastrtps/Domain.h>

using namespace eprosima::fastdds::dds;

/* ARGUMENTS
 * --seed <int>
 * --wait <int>
 * --samples <int>
 * --magic <str>
 */

int main(
        int argc,
        char** argv)
{
    int arg_count = 1;
    uint32_t seed = 7800;
    uint32_t wait = 0;
    uint32_t samples = 40;
    std::string magic;

    while (arg_count < argc)
    {
        if (strcmp(argv[arg_count], "--seed") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--seed expects a parameter" << std::endl;
                return -1;
            }

            seed = strtol(argv[arg_count], nullptr, 10);
        }
        else if (strcmp(argv[arg_count], "--wait") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--wait expects a parameter" << std::endl;
                return -1;
            }

            wait = strtol(argv[arg_count], nullptr, 10);
        }
        else if (strcmp(argv[arg_count], "--samples") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--samples expects a parameter" << std::endl;
                return -1;
            }

            samples = strtol(argv[arg_count], nullptr, 10);
        }
        else if (strcmp(argv[arg_count], "--magic") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--magic expects a parameter" << std::endl;
                return -1;
            }

            magic = argv[arg_count];
        }
        else
        {
            std::cout << "Wrong argument " << argv[arg_count] << std::endl;
            return -1;
        }

        ++arg_count;
    }

    PublisherModule publisher;

    if (publisher.init(seed, magic))
    {
        if (wait > 0)
        {
            publisher.wait_discovery(wait);
        }

        publisher.run(samples);
        return 0;
    }

    return -1;
}
