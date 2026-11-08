#include "runtime_adapter.h"
#include "render_bridge.h"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <atomic>
#include <array>
#include <bit>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <map>
#include <thread>

extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;
extern bool reoNativeHostMovieReviewedEntry(std::uint32_t,PS2Runtime::RecompiledFunction)noexcept;
#define X(address,name,action) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "entries.inc"
#undef X
namespace reo::native::host_movie_binding {
namespace {
constexpr std::uint32_t ram_bytes=0x2000000,game_context=0x340a40,configuration=game_context+4,vtable=0x22dce8;
using Function=PS2Runtime::RecompiledFunction;
enum class Action {size,create,destroy,frame,release,filename,unsupported,stop,pause,start_afs,status,time,information,start,loop,unlink,enqueue_afs,repeat_afs};
template<class T>T load(const std::uint8_t* ram,std::uint32_t at){T value;std::memcpy(&value,ram+at,sizeof(value));return value;}
template<class T>void store(std::uint8_t* ram,std::uint32_t at,T value){std::memcpy(ram+at,&value,sizeof(value));}
bool extent(std::uint32_t at,std::uint64_t bytes){return at>=0x10000&&at<=ram_bytes&&bytes<=ram_bytes-at;}
std::string lower(std::string value){for(auto& c:value){if(c=='\\')c='/';else if(c>='A'&&c<='Z')c=char(c-'A'+'a');}return value;}
struct Cue {const char* container;std::uint32_t sector,sectors;const char* key;std::uint32_t frames;};
// BEGIN GENERATED NATIVE MOVIE CUES
constexpr Cue file1_cues[]{
    {"netbio01.dat",346959,146,"f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb",195},
    {"netbio01.dat",347105,3798,"8f3d870f720b590c963c98bd318ef83b743d1fa88288bc4ac57269f9cafaed47",521},
    {"netbio01.dat",350903,7535,"aa6ed7c77501568962042f54a784bc27aa42b119a48354db91c28faa332f1bf5",1058},
    {"netbio01.dat",358438,20454,"bff5fbb856270ef677b301676bf6e24755a01b678e6f88ee630ec38e25035a03",2763},
    {"netbio01.dat",378892,83078,"1321de8119604a6d96e68ec0689199ecf479d107dde49e90ad9dc4dae1611b9a",12432},
    {"netbio01.dat",461970,45198,"fe761807bc7493769dd7f9720ce6d1cc969f596f76fefc9b5add5385952b153b",6144},
    {"netbio01.dat",507168,875,"674374fc20aecc83c4c4640397ae33328523694e7b5d7ab81bd8f1ef3321ff83",300},
    {"netbio01.dat",508043,5490,"272707770b899fdd8e64bd8a5ba1567a0af22f9920e552530bc9fc26e9824613",600},
    {"netbio01.dat",513533,1520,"eaa7109ba59540f4f973dde7a0ee1ab874be77f8e8c7c280b0ab88bcc9f8601a",316},
    {"netbio01.dat",515053,2249,"6bf289ab52438f810e921aad89fa3b3f4f6b792d18deb003daafadcfccaea230",300},
    {"netbio01.dat",517302,1528,"bae6e9dec3d50ae13adc7bada27283fe7fe361e185495e06b7b27ac68579c26d",300},
    {"netbio01.dat",651894,77,"17c2d9b4e916bd3a7d0b679888401487e4867d02ae99cb46de1cba3521a729ba",30},
    {"netbio01.dat",651971,100,"5cc8d98da2e8ecf5046949977c413471c96bfaf546e1a5fab12ba7f22f047050",30},
    {"netbio01.dat",652071,74,"0375f999b4a75d50f79a846b3281036eef91db3f300aded0bbe6966dcd5d3371",30},
    {"netbio01.dat",652145,73,"c907ce1bd3c914a777cce8b822768a4a44804e78be1682d37ef9bf399c517968",30},
    {"netbio01.dat",652218,99,"826ac622f7912f89a10a6c99183b8b3fad50f141d3b9562c5b76be35c8021a91",30},
    {"netbio01.dat",652317,961,"f0c6de03196faa7d9cd7ed07dec24ce5b15bc644cd142b79804b09db83a7f4a8",300},
    {"netbio02.dat",2,2238,"51eed9d7c97f1591a5d0a07ce8e41357f898248461075caa1a7ec8ad3b9c385d",293},
    {"netbio02.dat",2240,2615,"f6bd2f879f50238e5b7a437a75de2584019ddfbbe63325435c468994f362a288",451},
    {"netbio02.dat",4855,739,"a1671d6593782af5afd7204400c030571a12ab64a0b5a7331bd2c448363902a3",90},
    {"netbio02.dat",5594,2322,"3f789f5d34e2649a40c10e2b5a364b98ffb7033edfbf7dbef770a22334e11bc9",299},
    {"netbio02.dat",7916,2019,"d5894ac24011d02ef4c8633dc00511800d1176fc4c8330e1bdb3062b3a31fa84",294},
    {"netbio02.dat",9935,1918,"57828a8280513630f1f359258d7f022cda4e82fb2cce98373174f70b17a6b1fe",299},
    {"netbio02.dat",11853,2111,"75b71af1d35f204538dc850902d1d3e93d777f5dd3b40565545ba636c7ba76f2",299},
    {"netbio02.dat",13964,2268,"7b5982c7890b96ee97307f0633168c2b54c1664e0ad22dd8eae307131dba478c",299},
    {"netbio02.dat",16232,1613,"21742cf8bd0db73ee17cdecc32a1bd5560ecb2b5059b91ef14d1b65e333f71a8",297},
    {"netbio02.dat",17845,2290,"54572c42d6cfd11dc738fb3b3c2949b2fe324ea5ba5cfe34b98362aac621f0ac",299},
    {"netbio02.dat",20135,2146,"286ede53445c1c316f8e204268da1006ed200a2da0e474a45a9db5706c3bd440",299},
    {"netbio02.dat",22281,4966,"b70e35c56db06f024dfbd46254488d5fd682f7702f44bda692103c29a6027e85",1224},
    {"netbio02.dat",27247,2878,"d32a644fd878af5416275681ae80423519eb0ec21f5129f18bafbdcf5f9e141c",711},
    {"netbio02.dat",30125,386,"31ece1f93b76e7e8825d1800ffe30103b11cf3cb295eb967ac3136c874c0e68f",90},
    {"netbio02.dat",30511,1393,"bb975f6cfb1035516268ed8c1c334e4c01c6dc6a2d5c6bd25b2043fcefc65bb0",277},
    {"netbio02.dat",31904,257,"ac706dcd3cae9f44a734d1757c9841edfbb1aaf7e6267e302fef89dc0ff264c0",41},
    {"netbio02.dat",32161,185,"333096ece809787fd837c0196f439e208e7059ce7809e18cdfe1d96ca9246bcc",64},
    {"netbio02.dat",32346,417,"63f28452fe3fe150785cc5bd53e28fb317e9c24b028c158107b5b9c8be54b027",83},
    {"netbio02.dat",32763,268,"abbc183ce17e76f0356be7dbfad1e0628be90dc46a8fc153aaf46fcb37b6a202",60},
    {"netbio02.dat",33031,232,"761e5779663ad4b3a06e2f26fcdd0faa7649ee158096c6a81208494067dad6f7",63},
    {"netbio02.dat",33263,313,"0fc66bcec8bcb819bc5e1fbba04d78b598777a82786472f0c8287fdb2d227a59",56},
    {"netbio02.dat",33576,1034,"63a5cbe4c9dd74e41ce98238c113597671734a12f3c0541dc4d6c915c713445b",230},
    {"netbio02.dat",34610,312,"48b9f3bec8fb7686fdea84117cb8aa70c56757af2017353befdd204d7990ebae",52},
    {"netbio02.dat",34922,3707,"a7d099727d96677c043ad8dc4ecae8b8d03ae7f0ef589e00ddaf1135d6f9912b",1038},
    {"netbio02.dat",38629,785,"8527e08e3328995b69a4e9829dc5765409695d16b6b01339952e29d3f2e02541",201},
    {"netbio02.dat",39414,1785,"81d8e0c6d2ceae52493f18ab6267c258717c5864f9685e4c184c7cd4c5797610",540},
    {"netbio02.dat",41199,511,"d22b2b9d6747d4a4db9c91d034b014beb3eec1acb9ead281448888f76790e429",168},
    {"netbio02.dat",41710,4024,"017f586668780c62f8bf7e4ca782e6a87a0bab091d6199afabcc74863ea4eaff",905},
    {"netbio02.dat",45734,4197,"b08727cea120c278e9f40f2d5fc06b754ffd9e80dcb746f48aedbac24b6a9db7",905},
    {"netbio02.dat",49931,1287,"a3037ea27e27d20b9317419ecf91cbdc9da3788e4372d620d9536989053a9cc1",240},
    {"netbio02.dat",51218,3161,"6dc21690289e1615d4e4a7dc6cdcedb269fe591fd049a11d9776cb550d423d81",510},
    {"netbio02.dat",54379,3541,"3f50cd5183beccb0fc3ae6b5d838b5d2b261ae6eae5fd4d32eb5c504f251fbce",570},
    {"netbio02.dat",57920,2206,"3ca39d8a3e8c27b5a4f926d28170ff2bb8ca03153a4f38a644a84389c8452e1e",360},
    {"netbio02.dat",60126,1331,"47e0d407c8c1a9b5ece7282cc8ffe8b363641563bbaf853f6afe36dc719d778c",519},
    {"netbio02.dat",61457,2320,"6a8c48e4eb7c2ea0e6ecacb04e0453208b27405d73cd553fd6369e775e43f08b",420},
    {"netbio02.dat",63777,6349,"fe77b82d76d9db8216742f1e9d4c4f2a1ec2d11a3b153bca070ed3fd5daa4583",1134},
    {"netbio02.dat",70126,4546,"22d4268c636cb2d5a0dab9ff31e9ff7b29b103211c6dc1d9f5bc57f18c4850d5",741},
    {"netbio02.dat",74672,1305,"a06cd28eb3100fd9bd729d8bf373a9921446e741338c6ee2bf592ba81632f9de",255},
    {"netbio02.dat",75977,371,"75f2d835bb345c66520995d5ef58b42d444d1840ce2cbc121c238a0962fd2916",105},
    {"netbio02.dat",76348,390,"f9f168390cbce493f9dd0a5d675a897b2b537d64429f1e29823e157586847f76",105},
    {"netbio02.dat",76738,1234,"c5282459ab7b4ea75ac45e1c2c7a13633a1489838cf6d42e87873402d6d1c166",349},
    {"netbio02.dat",77972,10677,"db9b12a6fcc7c069371e0a25764877b1063a388df5ae14ca8eeb46577856a646",2320},
    {"netbio02.dat",88649,10193,"97d5a803eef96fa42c09208727b32bd5990c2fd3d3f432ff722d30a5cfdae715",2269},
    {"netbio02.dat",98842,10952,"a44107d073a79d23805ee9a59bd2671e38d1a69e774847368e4e975b2c1d3fa9",2395},
    {"netbio02.dat",109794,10180,"f82ef257df55f487f000573b8d0dcea93767e1a1193653ae63318f7ae2b4eb9d",2216},
    {"netbio02.dat",119974,10885,"53b7dd5c86e7da1b6a40daee4d1fd3bed2e6ded78aba0a72abc4591dc49aad6e",2453},
    {"netbio02.dat",130859,10674,"4ffa317d83454cfc1c1ffedf8f194ecff1bac9fafac8615f7333ce5f5c235ad9",2347},
    {"netbio02.dat",141533,10453,"9a843de93687775146ec0ef873778b90ecfe82184c0a2dd9597aae5ce4927077",2312},
    {"netbio02.dat",151986,10364,"a5fd107f3368c45496431bc004d28b6222dfb4f34c82631e6bac8b6bc9ce3d07",2304},
    {"netbio02.dat",162350,3048,"c2e0be0bcd3f105f33c20ae48036a09728959724ef8cd05a5efc863eb9085912",909},
    {"netbio02.dat",165398,2616,"12fe520570aee1d9e33e42a5b65a6be397382a33b2f8076a64aed4bb6318b93d",859},
    {"netbio02.dat",168014,3139,"ddb9f82dc3d6cb2feeee233d92de4397cf8910f13bd10c3cbd4213ba29aa8e9c",934},
    {"netbio02.dat",171153,2648,"f0dae9cff4d258d281119acd987856baa94d78d423e6707aa51bf048d802f540",834},
    {"netbio02.dat",173801,2809,"65dcfebc393028b724a10a1f15d100e10cc778a9f941faadadb6cd82ed5e524b",909},
    {"netbio02.dat",176610,2732,"9b02133d139671f670c047f8e8b94f74832fa4f7c3cd57c8216a95ab20f88a97",858},
    {"netbio02.dat",179342,2453,"84b8b6a2b3f2782e64d90ceada56bdf4db7e1792ac181ad49faca365f50e8d47",822},
    {"netbio02.dat",181795,2474,"bf4f93bd7c5c0a0beaa42a9bae87aece66d707767f96fc11bf47ed4690f7e604",834},
    {"netbio02.dat",184269,15218,"f5d0b6f2808b4f54e00fc6bcd688793534b988cf15ffb8bcff1c8dc0b86a3712",3061},
    {"netbio02.dat",199487,14735,"7c3194148f9b634e5157258f37860bd551a520430f2d84e85a75be626a6b8c8e",3010},
    {"netbio02.dat",214222,15493,"21155dc478c115e872b16fd1000868753fd7ff15cb0ef69f0a42f2ed61463f31",3136},
    {"netbio02.dat",229715,14722,"bef0962da52c944d9a57b5ea1fa96f804be0fea06b8e1a3d9498981c5cea2ade",2957},
    {"netbio02.dat",244437,15427,"e4f53a8cf44cf3e887f086a4aa41601a1c3ae9a7e657aeeb97f13ffc7f6d9036",3194},
    {"netbio02.dat",259864,15216,"15620bddbb4908874709335aaa21213f99c5803154b6b941a3f94daa8e0abf86",3088},
    {"netbio02.dat",275080,14995,"3a06a1070dab329301643c71b0de5c6ef9f67642f7d529f8a2731c9910c754ba",3053},
    {"netbio02.dat",290075,14905,"d3df4aa4aa2e739d5cfe912a2c1fb284b432e6ff368a3bc7e1f8e42a012593d9",3045},
    {"netbio02.dat",304983,8042,"cc9bc350d642ef83bff7d1d2ec4321c1995b12c75328507e91ac5423eb2e0dc2",1394},
    {"netbio02.dat",313025,1870,"ca794d301f35466e89097df77c6f97f2721e1a2b68ea281287b025c3846f2ff8",420},
    {"netbio02.dat",314895,2479,"dcddf0ca717d92b0b619d41e075c325d62570387d0285e99ff45fbc172f2ace0",459},
    {"netbio02.dat",317374,4561,"2501dc954c9f3f2ada5620ee59ecbb8f7bb1e8c5d4717fb1e3087172d77142b1",811},
    {"netbio02.dat",321935,4388,"e1f8d51fbe60cc74796884b54d7b454ffa9639729282743e0e07021b558cac22",811},
    {"netbio02.dat",326323,4439,"0fded2da7668205e26fe105bb0375c90af02f31d1e68708237916f16caa2f367",811},
    {"netbio02.dat",330762,4411,"f73cbdb09b11f1f46d9873458b0d8cfab1d2e4a4af2e593e0b8745dc607a546e",811},
    {"netbio02.dat",335173,4481,"f92f4e9837bc92310db11bb5c47e6c86c9835481171368c1093082748ffeafcc",811},
    {"netbio02.dat",339654,4404,"055093d8420b512e16f0fa23abac5706794f0d41e08b141d1dff8a8aa1d1b58f",811},
    {"netbio02.dat",344058,4417,"f2eb4359015da46d9e95c96edf7d765e6c887f003f24e5c9768bc1f35181ef1c",811},
    {"netbio02.dat",348475,4450,"2fe7a97171b45de76558ec147b6e73a647a1ed1e8a378e1cf23fdeb719a2e2a5",811},
    {"netbio02.dat",352925,777,"0a43320fcac2bad66c5aa20827e57ebab476be76bc6b42586bbc05e511d763af",181},
    {"netbio02.dat",353702,4850,"8e52d4440ebb50814fe61b1593c6bbb6641108e5898c6b5e32d912d1e3d89864",960},
    {"netbio02.dat",358552,4842,"3b6bd85b8af66dc9c2d314a062a6ec87808f6dbdd81d51ca93d88e82204029c2",914},
    {"netbio02.dat",363396,2007,"08be59a2ec95784b54aa14df9b499673a9e16e36a013870c7f5c9ed919d28ecf",390},
    {"netbio02.dat",365403,7020,"d2f1ecafd0fb1a298207c4a63e3bf7517d4270c8e5905f4e1ec79fc9b7600d99",1690},
    {"netbio02.dat",372423,2623,"6710a1bdd7754e38c29a79604350b42066550d4f0592949f04cb8e092c3f872f",460},
    {"netbio02.dat",375046,4769,"93be9707fcc5f33afa0f0f60604f874045eae6db95f079bf7c6059bf474a776a",1000},
    {"netbio02.dat",379815,3362,"8ad7f2bdd7c1aaa638ab6ae63b69fd4cd11d413c87f1adca516c2ef6dfc5c5b2",638},
    {"netbio02.dat",383177,3301,"3e826decad403165fc9df749d81282082ba818aeb69507bda78b2dbd99fc51fb",638},
    {"netbio02.dat",386478,3302,"edc4bf44fbddc7ad6d0ea5329ce4df28b2e8d78134b4f1b366323e2feb80a308",638},
    {"netbio02.dat",389780,3271,"bcd83dfd0597aba1b264ab118919999a385f27e1e5b1b933e655c3f6bdf89baa",638},
    {"netbio02.dat",393051,3384,"2497a334b8fef50a86b54befae7384a459a2e1b3dcf362622028c4973b52080f",638},
    {"netbio02.dat",396435,3299,"4bace546246a40b2a52d35c6fc7029f9d1f8b77910f76309f6f31f9ce7b52e6c",638},
    {"netbio02.dat",399734,3353,"7f7e7ebea5a090d507005d9dbe2290b647bf99144bf750c75207a8677c7b2493",638},
    {"netbio02.dat",403087,3401,"5b1443aebe2bf7c32e0b0ad0a704fe5ee90599c02a4bf37dbafa21ba35f74dfd",638},
    {"netbio02.dat",406488,1349,"6ca1f3dcfeb46b924f6141b7133708cdc59b9297c21ad2e15a0ee2750e21708c",316},
    {"netbio02.dat",407837,1249,"54705eab38dd103b436c27c3328e091f88bab35ed2d746f0d42b28692520165b",316},
    {"netbio02.dat",409086,1340,"f8203117ad72ff6f4661a5d241e5670f6a5d1b5beb967202ed4d8348fd984c42",316},
    {"netbio02.dat",410426,1252,"42544388d118a3eead5ed683b4aec8da2d8930840ee0728d19107db612bd0533",316},
    {"netbio02.dat",411678,1389,"7623c42fa0a5b12f7a955ebcc8467f50c2bb35813319ae86a50eefbbeed99e79",316},
    {"netbio02.dat",413067,1303,"bcc4b5a98a6209489d87ba6353c3c7cab7a472e78cc24db26406c2856ddcc96b",316},
    {"netbio02.dat",414370,1271,"6fcc621e89e5cc35d2f2cda39f6f25563800d6c494e092599c1bacab2c2fc9db",316},
    {"netbio02.dat",415641,1399,"6c21559106475a92c8e6b6f2d789885025bef5e33b13a9c6c726f16ad168f0d6",316},
    {"netbio02.dat",417042,3175,"a34bd3c6193fc386b685060a77fe75e51906cfb03c666a0fae1ec2f710cf31a9",717},
    {"netbio02.dat",420217,4721,"a12b0b9ff99e262b05bdfc8d85c87457d7009808df2ee8614014de520371dbab",930},
    {"netbio02.dat",424938,706,"e20cf9be5a1253f41e748d8050f00fc48e7fe45b725ea96327d63b2ebf0a885b",181},
    {"netbio02.dat",425644,11213,"6835b0d41c11a928f0a442b762fa687b25fb5f6315180af3c20e99ea1c02bfd5",2096},
    {"netbio02.dat",436857,755,"51c2c6c60c026001a3cade3ace765ca0db110f0bccda4aa10249d019ea860765",180},
    {"netbio02.dat",437612,750,"7682bc3a8908dd2f6725154b2b51ef7b1cd4b5625cad5f68e386888f9ba33212",179},
    {"netbio02.dat",438362,4542,"a68b11f0cb27dec71638aeabc7710fb9b19228143ebb32b4fe3384561352d593",951},
    {"netbio02.dat",442904,3125,"30ee2de84dcef8750dfc97939ca4d80361bde2871821845994d35846d287508c",500},
    {"netbio02.dat",446029,1665,"3d55f29d5db69833470276388683cf3b157cecdb17b53f2345d464f111b30031",450},
    {"netbio02.dat",447694,6283,"0cdde15e7ffde86de7eaab13264b3c082ad4a8f5051ab0ff7f82e55189347b28",1224},
    {"netbio02.dat",453977,1072,"6acc1f2b771d115a6b5d0d4cb39eee8e8ed52f6ffaaa311a1b8a1ac3d8f637b1",180},
    {"netbio02.dat",455049,5536,"a3f102db4641bb64a7a2943ad9d4cc1cd35db09449ae6541f2cdf42fdaae86fa",964},
    {"netbio02.dat",460585,2063,"36a295f86117824460848a98fc39fd2c76d432fb501a211a5c67e14d220c3ee9",411},
    {"netbio02.dat",462648,2035,"1a1da87ded61c0dd834000d58fdc24d3ac082e0f0850575bc8616628ae069d8a",450},
    {"netbio02.dat",464685,6065,"1d7ae21b7c6a9459fb0c8a20c44763681707fc0452b2716e667f8e26136df534",1256},
    {"netbio02.dat",470750,9406,"3ddca5a6f6ee2a5e713c1035afd6f1a32adf4d3f46d48eca605800ea9debc6b5",1791},
    {"netbio02.dat",480156,381,"8717439c7ae27f96d66127bf46a8ca3d33c774af30699b910446658657f5de9c",151},
    {"netbio02.dat",480537,2621,"8517555c448ac06a1d61996ec739c527d0e92f1da3c24c90298872a876cb22ec",580},
    {"netbio02.dat",483158,493,"3a42a8f138a5996d6b37a6d648c92e8875aaaf1e6326a6c616850c1e6d554ccf",151},
    {"netbio02.dat",483651,497,"5c304e323fbc8ca57b44ad062e6fd95f528338447afce09d232e3063a4eaec61",151},
    {"netbio02.dat",484148,2228,"375a4394aa63350f9fedcdac7ad6009a8ed23f4fb3b7a40298dff397fb9e4c9c",611},
    {"netbio02.dat",486376,758,"c8980b49a5bae153ae0f7f982c64f4486bfa689bba314bdabd8dbe2262f194d2",180},
    {"netbio02.dat",487134,1121,"be420b4603f0524bc2b6ae02d6dfe755b02fd580bc01555ea6031ec33422ecbf",239},
    {"netbio02.dat",488255,7282,"3deae30cf2448391ffd6bfaa20e611f994fc90526120c736bd3685445b3efd41",1324},
    {"netbio02.dat",495537,1199,"70002f5af08c8fc3817363dd6b3a2c59538b90fad2068238e42aa44fd3e6e927",279},
    {"netbio02.dat",496736,1845,"c91b1c818e8592c7d4dd48bd9dbc7926fa619fb6cdcfcd1662c335074286f266",366},
    {"netbio02.dat",498581,477,"df2b4daa59b9b5b21a059b321deeac477845d6af33dd02f7226234a2eb07f736",151},
    {"netbio02.dat",499058,4323,"499fb2eda8fe2f6a2e3fc91fdc50bad36cf2c7c818d7fa4812ba538738a19c2f",748},
    {"netbio02.dat",503381,2203,"fd349881459ebef4fb73ee1ae42d31fca623fd25ada6573ccb3194b7ae0b6221",601},
    {"netbio02.dat",505584,2097,"80fa77d37cda55aa416510f826190c1a4ed8ee34c734058d6e44542b088f5861",601},
    {"netbio02.dat",507681,2165,"99cef8b0ea9d4d406fdb9ad07cff68d708aa7600bbac89d6ef3d1d28682ec9e1",601},
    {"netbio02.dat",509846,2117,"397aa4a6ed7ae55c548f7ec21e9e488fff0d35839c97a26a7e7d4c2a1a362c2e",601},
    {"netbio02.dat",511963,2173,"a0d217e68c17ec46bda23111d9283b19fef48f7af31ddc8f34a19d14ecb13c28",601},
    {"netbio02.dat",514136,2141,"54ca8d458eb1eac933a076c5083c9b08e8686d1cc7a28cf37e64898a448d96d3",601},
    {"netbio02.dat",516277,2100,"84700d69b815e8a0c061773100ca1a673c3351216957c390c882756c5aeff001",601},
    {"netbio02.dat",518377,2188,"7a14b620d3229013fdeb2ef2d4f4bfe6d742daa626c49d4d6f16554282aebac7",601},
    {"netbio02.dat",520565,2518,"d9904f10ce062f06b5b3b421b775e8dcb37a2d6b21a4a23218c07d34a679225e",551},
    {"netbio02.dat",523083,1819,"cad5255084ea6dcc104f87cdfd9dd53be9739dc537a6cdced79c27c736f9d525",551},
    {"netbio02.dat",524902,2494,"735f0a986a68c22cfc04216dfacf696cf91d1c8c013e4fd2a92e7bc8696ebaba",503},
    {"netbio02.dat",527396,2665,"b6ba7daa233c8ce7035cb84af9930b92a90b9e41ec06449f2ac088d1d905d525",550},
    {"netbio02.dat",530061,535,"ee89b5be19d0fd29faaa2526ff3a3c2d52d07c909e1bdd2a142ad38e1e389a86",151},
    {"netbio02.dat",530596,523,"4e1a2944ef7feff8b8f7bfa2d3a29c6b1fe141e83f38954eb459453aec84cbc9",151},
    {"netbio02.dat",531119,532,"5660c9e910518f4e5a031607f85e4cc6ee4c53a74573706c64b2a9c5b1ff5715",151},
    {"netbio02.dat",531651,504,"64ffb8a02a97c83ec04787d75057cbc5129ae14f5d66fe39aebfd03333210794",151},
    {"netbio02.dat",532155,470,"a2b43e058f6c31abe210c209fa13a84ddaea152c3d4fbc2aa4efc4de4124f429",151},
    {"netbio02.dat",532625,440,"d95bdff9014ac2b314545b1ebd148b582b70578e3af00fbeab2dd5534aa03f4b",152},
    {"netbio02.dat",533065,460,"0438a08e661ed19fd96b156a21dc10cbba296d0457960880a9baa8ce51a79762",151},
    {"netbio02.dat",533525,470,"9de4865a4a234fd6e1e2e3242eccb50c57ce3d9898a30a55e16b69c1d28b71f2",151},
    {"netbio02.dat",533995,457,"c3343b98edc676c05809a4c3c429115b61a53a8e203149164538f867114a4781",151},
    {"netbio02.dat",534452,443,"300b52555c8b28e979fee8c1d4fb26bb33ad6ac13191c94beed7d73015cd1a42",151},
    {"netbio02.dat",534895,461,"c37f2248a55023e164c500545c229729e6378e89a9cd384952cbb4f4d8603ab3",151},
    {"netbio02.dat",535356,3227,"2ec34a1cacf4b3d046a42b8e652bec3d7e9badf8dabafc67cf352194ee326dd7",833},
    {"netbio02.dat",538583,3050,"4d83dc0f586ea0fa0d312be19b7d57065e6d8200a3c70ec4fdd99122fe195267",833},
    {"netbio02.dat",541633,3225,"b7aa6f0d37c6a7ad89223a863a0c452bdc1c8304279597b4fb5d7507ff2f6c12",833},
    {"netbio02.dat",544858,3083,"657498960f445d5ff1f2a41bbdf1ffafa77699f369b3cc487eb32d6871eeaa41",833},
    {"netbio02.dat",547941,3222,"0b04ca614e3e3aea840320afcb21d3065c63f34d19350d61532f1c949a77a409",833},
    {"netbio02.dat",551163,3144,"f1bd129319660d98c8569a08a4a04abf3584d80923bc41869dfa7642d9c9d61e",833},
    {"netbio02.dat",554307,3151,"536b871db4c2f04c6e9bfc91b4bdf1adbb054365544e15d4d94836d58a262c4a",833},
    {"netbio02.dat",557458,3206,"aa905d877365a7a03b6147a1ae3f55905a0a6be902e077ebca04f53157e8bbd0",833},
    {"netbio02.dat",560664,5114,"fbd5527ce5df0a3536ff8fdb25878913e42fcc97213e51572cde2e77ce9e12fd",880},
    {"netbio02.dat",565778,11003,"9d683a07ce149f00fdc364c65e304a48de420a3e808be6e3140fb8bef7db730c",1986},
    {"netbio02.dat",576781,17274,"07043d15d2a47d6bffd1389cf132013894daad5063318134c520cf1c340b6df3",3308},
    {"netbio02.dat",594055,14771,"48d5488cc9cb4d95ea6689f13c27a1aaa5389835e4815a27feda8e29adedd86c",2985},
    {"netbio02.dat",608826,16801,"14fc6d9ea0eae33502b929c60a82d8f6f97c97dd9fab947d32421b6d35d7d634",3037},
    {"netbio02.dat",625627,16203,"4efd3469c7234f0a76bcdeef154cdf293337f67fdb3ed05059603e177d333317",3107},
    {"netbio02.dat",641830,16796,"7e8ebcebbdff79685e29d7dc44084977df8321bde51847a2dca9b44d69979d6c",3176},
    {"netbio02.dat",658626,14758,"1dec74601b6a16a419bfb74a5439914b8246730cdcaae8353c9ca3ebfbed7be5",2902},
    {"netbio02.dat",673384,15403,"e3d753d9ce87cf3e1c11d1810c362ae2c2de33bf0d3578bac320c6e06453808f",3026},
    {"netbio02.dat",688787,15836,"e47cf3a9538fb6a2d9bd58c532240baae60d80420c90e5efe1a303c024d3e611",2912},
    {"netbio02.dat",704623,9456,"6356f7c59ee18b1c616bfa4301ffaf2c14ced1cabf796fb3c2c35a950c740c0b",1833},
    {"netbio02.dat",714079,9316,"124f8425aa01e76bebf22863633a538d58d90361bbfb3fb3ff5c27eb79891fd0",1835},
    {"netbio02.dat",723395,9395,"03df262c639a13cdcf7eeb6f85e6bed22e4af85f020c7db9d529814b8140f3d1",1834},
    {"netbio02.dat",732790,9322,"ae96d17a98f671ef31e1bedbcd568603c70e604e2d1a97a37ebaf7f9ae234ed8",1834},
    {"netbio02.dat",742112,9413,"9039346c452dcbea2215f787ce2fea62884235349bd9b8391883babe20db482f",1834},
    {"netbio02.dat",751525,9363,"8cc105d680d84a9f4f18fceb4dc444a76cd7af1dc39bb2edb3a7c0557bc803af",1834},
    {"netbio02.dat",760888,9343,"4f881a1be784cc8a87db68b39d4b861bc7be12b358caec036ced3d557f813e74",1833},
    {"netbio02.dat",770231,9435,"a10e0412a717d6ade4db51276d5aca46e104ec109bbe4162032065c1bae1621a",1834},
    {"netbio02.dat",779666,16881,"26eda536a6a17a0d27e2167626b8fe13e3719fc17c9a532815fe779d93c3ab7c",3140},
    {"netbio02.dat",796547,15839,"6e73825738030c743ea92baff666663590585c2d5288383ef9e285ff089c6dfd",3182},
    {"netbio02.dat",812386,20263,"fa03740b74b9059826a4124783ed9e4156bf0a4367890f1f8cdabc1cf6fc2618",3715},
    {"netbio02.dat",832649,15747,"998672b5e29756d3379cd89e186b026220a94e0fe49b64ce2efef85f1ccf9300",3114},
    {"netbio02.dat",848396,3665,"6be52a18efd260c7343a0e2bc249acadb7ba2351c6a976ff230b56c7138e41d7",1199},
    {"netbio02.dat",852061,16159,"d1ad4800dc9f20d708120534bfb51815a3023d7cf18a18a88e0ac4b4b3dfb2a1",2761},
    {"netbio02.dat",868220,3665,"6be52a18efd260c7343a0e2bc249acadb7ba2351c6a976ff230b56c7138e41d7",1199},
    {"netbio02.dat",871885,56780,"4b68962d85c95e4aa8b9d48082ae8b72baed83d523dc2d2176a0ff519ffad07a",11297},
};
// END GENERATED NATIVE MOVIE CUES
class Binding final:public PS2Runtime::ExternalWorker {
public:
    PS2Runtime* const runtime;std::uint8_t* const ram;
    std::shared_ptr<const movie_assets::Catalogue> catalogue;
    host_movie::Session session;
    std::map<std::uint32_t,Function> originals;
    std::atomic<bool> active{},closing{};
    std::uint32_t proxy{},pixels{},width{},height{};
    bool alive{},repeat{},started{};
    host_movie::Generation generation{};
    std::uint64_t released{},sources{},frames{};
    std::vector<std::shared_ptr<const movie_assets::Asset>> playlist;
    std::shared_ptr<const host_movie::CpuFrame> held;
    Binding(PS2Runtime& r,std::uint8_t* bytes,std::shared_ptr<const movie_assets::Catalogue> assets):runtime(&r),ram(bytes),catalogue(std::move(assets)){}
    void requestStop()noexcept override{closing.store(true);session.request_stop();}
    bool join()noexcept override{requestStop();session.join();const auto s=session.snapshot();std::fprintf(stderr,"[NATIVE-HOST-MOVIE-REPORT] joined=%u sources=%llu delivered_frames=%llu error=%s\n",unsigned(s.joined),static_cast<unsigned long long>(sources),static_cast<unsigned long long>(frames),s.error.empty()?"none":s.error.c_str());return s.joined;}
    [[noreturn]]void fail(const char* reason,std::uint32_t address=0){std::fprintf(stderr,"[NATIVE-HOST-MOVIE-REFUSAL] boundary=%s address=%08x\n",reason,address);runtime->requestStop();throw std::runtime_error("Native movie game boundary refused");}
    void require(bool condition,const char* reason,std::uint32_t at=0){if(!condition)fail(reason,at);}
    std::string string(std::uint32_t at){require(extent(at,256),"string-range",at);std::string out;for(unsigned i=0;i<256;++i){const auto c=ram[at+i];if(!c)return out;require(c>=32&&c<127,"string-profile",at);out+=char(c);}fail("string-length",at);}
    void output(std::uint32_t at,std::size_t bytes){require(at%4==0&&extent(at,bytes),"output-range",at);require(at+bytes<=proxy||at>=pixels+std::uint64_t(width)*height*4,"output-proxy-alias",at);}
    void validate(){require(alive&&extent(proxy,8)&&load<std::uint32_t>(ram,proxy)==vtable&&load<std::uint32_t>(ram,proxy+4)==1&&load<std::uint32_t>(ram,game_context)==proxy,"proxy-lifetime",proxy);}
    std::uint32_t required(std::uint32_t config){require(config==configuration&&extent(config,48),"game-config",config);const auto w=load<std::uint32_t>(ram,config+8),h=load<std::uint32_t>(ram,config+12);require(w&&h&&w<=1024&&h<=1024&&w%16==0&&h%16==0,"game-dimensions",config);return w*h*4+64;}
    void create(std::uint32_t config,R5900Context& ctx){require(!alive,"duplicate-create");const auto bytes=required(config);const auto base=load<std::uint32_t>(ram,config+0x18),capacity=load<std::uint32_t>(ram,config+0x1c);
        require(base%64==0&&extent(base,capacity)&&capacity>=bytes,"game-arena",base);const auto work=load<std::uint32_t>(ram,0x56bae8);require(extent(work,40)&&load<std::uint32_t>(ram,work)==base,"game-arena-owner",base);
        proxy=base;pixels=base+64;width=load<std::uint32_t>(ram,config+8);height=load<std::uint32_t>(ram,config+12);alive=true;repeat=started=false;generation=released=0;playlist.clear();held.reset();
        std::memset(ram+proxy,0,64);store(ram,proxy,vtable);store(ram,proxy+4,1u);SET_GPR_U32((&ctx),2,proxy);
        std::fprintf(stderr,"[NATIVE-HOST-MOVIE] game object created renderer_grid=%ux%u original_decoder=unused\n",width,height);
    }
    std::shared_ptr<const movie_assets::Asset> afs(std::uint32_t type,std::uint32_t member){
        // This is only the old caller's cue descriptor. Resolve its immutable
        // imported range to a native key; never open/feed that original range.
        require(type<256,"archive-type",type);const auto descriptor=load<std::uint32_t>(ram,0x20cd00+type*4);require(extent(descriptor,0x11c),"archive-descriptor",descriptor);
        const auto count=load<std::uint32_t>(ram,descriptor+8);require(count&&count<=65536&&member<count,"archive-member",member);
        const auto mode=ram[descriptor+15];require(mode<=1&&load<std::uint32_t>(ram,descriptor+0x110)==0,"archive-profile",descriptor);
        const auto stride=mode==1?4u:2u;require(extent(descriptor,0x118ull+stride*(count+1ull)),"archive-index-bounds",descriptor);
        const auto value=[&](std::uint32_t index){return mode==1?load<std::uint32_t>(ram,descriptor+0x118+index*4):std::uint32_t(load<std::uint16_t>(ram,descriptor+0x118+index*2));};
        std::uint64_t sector=load<std::uint32_t>(ram,descriptor+0x114);for(std::uint32_t i=0;i<=member;++i)sector+=value(i);const auto sectors=value(member+1);
        auto path=lower(string(descriptor+16));const auto slash=path.find_last_of("/:");auto name=path.substr(slash==std::string::npos?0:slash+1);if(name.ends_with(";1"))name.resize(name.size()-2);
        std::fprintf(stderr,"[NATIVE-HOST-MOVIE-CUE] partition=%u member=%u container=%s sector=%llu sectors=%u\n",type,member,name.c_str(),static_cast<unsigned long long>(sector),sectors);
        for(const auto& cue:file1_cues)if(name==cue.container&&sector==cue.sector&&sectors>=cue.sectors){auto found=catalogue->find(cue.key);require(bool(found),"unprepared-native-key",member);return found;}
        fail("unprepared-archive-cue",member);
    }
    std::shared_ptr<const movie_assets::Asset> filename(std::uint32_t at){const auto wanted=lower(string(at));std::shared_ptr<const movie_assets::Asset> found;for(const auto& entry:catalogue->entries()){const auto label=lower(entry.label);if(label==wanted||label.substr(label.find_last_of('/')+1)==wanted){require(!found||found==entry.asset,"ambiguous-filename",at);found=entry.asset;}}require(bool(found),"unprepared-filename",at);return found;}
    void enqueue(std::shared_ptr<const movie_assets::Asset> asset){require(playlist.size()<256,"playlist-capacity");if(started)require(session.append(generation,asset),"append-admission");playlist.push_back(std::move(asset));}
    void start(){require(!held,"start-with-renderer-lease");require(!playlist.empty(),"empty-playlist");generation=session.start(playlist,repeat,width);released=0;started=true;++sources;std::fprintf(stderr,"[NATIVE-HOST-MOVIE] source started generation=%llu clips=%zu loop=%u\n",static_cast<unsigned long long>(generation),playlist.size(),unsigned(repeat));}
    void stop(){require(!held,"stop-with-renderer-lease");if(started)require(session.stop(generation),"stop-admission");started=false;generation=released=0;playlist.clear();}
    std::uint32_t status(){if(!started)return 0;const auto snapshot=session.snapshot();if(snapshot.state==host_movie::State::error){std::fprintf(stderr,"[NATIVE-HOST-MOVIE-ERROR] %s\n",snapshot.error.c_str());return 4;}const auto frame=session.frame(generation);if(snapshot.state==host_movie::State::ended&&(!frame||frame->serial<=released))return 3;return frame?2:1;}
    bool dispatch(Action action,std::uint32_t address,R5900Context& ctx){const auto argument=[&](unsigned i){return GPR_U32((&ctx),i);};const auto handle=argument(4);
        if(action==Action::size){SET_GPR_U32((&ctx),2,required(handle));return true;}
        if(action==Action::create){create(handle,ctx);return true;}
        if(handle!=proxy)return false;
        validate();
        switch(action) {
        case Action::destroy:stop();alive=false;store(ram,proxy+4,0u);return true;
        case Action::enqueue_afs:enqueue(afs(argument(5),argument(6)));return true;
        case Action::start_afs:case Action::repeat_afs:stop();repeat=action==Action::repeat_afs;enqueue(afs(argument(5),argument(6)));start();return true;
        case Action::filename:stop();enqueue(filename(argument(5)));start();return true;
        case Action::start:start();return true;
        case Action::stop:stop();return true;
        case Action::loop:repeat=argument(5)==1;if(started)require(session.loop(generation,repeat),"loop-admission");return true;
        case Action::pause:if(started)require(session.pause(generation,argument(5)!=0),"pause-admission");return true;
        case Action::unlink:return true;
        case Action::status:SET_GPR_U32((&ctx),2,status());return true;
        case Action::time:{const auto numerator=argument(5),denominator=argument(6);output(numerator,4);output(denominator,4);const auto frame=session.frame(generation);store(ram,numerator,frame?static_cast<std::uint32_t>(frame->ordinal):0u);store(ram,denominator,1u);SET_GPR_U32((&ctx),2,0);return true;}
        case Action::information:{output(argument(5),20);std::memset(ram+argument(5),0xff,20);return true;}
        case Action::frame:{const auto out=argument(5);output(out,76);std::memset(ram+out,0,76);require(!held,"nested-renderer-acquire");auto frame=session.frame(generation);if(!frame||frame->serial<=released)return true;
            copy_for_legacy_renderer(*frame,width,height,{ram+pixels,std::size_t(width)*height*4});held=std::move(frame);store(ram,out,pixels);store(ram,out+4,3u);store(ram,out+8,width);store(ram,out+12,height);store(ram,out+16,width*4);store(ram,out+24,1u);store(ram,out+28,30000u);store(ram,out+32,static_cast<std::uint32_t>(held->ordinal));store(ram,out+40,1001u);store(ram,out+48,static_cast<std::uint32_t>(held->ordinal));store(ram,out+72,2u);++frames;return true;}
        case Action::release:if(held){released=held->serial;held.reset();}return true;
        case Action::unsupported:fail("unsupported-public-api",address);
        case Action::size:case Action::create:break;
        }return false;
    }
};
std::mutex installed_mutex;std::shared_ptr<Binding> installed;
std::shared_ptr<Binding> current(){std::lock_guard lock(installed_mutex);return installed;}
template<Action What,std::uint32_t Address,Function Original>void route(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){const auto binding=current();const auto original=binding&&binding->originals.contains(Address)?binding->originals.at(Address):Original;if(!binding||!binding->active.load()){original(ram,ctx,runtime);return;}if(binding->closing.load()){if(ctx)ctx->pc=0;return;}
    binding->require(ctx&&binding->ram==ram&&binding->runtime==runtime&&ps2ActualGuestExecutionDepth(runtime),"guest-identity",Address);
    if(binding->dispatch(What,Address,*ctx))ctx->pc=GPR_U32(ctx,31);else original(ram,ctx,runtime);
}
struct Entry {std::uint32_t address;Function original,wrapper;};
const Entry entries[]{
#define X(address,name,action) {address,name,route<Action::action,address,name>},
#include "entries.inc"
#undef X
};
}
bool install_before_run(PS2Runtime& runtime,const std::filesystem::path& cache)noexcept {
    std::shared_ptr<Binding> binding;std::size_t changed{};std::array<Function,std::size(entries)> previous{};
    try {
        std::unique_lock publication(installed_mutex);
        if(installed&&installed->active.load())return false;
        auto setup=runtime.acquirePreRunSetup();if(!setup){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] pre-run setup unavailable\n");return false;}auto* ram=runtime.memory().getRDRAM();
        if(!ram||load<std::uint32_t>(ram,vtable+0x14)!=0x15d1d0||load<std::uint32_t>(ram,vtable+0x20)!=0x160060){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] public method table mismatch\n");return false;}
        constexpr reo_native_image_identity::Digest expected{0x58,0x59,0xa4,0x9d,0x20,0xf2,0x49,0x2c,0x00,0xfa,0x81,0xab,0xce,0xef,0x49,0x85,0xe8,0xb2,0xb9,0xdb,0xb0,0x3d,0x58,0x5c,0xfe,0xf2,0x48,0xe4,0x05,0x47,0x65,0x42};
        if(reo_native_image_identity::sha256(ram+0x15bf48,0x164128-0x15bf48)!=expected){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] owned code identity mismatch\n");return false;}
        for(std::size_t i=0;i<std::size(entries);++i){const auto& entry=entries[i];previous[i]=runtime.lookupFunction(entry.address);if(!runtime.hasFunction(entry.address)||(previous[i]!=entry.original&&!reoNativeHostMovieReviewedEntry(entry.address,previous[i]))){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] registry mismatch at %08x\n",entry.address);return false;}}
        auto assets=movie_assets::Catalogue::open(cache);
        for(const auto& cue:file1_cues){const auto asset=assets->find(cue.key);if(!asset||asset->frames()!=cue.frames)throw std::runtime_error("Prepared catalogue lacks an admitted native movie cue");}
        binding=std::make_shared<Binding>(runtime,ram,std::move(assets));
        for(std::size_t i=0;i<std::size(entries);++i)binding->originals.emplace(entries[i].address,previous[i]);
        const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(10);for(;;){const auto s=binding->session.snapshot();if(!s.error.empty()||s.joined)return false;if(s.device_ready)break;if(std::chrono::steady_clock::now()>end)return false;std::this_thread::sleep_for(std::chrono::milliseconds(1));}
        if(!runtime.registerExternalWorker(binding))return false;
        installed=binding;
        for(const auto& entry:entries){runtime.registerFunction(entry.address,entry.wrapper);++changed;}
        binding->active.store(true);std::fprintf(stderr,"[NATIVE-HOST-MOVIE] selected entries=%zu cache_entries=%zu decoder=windows-media-engine original_sfd=unused renderer=temporary-game-bridge\n",std::size(entries),binding->catalogue->entries().size());return true;
    }catch(const std::exception& error){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] installation failed: %s\n",error.what());if(binding)binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,previous[i]);return false;}
    catch(...){if(binding)binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,previous[i]);return false;}
}
}
