#define REO_OBJECT_LIFETIME_TEST_ENTRY legacy_object_lifetime_entry
#include "game/native/gameplay_collision/object_lifetime_tests.cpp"

int main(int argc,char** argv){
    const int baseline=legacy_object_lifetime_entry(argc,argv);if(baseline)return baseline;
    use_real_model_provider=true;lifetime_fixture::real_model_bindings=true;
    const auto old_created=created,old_updates=updates,old_disables=disables,old_checks=checks;
    std::ifstream manifest(argv[1]);std::string line;
    while(std::getline(manifest,line)){
        std::istringstream f(line);std::array<std::string,6> fields;for(auto& s:fields)std::getline(f,s,'\t');if(fields[0].empty())continue;
        const auto map=load((fields[3]+".model-map").c_str());check(map.size()==32,"owned bounded room model remap");std::memcpy(real_model_map.data(),map.data(),32);
        for(unsigned variant=0;variant<2;++variant)room(fields[0].c_str(),fields[1].c_str(),unsigned(std::stoi(fields[2])),fields[3].c_str(),fields[4].c_str(),fields[5].c_str(),variant);
    }
    check(real_binding_rooms==14&&real_binding_instances>0,"real model provider exercised actual room lifetimes");
    check(real_model_refusal_cases>0,"native model admission refusal reaches caller");
    check(real_numeric_refusal_cases==real_model_refusal_cases,"numeric and model preflight refusal cohorts exercised");
    std::printf("{\"status\":\"passed\",\"checks\":%u,\"real_rooms\":%u,\"real_instances\":%u,\"created\":%u,\"updates\":%u,\"disables\":%u,\"model_refusal_cases\":%u,\"numeric_refusal_cases\":%u,\"game_launched\":false}\n",checks-old_checks,real_binding_rooms,real_binding_instances,created-old_created,updates-old_updates,disables-old_disables,real_model_refusal_cases,real_numeric_refusal_cases);
    return 0;
}
