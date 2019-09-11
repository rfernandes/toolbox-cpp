// The Reactive C++ Toolbox.
// Copyright (C) 2013-2019 Swirly Cloud Limited
// Copyright (C) 2019 Reactive Markets Limited
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

#include "Stream.hpp"

#include <sstream>

namespace toolbox {
inline namespace util {
using namespace std;

void reset(ostream& os) noexcept
{
    os.clear();
    os.fill(os.widen(' '));
    os.flags(ios_base::skipws | ios_base::dec);
    os.precision(6);
    os.width(0);
}

std::stringstream wrap_buffer(char* buf, int size)
{
    std::stringstream stream;
    stream.rdbuf()->pubsetbuf(buf, size);
    return stream;
}

} // namespace util
} // namespace toolbox
