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
 * @file SubscriberMain.cpp
 */
#include "SubscriberModule.hpp"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastrtps/Domain.h>

using namespace eprosima::fastdds::dds;

/* ARGUMENTS
 * --notexit
 * --seed <int>
 * --samples <int>
 * --magic <str>
 * --publishers <int>
 */

int main(
        int argc,
        char** argv)
{
    int arg_count = 1;
    bool notexit = true;
    uint32_t seed = 7800;
    uint32_t samples = 10;
    uint32_t publishers = 1;
    std::string magic;

    while (arg_count < argc)
    {
        if (strcmp(argv[arg_count], "--notexit") == 0)
        {
            notexit = true;
        }
        else if (strcmp(argv[arg_count], "--seed") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--seed expects a parameter" << std::endl;
                return -1;
            }

            seed = strtol(argv[arg_count], nullptr, 10);
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
        else if (strcmp(argv[arg_count], "--publishers") == 0)
        {
            if (++arg_count >= argc)
            {
                std::cout << "--publishers expects a parameter" << std::endl;
                return -1;
            }

            publishers = strtol(argv[arg_count], nullptr, 10);
        }
        else
        {
            std::cout << "Wrong argument " << argv[arg_count] << std::endl;
            return -1;
        }

        ++arg_count;
    }

    SubscriberModule subscriber(publishers, samples);

    if (subscriber.init(seed, magic))
    {
        return subscriber.run(notexit) ? 0 : -1;
    }

    return -1;
}
