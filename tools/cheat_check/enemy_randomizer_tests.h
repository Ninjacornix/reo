#include "../../runtime/mods/enemy_randomizer.h"
#include "../../runtime/mods/enemy_spawn_randomizer.h"
#include <tuple>
inline void testEnemyRandomizer() {
    using namespace reo::cheats;
    auto require = [](bool ok) { if (!ok) throw std::runtime_error("Enemy randomizer check failed"); };
    std::vector<uint8_t> ram(32 * 1024 * 1024);
    auto make = [&](unsigned i, unsigned room, unsigned variant, unsigned hp, unsigned mode = 0) {
        const auto a = 0x74f250u + i * 96;
        for (unsigned b = 0; b < 96; ++b) ram[a + b] = uint8_t(i * 7 + b);
        ram[a] = uint8_t(i); ram[a + 2] = 1; ram[a + 3] = uint8_t(variant);
        ram[a + 0x22] = uint8_t(room); ram[a + 0x26] = uint8_t(mode);
        setHalf(ram.data(), a + 0x1c, uint16_t(hp)); setHalf(ram.data(), a + 0x1e, uint16_t(hp));
    };
    ram[0x4bae8e] = 12;
    make(0,1,9,700); make(1,1,11,850);
    make(2,2,12,600); make(3,2,13,800);
    make(4,1,14,500,1); make(5,1,15,900,1);
    make(6,1,85,750); // Special scripted variant.
    make(7,1,9,700,2); // Unknown lifecycle.
    make(8,1,9,700); ram[0x74f250 + 8 * 96 + 2] = 4; // Other species.
    make(9,1,9,0); // Dead.
    make(10,1,9,700); setHalf(ram.data(),0x74f250 + 10 * 96 + 0x1c,600); // Injured.
    make(11,1,9,700); ram[0x74f250 + 11 * 96] = 99; // Invalid record identity.
    const auto initial = ram;
    bool changed = false;
    for (unsigned seed : {0u,1u,2031u,0xffffffffu}) {
        ram = initial;
        const auto result = reo::mods::shuffleZombieProfiles(ram.data(),seed);
        require(result.count == 6);
        changed |= result.changed > 0;
        auto repeat = initial;
        reo::mods::shuffleZombieProfiles(repeat.data(),seed);
        require(repeat == ram);
        using Tuple = std::tuple<unsigned,unsigned,unsigned,unsigned,unsigned>;
        std::vector<Tuple> before,after;
        for (unsigned i=0; i<result.count; ++i) {
            const auto& a=result.before[i]; const auto& b=result.after[i];
            require(a.address == b.address && a.room == b.room && a.mode == b.mode);
            before.emplace_back(a.room,a.mode,a.variant,a.health,a.maximum);
            after.emplace_back(b.room,b.mode,b.variant,b.health,b.maximum);
            for (unsigned offset : {3u,0x1cu,0x1du,0x1eu,0x1fu}) ram[a.address+offset]=initial[a.address+offset];
        }
        std::sort(before.begin(),before.end()); std::sort(after.begin(),after.end());
        require(before == after && ram == initial); // Includes every excluded record and all trigger/position bytes.
    }
    require(changed && reo::mods::shuffleZombieProfiles(nullptr,0).count == 0);
    ram=initial; ram[0x4bae8e]=0; const auto empty=ram;
    require(reo::mods::shuffleZombieProfiles(ram.data(),2031).count == 0 && ram==empty);
    std::cout << "PASS zombie profiles: deterministic, room/lifecycle conservation, exclusions and full-RAM write boundaries\n";
    using namespace reo::mods;
    const auto pool=parseSpawnPool("1:9:700:0:0:1;2:1:300:0:0:3;0:0:700:0:0:3;22:0:1200:0:0:3","0,9");
    require(pool.count==4 && pool.profiles[3].type==22);
    for(const auto bad : {"", "2:1:0:0:0:3", "64:1:300:0:0:3", "2:1:300:0:0:0", "2:1:300:0:0", "2:1:300:0:0:3;", "2:1:300:0:0:3oops", "2:1:300:0:0:3;2:1:700:0:0:1"}) {
        bool rejected=false; try { parseSpawnPool(bad,"0"); } catch(const std::runtime_error&) { rejected=true; }
        require(rejected);
    }
    for(const auto bad : {"", "256", "0,0", "0,", "-1"}) {
        bool rejected=false; try { parseSpawnPool("2:1:300:0:0:3",bad); } catch(const std::runtime_error&) { rejected=true; }
        require(rejected);
    }
    ram.assign(ram.size(),0);
    const SpawnProfile dog{2,1,0,0,300,3};
    require(enemyProfileCallback(ram.data(),dog)==0);
    setWord(ram.data(),0x387e90+2*8,0x100000);
    setWord(ram.data(),0x387e94+2*8,2);
    setHalf(ram.data(),0x70aa50+2*2,3);
    setWord(ram.data(),0x70ab20+3*4,0x6055e0);
    require(enemyProfileCallback(ram.data(),dog)==0x6055e0);
    setWord(ram.data(),0x387e94+2*8,1);
    require(enemyProfileCallback(ram.data(),dog)==0);
    setWord(ram.data(),0x387e94+2*8,2);
    setHalf(ram.data(),0x70aa50+2*2,32);
    require(enemyProfileCallback(ram.data(),dog)==0);
    const auto actor=0x42eb00u;
    ram[actor]=1;ram[actor+2]=2;ram[actor+3]=1;ram[actor+0xb98]=2;ram[actor+0xc2b]=0;
    setHalf(ram.data(),actor+0xbba,9);setHalf(ram.data(),actor+0x544,600);
    setWord(ram.data(),0x709ac0,2); // Zombies share the room's preloaded model set.
    const auto source=ram;
    std::array<bool,32> available{}; std::fill_n(available.begin(),4,true);
    std::array<bool,4> chosen{};
    for(uint32_t seed=0;seed<64;++seed) {
        ram=source;
        int choice=chooseSpawnProfile(ram.data(),actor,seed,pool,available);
        require(choice>=0 && choice<4 && choice==chooseSpawnProfile(ram.data(),actor,seed,pool,available));
        chosen[choice]=true;
        applySpawnProfile(ram.data(),actor,pool.profiles[choice],0x6055e0);
        require(ram[actor+3]==pool.profiles[choice].type && half(ram.data(),actor+0xbba)==pool.profiles[choice].model);
        for(unsigned o : {3u,0xbbau,0xbbbu,0x544u,0x545u,0x546u,0x547u,0xc2bu,0xb9cu,0x14u,0x15u,0x16u,0x17u})
            ram[actor+o]=source[actor+o];
        require(ram==source); // Entire spawn table, trigger data, position and lifecycle stay intact.
    }
    require(std::all_of(chosen.begin(),chosen.end(),[](bool v){return v;}));
    // Revisit the same spawn in another room/actor slot; resource timing and
    // another actor's construction must not alter its established selection.
    ram=source; available.fill(true);
    SpawnDecisions decisions;
    const int first=decisions.pick(ram.data(),actor,2031,pool,available);
    std::memcpy(ram.data()+actor+0xd90,ram.data()+actor,0xd90);
    setHalf(ram.data(),0x3243dc,19);
    auto none=available;none.fill(false);
    require(decisions.pick(ram.data(),actor+0xd90,2031,pool,none)==first);
    require(chooseSpawnProfile(ram.data(),actor+0xd90,2031,pool,available)==first);
    std::array<int,16> forward{},reverse{};
    SpawnDecisions otherClient;
    for(unsigned id=0;id<16;++id) { ram[actor+0xb98]=uint8_t(id); forward[id]=decisions.pick(ram.data(),actor,2031,pool,available); }
    for(int id=15;id>=0;--id) { ram[actor+0xb98]=uint8_t(id); reverse[id]=otherClient.pick(ram.data(),actor,2031,pool,available); }
    require(forward==reverse);
    require(std::adjacent_find(forward.begin(),forward.end(),std::not_equal_to<int>())!=forward.end());
    decisions.reset();ram[actor+0xb98]=2;
    require(decisions.pick(ram.data(),actor,2031,pool,none)==-1);
    ram=source;ram[actor+0xc2b]=9;require(chooseSpawnProfile(ram.data(),actor,1,pool,available)>=0); // Selected now, applied only after script handoff.
    ram=source;ram[actor+0xb9a]=1;require(chooseSpawnProfile(ram.data(),actor,1,pool,available)>=0);
    ram=source;ram[actor+0xb9a]=2;require(chooseSpawnProfile(ram.data(),actor,1,pool,available)==-1);
    ram=source;ram[actor+3]=2;setHalf(ram.data(),actor+0xbba,1);
    setWord(ram.data(),0x709ac0,0x08400002);
    for(uint32_t seed=0;seed<64;++seed) require(chooseSpawnProfile(ram.data(),actor,seed,pool,available)!=3);
    ram[actor+0xc2b]=9;
    require(chooseSpawnProfile(ram.data(),actor,1,pool,available)==-1); // Only zombie entrance scripts have a supported handoff.
    ram=source;ram[actor+0xc2b]=24;require(chooseSpawnProfile(ram.data(),actor,1,pool,available)==-1);
    ram=source;setHalf(ram.data(),actor+0xbba,85);require(chooseSpawnProfile(ram.data(),actor,1,pool,available)==-1);
    ram=source;available.fill(false);require(chooseSpawnProfile(ram.data(),actor,1,pool,available)==-1);
    require(chooseSpawnProfile(nullptr,actor,1,pool,available)==-1 && !enemyActorAddress(actor+1));
    ram=source;ram[actor+1]=1;ram[actor+8]=5;
    require(!enemyReadyForHandoff(ram.data(),actor,1,9,2)); // Entrance still owns this actor.
    ram[actor+8]=1;require(enemyReadyForHandoff(ram.data(),actor,1,9,2));
    ram[actor+8]=0;ram[actor+1]=0;
    require(!enemyReadyForHandoff(ram.data(),actor,1,9,2));
    require(enemyReadyForHandoff(ram.data(),actor,1,9,2,true)); // Room revisit must not replay the original entrance.
    ram[actor+8]=1;ram[actor+1]=1;
    require(!enemyReadyForHandoff(ram.data(),actor,1,9,3)); // Reused spawn slot.
    setHalf(ram.data(),actor+0x544,0);require(!enemyReadyForHandoff(ram.data(),actor,1,9,2));
    setHalf(ram.data(),actor+0x544,0xffff);require(!enemyReadyForHandoff(ram.data(),actor,1,9,2));
    require(replacementHealth(ram.data(),actor,dog)==0);
    setHalf(ram.data(),actor+0x544,350);setHalf(ram.data(),actor+0x546,700);
    require(replacementHealth(ram.data(),actor,dog)==150);
    setHalf(ram.data(),actor+0x544,1);require(replacementHealth(ram.data(),actor,dog)==1);
    ram[0x4baeb0+2]=0xff;
    for(unsigned i=0;i<6;++i) ram[0x4bec30+i*0xc84+1]=1;
    require(!enemyAnimationAvailable(ram.data(),2));
    ram[0x4bec30+5*0xc84+1]=0;require(enemyAnimationAvailable(ram.data(),2));

    std::cout << "PASS enemy spawn interception: editable pool, multiple species/seeds, protected source states and exact actor-only writes\n";
}
