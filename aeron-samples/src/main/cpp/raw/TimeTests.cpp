/*
 * Copyright 2015 Real Logic Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char** argv)
{
    cout << "system_clock resolution          ";
    cout << chrono::system_clock::period::num << "/";
    cout << chrono::system_clock::period::den << "\n";

    cout << "steady_clock resolution          ";
    cout << chrono::steady_clock::period::num << "/";
    cout << chrono::steady_clock::period::den << "\n";

    cout << "high_resolution_clock resolution ";
    cout << chrono::high_resolution_clock::period::num << "/";
    cout << chrono::high_resolution_clock::period::den << "\n";

    auto start = chrono::steady_clock::now();
    this_thread::sleep_for(chrono::nanoseconds(1));
    auto end = chrono::steady_clock::now();

    auto diff = end - start;

    cout << "sleep_for min duration:          ";
    cout << std::chrono::duration<long, std::nano>(diff).count() << " ns\n";

    start = chrono::steady_clock::now();
    this_thread::yield();
    end = chrono::steady_clock::now();
    diff = end - start;

    cout << "yield min duration:              ";
    cout << std::chrono::duration<long, std::nano>(diff).count() << " ns\n";

    return 0;
}

