#include "actor_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <atomic>
#include <fstream>
#include <future>
#include <iostream>
#include <source_location>
#include <sstream>

namespace world = reo::native::gameplay_world;
namespace {
std::size_t checks{},refusals{},owned_models{},owned_skeletons{},owned_absent_skeletons{},owned_absent_models{},owned_missing{};

void check(bool condition,std::source_location at = std::source_location::current()) {
    ++checks;
    if (!condition) throw std::runtime_error("Native actor asset check at "+std::to_string(at.line()));
}
template<class T> void put(std::vector<std::uint8_t>& bytes,std::size_t at,T value) {
    check(at <= bytes.size() && sizeof(value) <= bytes.size()-at);
    std::memcpy(bytes.data()+at,&value,sizeof(value));
}
template<class Action> void refused(Action action) {
    bool caught = false;
    try { action(); } catch (const std::exception&) { caught = true; }
    check(caught);
    ++refusals;
}

std::vector<std::uint8_t> bundle(bool skeleton = true) {
    std::vector<std::uint8_t> bytes(48+112);
    if (!skeleton) return bytes;
    put(bytes,0x24,48u);put(bytes,0x28,112u);
    put(bytes,48+4,2u);put(bytes,48+8,112u);
    put(bytes,60+4,1u);put(bytes,60+8,16u);put(bytes,60+12,0u);
    put(bytes,76,1u);put(bytes,76+4,1u);put(bytes,76+8,84u);
    const auto node = 88u;
    put(bytes,node+8,0xffffffffu);put(bytes,node+12,0xffffffffu);
    for (unsigned lane = 0; lane < 3; ++lane) put(bytes,node+0x10+4*lane,1.f);
    return bytes;
}

using File = std::pair<std::string,std::vector<std::uint8_t>>;
std::vector<std::uint8_t> afs(std::vector<File> files) {
    check(!files.empty());
    const auto aligned = [](std::size_t size) { return (size+2047u)&~std::size_t(2047u); };
    const auto names = 16+8*files.size();
    std::vector<std::uint8_t> bytes(aligned(names+48*files.size()));
    std::memcpy(bytes.data(),"AFS\0",4);put(bytes,4,std::uint32_t(files.size()));
    put(bytes,8+8*files.size(),std::uint32_t(names));
    put(bytes,12+8*files.size(),std::uint32_t(48*files.size()));
    for (std::size_t index = 0; index < files.size(); ++index) {
        auto& [name,payload] = files[index];
        check(name.size() < 32);
        std::memcpy(bytes.data()+names+48*index,name.data(),name.size());
        const auto offset = bytes.size();
        bytes.resize(aligned(offset+payload.size()));
        put(bytes,8+8*index,std::uint32_t(offset));
        put(bytes,12+8*index,std::uint32_t(payload.size()));
        std::memcpy(bytes.data()+offset,payload.data(),payload.size());
    }
    return bytes;
}

struct Memory final : reo::assets::PositionedSource {
    const std::vector<std::uint8_t> bytes;
    mutable std::atomic<unsigned> reads{},failures{};
    explicit Memory(std::vector<std::uint8_t> input) : bytes(std::move(input)) {}
    std::uint64_t size() const noexcept override { return bytes.size(); }
    std::size_t read(std::uint64_t offset,std::size_t length,void* output) const override {
        ++reads;
        if (failures.load() && offset == 4096) { --failures;throw std::runtime_error("Injected asset read failure"); }
        if (offset > bytes.size() || length > bytes.size()-offset) throw std::runtime_error("Fixture asset extent");
        std::memcpy(output,bytes.data()+offset,length);
        return length;
    }
};
std::shared_ptr<reo::assets::Source> source(std::vector<File> files) {
    return std::make_shared<reo::assets::Source>("native actor asset fixture",
        std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(std::move(files))}})));
}

