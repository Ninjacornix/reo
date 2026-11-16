// Included by the owned startup fixture. These are the actual File1 ROM
// scenario NPC motion tables; no executable script/asset bytes are replaced.
void scenario_auxiliary_motions(const char* archive_path){
    const auto source=std::make_shared<const reo::assets::Source>(archive_path);
    const w::HumanoidMotionAssets assets(source);
    auto current=w::HumanoidMotionAssets::initial_banks(false);
    const auto alias=w::HumanoidMotionAlias{w::HumanoidMotionFamily::scenario_auxiliary,0};
    const auto cold=current->bank(alias);check(cold&&cold->cleared());
    constexpr std::array<std::uint8_t,20> scenarios{0,1,2,4,6,10,15,16,18,19,24,26,28,32,34,35,37,39,40,41};
    for(const auto scenario:scenarios){
        const auto previous=current;const auto held=previous->bank(alias);
        current=assets.scenario_auxiliary(scenario,*previous);
        const auto bank=current->bank(alias);
        check(current->follows(*previous)&&bank&&bank!=held&&bank->kind()==reo::native::animation::MotionBankKind::sparse);
        check(previous->bank(alias)==held&&current->bank({w::HumanoidMotionFamily::primary,0})==previous->bank({w::HumanoidMotionFamily::primary,0})&&
              current->scripted().other_modes==previous->scripted().other_modes&&current->base_loaded()==previous->base_loaded());
        // The authored table can retain or replace blocks across publications;
        // a live resource exposes a valid encoded clip through the real owner.
        const auto block=std::find_if(bank->slots().begin(),bank->slots().end(),[](const auto& value){return bool(value);});
        if(block!=bank->slots().end())check(bool((*block)->clip()));
    }
    const auto held=current->bank(alias);
    bool missing{};try{(void)assets.scenario_auxiliary(255,*current);}catch(const std::invalid_argument&){missing=true;}
    check(missing&&current->bank(alias)==held&&cold->cleared());
    check(!current->bank({w::HumanoidMotionFamily::scenario_auxiliary,1}));
}
