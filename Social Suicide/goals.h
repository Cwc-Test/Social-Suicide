//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     goals data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

namespace goals {
    using nlohmann::json;
    
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }
    
    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    
    struct beauParleur {
        int64_t id;
        int64_t level;
        int64_t skill;
    };
    
    struct goals {
        beauParleur brillant;
        beauParleur beauParleur;
        beauParleur gorille;
        beauParleur musicien;
    };
}

namespace nlohmann {
    void from_json(const json & j, goals::beauParleur & x);
    void to_json(json & j, const goals::beauParleur & x);
    
    void from_json(const json & j, goals::goals & x);
    void to_json(json & j, const goals::goals & x);
    
    inline void from_json(const json & j, goals::beauParleur& x) {
        x.id = j.at("id").get<int64_t>();
        x.level = j.at("level").get<int64_t>();
        x.skill = j.at("skill").get<int64_t>();
    }
    
    inline void to_json(json & j, const goals::beauParleur & x) {
        j = json::object();
        j["id"] = x.id;
        j["level"] = x.level;
        j["skill"] = x.skill;
    }
    
    inline void from_json(const json & j, goals::goals& x) {
        x.brillant = j.at("brillant").get<goals::beauParleur>();
        x.beauParleur = j.at("Beau Parleur").get<goals::beauParleur>();
        x.gorille = j.at("Gorille").get<goals::beauParleur>();
        x.musicien = j.at("Musicien").get<goals::beauParleur>();
    }
    
    inline void to_json(json & j, const goals::goals & x) {
        j = json::object();
        j["brillant"] = x.brillant;
        j["Beau Parleur"] = x.beauParleur;
        j["Gorille"] = x.gorille;
        j["Musicien"] = x.musicien;
    }
}
