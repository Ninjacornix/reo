#pragma once
// Synthetic fixture bytes retained from the pre-oracle v1 lifecycle tests.
struct InputBank {std::vector<std::uint8_t> hd,bd,tq;};
void word16(std::vector<std::uint8_t>& d,std::size_t at,unsigned v){d.at(at)=v&255;d.at(at+1)=(v>>8)&255;}
void word32(std::vector<std::uint8_t>& d,std::size_t at,unsigned v){for(unsigned n=0;n<4;++n)d.at(at+n)=(v>>(n*8))&255;}
void tag(std::vector<std::uint8_t>& d,std::size_t at,const char* value){for(unsigned n=0;n<4;++n){d.at(at+n)=std::uint8_t("SCEI"[3-n]);d.at(at+4+n)=std::uint8_t(value[3-n]);}}
// Synthetic inputs only. No expected output is computed by a second mixer.
InputBank bank(unsigned notes=1,unsigned regions=1,unsigned layers=1){
    InputBank bytes;bytes.hd.resize(0x1800);bytes.bd.resize(32);bytes.tq.resize(0x20+notes*2+8);
    tag(bytes.hd,0,"Vers");tag(bytes.hd,0x10,"Head");
    const unsigned chunks[]{0x40,0xc0,0x140,0x1c0};const char* names[]{"Prog","Sset","Smpl","Vagi"};
    for(unsigned n=0;n<4;++n){word32(bytes.hd,0x24+n*4,chunks[n]);tag(bytes.hd,chunks[n],names[n]);word32(bytes.hd,chunks[n]+16,0x20);}
    const unsigned pr=0x60,ss=0xe0,sm=0x160,va=0x1e0;
    word32(bytes.hd,pr,0x300-pr);bytes.hd[pr+4]=std::uint8_t(regions);bytes.hd[pr+6]=127;bytes.hd[pr+7]=64;
    for(unsigned n=0;n<regions;++n){const auto at=0x300+n*20;bytes.hd[at+3]=64;bytes.hd[at+4]=127;bytes.hd[at+16]=127;bytes.hd[at+17]=64;}
    bytes.hd[ss+2]=127;bytes.hd[ss+3]=std::uint8_t(layers);
    // Large Sset sample lists use a separate record beyond all region data.
    if(layers>1){word32(bytes.hd,0xc0+16,0x1700-0xc0);bytes.hd[0x1702]=127;bytes.hd[0x1703]=std::uint8_t(layers);bytes.hd.resize(0x1904);}
    bytes.hd[sm+3]=64;bytes.hd[sm+4]=127;bytes.hd[sm+0xb]=62;bytes.hd[sm+0xd]=64;bytes.hd[sm+0x10]=127;word16(bytes.hd,sm+0x14,0x1fc0);
    word16(bytes.hd,va+4,48000);
    for(unsigned at:{0u,16u}){bytes.bd[at]=12;bytes.bd[at+1]=at?3:4;for(unsigned n=2;n<16;++n)bytes.bd[at+n]=0x77;}
    word16(bytes.tq,14,1);word32(bytes.tq,16,0x40000020);
    bytes.tq[0x20]=0xe0;bytes.tq[0x21]=127;bytes.tq[0x22]=0xe2;bytes.tq[0x23]=0;
    for(unsigned n=0;n<notes;++n){bytes.tq[0x24+n*2]=0xb2;bytes.tq[0x25+n*2]=127;}
    bytes.tq[0x24+notes*2]=0xff;return bytes;
}
