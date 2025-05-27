// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef _FASTDDS_RTPS_THROUGHPUT_CONTROLLER_DESCRIPTOR_H
#define _FASTDDS_RTPS_THROUGHPUT_CONTROLLER_DESCRIPTOR_H

#include <fastrtps/fastrtps_dll.h>
#include <cstdint>

namespace eprosima{
namespace fastrtps{
namespace rtps{

/**
 * Descriptor for a Throughput Controller, containing all constructor information
 * for it.
 * @ingroup NETWORK_MODULE
 */
struct ThroughputControllerDescriptor
{
    //! Packet size in bytes that this controller will allow in a given period.
    uint32_t bytesPerPeriod; // 表示在指定的时间窗口内允许传输的数据量（以字节为单位）
    //! Window of time in which no more than 'bytesPerPeriod' bytes are allowed.
    uint32_t periodMillisecs; // 表示时间窗口的大小（以毫秒为单位）

    RTPS_DllAPI ThroughputControllerDescriptor();
    RTPS_DllAPI ThroughputControllerDescriptor(uint32_t size, uint32_t time);

    bool operator==(const ThroughputControllerDescriptor& b) const
    {
        return (this->bytesPerPeriod == b.bytesPerPeriod) &&
               (this->periodMillisecs == b.periodMillisecs);
    }
};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif // THROUGHPUT_CONTROLLER_DESCRIPTOR_H
