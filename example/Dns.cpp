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

#include <toolbox/io.hpp>
#include <toolbox/net.hpp>
#include <toolbox/sys.hpp>
#include <toolbox/util.hpp>

#include <fstream>
#include <iostream>

using namespace std;
using namespace toolbox;
using namespace toolbox::net;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    try {

        std::string nameserver;
        std::string hostname;

        Options opts{"Unit Test options [OPTIONS] [COMMAND]"};
        // clang-format off
        opts('s', Value{nameserver}, "ShortOption Description")
            ('h', "help", Help{}, "Help")
            (Value{hostname}.required(), "Hostname")
            ;
        // clang-format on

        opts.parse(argc, argv);

        if (nameserver.empty()) {
            std::ifstream resolv_conf{"/etc/resolv.conf"};
            DnsServers dns_servers{resolv_conf};
            nameserver = dns_servers.server();
        }

        const auto ip = toolbox::net::get_host_by_name(nameserver, hostname, DnsRequest::A);
        cout << ip << endl;

    } catch (const std::exception& e) {
        TOOLBOX_ERROR << "exception: " << e.what();
        return 1;
    }
    return 0;
}