void fixtures() {
    const auto payload = bundle();
    auto memory = std::make_shared<Memory>(afs({{"romdata_usa.afs",afs({{"e00_00.nbd",payload}})}}));
    const auto input = std::make_shared<reo::assets::Source>("native actor asset fixture",memory);
    world::ActorAssets assets(input);
    const auto asset = assets.read(0,0);
    check(asset && asset->name() == "E00_00.NBD" && asset->bytes().size() == payload.size());
    check(std::memcmp(asset->bytes().data(),payload.data(),payload.size()) == 0);
    check(asset->skeleton() && asset->skeleton()->nodes().size() == 1);
    const auto read_count = memory->reads.load();
    check(assets.read(0,0) == asset && memory->reads.load() == read_count);
    check(!assets.read(51,0) && memory->reads.load() == read_count);
    auto first = asset->make_instance(),second = asset->make_instance();
    check(first && second && first != second && &first->skeleton() == &second->skeleton());
    first->rebuild(reo::native::transform_math::identity());
    const auto retained = first->retain();
    second->local_translation(0,{10,20,30});
    second->rebuild(reo::native::transform_math::identity());
    check(retained && first->retain() == retained && second->world_translation(0).x == 10);
    check(first->world_translation(0).x == 0);
    world::ActorAssets concurrent(input);
    auto read_one = std::async(std::launch::async,[&] { return concurrent.read(0,0); });
    auto read_two = std::async(std::launch::async,[&] { return concurrent.read(0,0); });
    check(read_one.get() == read_two.get());
    world::ActorAssets retry(input);
    memory->failures = 1;
    refused([&] { (void)retry.read(0,0); });
    check(retry.read(0,0)->skeleton()->nodes().size() == 1);
    refused([&] { (void)world::ActorAssets(nullptr); });
    const auto wrong_directory = std::make_shared<reo::assets::Source>("invalid",
        std::make_shared<Memory>(afs({{"other.afs",afs({{"e00_00.nbd",payload}})}})));
    refused([&] { (void)world::ActorAssets(wrong_directory); });
    refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",payload},{"E00_00.NBD",payload}})).read(0,0); });
    refused([&] { (void)world::ActorAssets(source({{"other.nbd",payload}})).read(0,0); });
    refused([&] { (void)assets.read(62,0); });
    refused([&] { (void)assets.read(0,255); });
    refused([&] { (void)world::ActorAssets::model_name(153,world::ModelDefinitionBank::ordinary); });
    refused([&] { (void)world::ActorAssets::model_name(30,world::ModelDefinitionBank::alternate); });
    for (const auto field : {0x24u,0x28u}) {
        auto malformed = payload;put(malformed,field,UINT32_MAX);
        refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",malformed}})).read(0,0); });
    }
    auto cyclic = payload;put(cyclic,88+8,0u);
    refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",cyclic}})).read(0,0); });
    const auto absent = world::ActorAssets(source({{"e00_00.nbd",bundle(false)}})).read(0,0);
    check(absent && !absent->skeleton() && !absent->make_instance());
    check(world::ActorAssets::model_name(60,world::ModelDefinitionBank::ordinary) == "N200.NBD");
    check(world::ActorAssets::model_name(29,world::ModelDefinitionBank::alternate) == "HE43_01.NBD");
}

void owned(const std::filesystem::path& archive,const std::filesystem::path& manifest) {
    world::ActorAssets assets(std::make_shared<reo::assets::Source>(archive));
    std::ifstream rows(manifest),raw(archive,std::ios::binary);
    check(bool(rows) && bool(raw));
    std::string line;
    while (std::getline(rows,line)) {
        std::istringstream row(line);
        unsigned bank,type,variant;std::string name;std::uint64_t offset;std::size_t length,nodes;
        check(bool(row>>bank>>type>>variant>>name>>offset>>length>>nodes));
        const auto selected = bank ? world::ModelDefinitionBank::alternate : world::ModelDefinitionBank::ordinary;
        if (name == "-") {
            check(!assets.read(std::uint8_t(type),std::uint16_t(variant),selected));
            ++owned_absent_models;
            continue;
        }
        if (!length) {
            refused([&] { (void)assets.read(std::uint8_t(type),std::uint16_t(variant),selected); });
            ++owned_missing;
            continue;
        }
        std::shared_ptr<const world::ActorModelAsset> asset;
        try { asset = assets.read(std::uint8_t(type),std::uint16_t(variant),selected); }
        catch (const std::exception& error) { throw std::runtime_error(name+" "+error.what()); }
        check(asset && asset->name() == name && asset->bytes().size() == length);
        std::vector<std::uint8_t> expected(length);
        raw.seekg(std::streamoff(offset));raw.read(reinterpret_cast<char*>(expected.data()),std::streamsize(length));
        check(bool(raw) && std::memcmp(asset->bytes().data(),expected.data(),length) == 0);
        check(assets.read(std::uint8_t(type),std::uint16_t(variant),selected) == asset);
        const auto instance = asset->make_instance();
        check(bool(instance) == (nodes != 0));
        if (instance) {
            check(instance->nodes().size() == nodes);
            instance->rebuild(reo::native::transform_math::identity());
            check(instance->retain() && instance->retain()->joints.size() == nodes);
            ++owned_skeletons;
        } else ++owned_absent_skeletons;
        ++owned_models;
    }
    check(rows.eof());
}
}

int main(int argc,char** argv) try {
    fixtures();
    if (argc == 3) owned(argv[1],argv[2]);
    else check(argc == 1);
    std::cout<<"{\"checks\":"<<checks<<",\"refusals\":"<<refusals<<",\"owned_models\":"<<owned_models
             <<",\"owned_skeletons\":"<<owned_skeletons<<",\"owned_absent_skeletons\":"<<owned_absent_skeletons
             <<",\"owned_absent_models\":"<<owned_absent_models
             <<",\"owned_missing\":"<<owned_missing<<"}\n";
} catch (const std::exception& error) { std::cerr<<error.what()<<'\n';return 1; }
