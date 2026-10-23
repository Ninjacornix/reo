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
    // Combined species mode must only shuffle scripted sources explicitly
    // admitted by its editable pool. Ordinary and unrelated scripts stay intact.
    ram=initial;
    ram[0x74f250+0x2a]=9;ram[0x74f250+96+0x2a]=9;
    ram[0x74f250+2*96+0x2a]=24;
    const auto scriptedSource=ram;
    reo::mods::ZombieShuffleFilter filter;
    filter.behaviors[9]=true;filter.variants[9]=true;filter.variants[11]=true;
    bool scriptedChanged=false;
    for(unsigned seed=0;seed<32;++seed) {
        ram=scriptedSource;
        const auto result=reo::mods::shuffleZombieProfiles(ram.data(),seed,&filter);
        require(result.count==2);scriptedChanged|=result.changed!=0;
        auto replay=scriptedSource;reo::mods::shuffleZombieProfiles(replay.data(),seed,&filter);
        require(replay==ram);
        for(unsigned i=0;i<2;++i) for(unsigned offset : {3u,0x1cu,0x1du,0x1eu,0x1fu})
            ram[0x74f250+i*96+offset]=scriptedSource[0x74f250+i*96+offset];
        require(ram==scriptedSource);
    }
    require(scriptedChanged);
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
    // A scripted entrance becoming mobile does not release later scenario
    // commands. Preserve the original family across seeds and room revisits,
    // even when the source actor subsequently switches to ordinary behavior.
    auto scriptedPool=pool;scriptedPool.sourceBehaviors[24]=true;scriptedPool.sourceBehaviors[33]=true;
    for(unsigned behavior : {9u,24u,33u}) {
        for(uint32_t seed=0;seed<128;++seed) {
            ram=source;ram[actor+0xc2b]=uint8_t(behavior);
            SpawnDecisions scripted;
            int choice=scripted.pick(ram.data(),actor,seed,scriptedPool,available);
            require(choice>=0 && scriptedPool.profiles[choice].type==1);
            ram[actor+0xc2b]=0;setHalf(ram.data(),0x3243dc,19);
            require(scripted.pick(ram.data(),actor,seed,scriptedPool,available)==choice);
        }
    }
    ram=source;ram[actor+0xc2b]=9;
    auto noCompatible=available;noCompatible[0]=false;
    require(chooseSpawnProfile(ram.data(),actor,2031,scriptedPool,noCompatible)==-1);
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

    // Shared seeds must survive different room visits, actor allocation, and
    // first-construction orders once a room needs more than six families.
    const auto planPool=parseSpawnPool("1:9:700:0:0:1;2:1:300:0:0:3;0:0:700:0:0:3;22:0:1200:0:0:3;5:0:50:0:0:3;7:0:600:0:0:3;6:0:150:0:0:3;26:0:1500:0:0:3","0,9");
    ram.assign(ram.size(),0);ram[0x4bae8e]=32;setHalf(ram.data(),0x3243da,1);setWord(ram.data(),0x709ac0,2);
    for(unsigned id=0;id<32;++id) {
        const auto r=0x74f250u+id*96;
        ram[r]=uint8_t(id);ram[r+2]=1;ram[r+3]=9;ram[r+0x22]=uint8_t(id/16+1);
        setHalf(ram.data(),r+0x1c,700);setHalf(ram.data(),r+0x1e,700);
    }
    ram[0x74f250+29*96+0x2a]=9; // Scripted source keeps its native family.
    ram[0x74f250+30*96+0x26]=2; // Unsupported lifecycle stays native.
    setHalf(ram.data(),0x74f250+31*96+0x1c,0); // Dead source stays native.
    const auto scenarioSource=ram;
    std::array<bool,MaxSpawnProfiles> supported{};supported.fill(true);
    bool seedVaries=false;std::array<int,256> previousPlan{};
    for(uint32_t seed:{0u,1u,43u,2031u,534703871u,0xffffffffu}) {
        ram=scenarioSource;SpawnDecisions host,client;
        host.prepare(ram.data(),seed,planPool,supported);
        client.prepare(ram.data(),seed,planPool,supported);
        require(host.profiles==client.profiles && ram==scenarioSource);
        if(seed) seedVaries|=host.profiles!=previousPlan;
        previousPlan=host.profiles;
        require(host.profiles[30]==-1 && host.profiles[31]==-1 && host.profiles[200]==-1);
        require(host.profiles[29]>=0 && planPool.profiles[host.profiles[29]].type==1);
        require(host.scripted[29] && client.scripted[29] && !host.scripted[0]);
        // Live networking can reconstruct a finished entrance with behavior 0.
        // Its original scripted identity must survive that transient actor state.
        ram[actor+0xb98]=29;ram[actor+0xc2b]=0;
        require(host.pick(ram.data(),actor,seed,planPool,supported)>=0 && host.scripted[29]);
        for(unsigned room=1;room<=2;++room) {
            std::array<bool,64> families{};families[1]=true;
            for(unsigned id=(room-1)*16;id<room*16;++id)
                if(host.profiles[id]>=0) families[planPool.profiles[host.profiles[id]].type]=true;
            require(std::count(families.begin(),families.end(),true)<=6);
        }
        std::array<int,32> forward{},reverse{};auto unavailable=supported;unavailable.fill(false);
        for(unsigned n=0;n<32;++n) {
            const auto slot=actor+(n%40)*0xd90;ram[slot+0xb98]=uint8_t(n);
            forward[n]=host.pick(ram.data(),slot,seed,planPool,supported);
        }
        // A client's runtime resource flags and current room cannot reroll its
        // already planned identities, including a late visit to another room.
        setHalf(ram.data(),0x3243dc,99);setWord(ram.data(),0x709ac0,0xffffffff);
        for(int n=31;n>=0;--n) {
            const auto slot=actor+(unsigned(n+7)%40)*0xd90;ram[slot+0xb98]=uint8_t(n);
            reverse[n]=client.pick(ram.data(),slot,seed,planPool,unavailable);
        }
        require(forward==reverse);
        client.reset();require(!client.planned && client.profiles[0]==-2 && !client.scripted[29]);
    }
    require(seedVaries);
    std::cout << "PASS shared enemy plans: same host seed across reversed actor/room orders, six-family limit, scripted/dead exclusions and no planning RAM writes\n";

    std::cout << "PASS enemy spawn interception: editable pool, multiple species/seeds, protected source states and exact actor-only writes\n";
}
