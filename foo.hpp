#pragma once

#include "Human.hpp"

#include <list>
#include <memory>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    constexpr char            yn[]{'y', 'n'};
    auto                      people_size = people.size();
    std::unique_ptr< char[] > output{std::make_unique< char[] >(people_size)};
    size_t                    iter = people_size;
    for (auto& person : people) {
        person.birthday();
        output[--iter] = yn[(size_t)person.isMonster()];
    }
    return std::vector< char >(&output[0], &(output[0]) + people_size);
}