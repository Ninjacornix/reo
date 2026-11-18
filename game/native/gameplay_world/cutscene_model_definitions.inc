// Exact owned0950-witnessed rows. Reproduce with generate_cutscene_model_admission.py.
struct CutsceneModelDefinition {std::uint8_t type;std::uint16_t variant;LinkedModelDefinition value;};
constexpr std::array<CutsceneModelDefinition,7> cutscene_model_definitions{{
    {0,10,{7,7,1,std::bit_cast<float>(0x3f83d70au),1,0,1,0}},
    {0,14,{11,11,1,std::bit_cast<float>(0x3f83d70au),1,0,1,0}},
    {0,48,{45,45,1,std::bit_cast<float>(0x3f83d70au),1,0,0,0}},
    {0,49,{46,46,1,std::bit_cast<float>(0x3f83d70au),1,0,0,0}},
    {0,50,{47,47,1,std::bit_cast<float>(0x3f83d70au),1,0,0,0}},
    {0,51,{48,48,1,std::bit_cast<float>(0x3f83d70au),1,0,0,0}},
    {0,52,{49,49,1,std::bit_cast<float>(0x3f83d70au),1,0,0,0}},
}};
