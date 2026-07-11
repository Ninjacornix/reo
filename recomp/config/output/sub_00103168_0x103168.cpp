#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00103168
// Address: 0x103168 - 0x103390
void sub_00103168_0x103168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x103168u;

    // 0x103168: 0x3c021000
    ctx->pc = 0x103168u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x10316c: 0x3c031000
    ctx->pc = 0x10316cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x103170: 0x3442e000
    ctx->pc = 0x103170u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57344));
    // 0x103174: 0x3463e020
    ctx->pc = 0x103174u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57376));
    // 0x103178: 0x8c4a0000
    ctx->pc = 0x103178u;
    SET_GPR_U32(ctx, 10, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x10317c: 0x3c051000
    ctx->pc = 0x10317cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x103180: 0x8c660000
    ctx->pc = 0x103180u;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103184: 0x80482d
    ctx->pc = 0x103184u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103188: 0x34a5e030
    ctx->pc = 0x103188u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 57392));
    // 0x10318c: 0x3c031000
    ctx->pc = 0x10318cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x103190: 0x8ca50000
    ctx->pc = 0x103190u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x103194: 0x3463e050
    ctx->pc = 0x103194u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57424));
    // 0x103198: 0x3c021000
    ctx->pc = 0x103198u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x10319c: 0x91240000
    ctx->pc = 0x10319cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1031a0: 0x8c660000
    ctx->pc = 0x1031a0u;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1031a4: 0x3442e040
    ctx->pc = 0x1031a4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57408));
    // 0x1031a8: 0x8c480000
    ctx->pc = 0x1031a8u;
    SET_GPR_U32(ctx, 8, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1031ac: 0x2c84000a
    ctx->pc = 0x1031acu;
    SET_GPR_U32(ctx, 4, SLTU32(GPR_U32(ctx, 4), 10));
    // 0x1031b0: 0x54800003
    ctx->pc = 0x1031B0u;
    {
        const bool branch_taken_0x1031b0 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        if (branch_taken_0x1031b0) {
            ctx->pc = 0x1031B4u;
            SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
            ctx->pc = 0x1031C0u;
            goto label_1031c0;
        }
    }
    ctx->pc = 0x1031B8u;
    // 0x1031b8: 0x3e00008
    ctx->pc = 0x1031B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031BCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031C0u;
label_1031c0:
    // 0x1031c0: 0x2c42000a
    ctx->pc = 0x1031c0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 10));
    // 0x1031c4: 0x54400003
    ctx->pc = 0x1031C4u;
    {
        const bool branch_taken_0x1031c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1031c4) {
            ctx->pc = 0x1031C8u;
            SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 2)));
            ctx->pc = 0x1031D4u;
            goto label_1031d4;
        }
    }
    ctx->pc = 0x1031CCu;
    // 0x1031cc: 0x3e00008
    ctx->pc = 0x1031CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031D0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031D4u;
label_1031d4:
    // 0x1031d4: 0x2c42000a
    ctx->pc = 0x1031d4u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 10));
    // 0x1031d8: 0x54400003
    ctx->pc = 0x1031D8u;
    {
        const bool branch_taken_0x1031d8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1031d8) {
            ctx->pc = 0x1031DCu;
            SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
            ctx->pc = 0x1031E8u;
            goto label_1031e8;
        }
    }
    ctx->pc = 0x1031E0u;
    // 0x1031e0: 0x3e00008
    ctx->pc = 0x1031E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031E4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031E8u;
label_1031e8:
    // 0x1031e8: 0x2d620007
    ctx->pc = 0x1031e8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 11), 7));
    // 0x1031ec: 0x14400003
    ctx->pc = 0x1031ECu;
    {
        const bool branch_taken_0x1031ec = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1031F0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
        if (branch_taken_0x1031ec) {
            ctx->pc = 0x1031FCu;
            goto label_1031fc;
        }
    }
    ctx->pc = 0x1031F4u;
    // 0x1031f4: 0x3e00008
    ctx->pc = 0x1031F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031F8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031FCu;
label_1031fc:
    // 0x1031fc: 0x91230000
    ctx->pc = 0x1031fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103200: 0x24427738
    ctx->pc = 0x103200u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 30520));
    // 0x103204: 0x3c040023
    ctx->pc = 0x103204u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x103208: 0x91250001
    ctx->pc = 0x103208u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
    // 0x10320c: 0x621821
    ctx->pc = 0x10320cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x103210: 0x24847748
    ctx->pc = 0x103210u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30536));
    // 0x103214: 0x90680000
    ctx->pc = 0x103214u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x103218: 0xa42821
    ctx->pc = 0x103218u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x10321c: 0x3c02ffff
    ctx->pc = 0x10321cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x103220: 0x3442ffcf
    ctx->pc = 0x103220u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65487));
    // 0x103224: 0x3c040023
    ctx->pc = 0x103224u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x103228: 0x91270002
    ctx->pc = 0x103228u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 2)));
    // 0x10322c: 0x1421024
    ctx->pc = 0x10322cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x103230: 0x24847758
    ctx->pc = 0x103230u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30552));
    // 0x103234: 0x84100
    ctx->pc = 0x103234u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 8), 4));
    // 0x103238: 0x90a60000
    ctx->pc = 0x103238u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10323c: 0x3c03ffff
    ctx->pc = 0x10323cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)65535 << 16));
    // 0x103240: 0x485025
    ctx->pc = 0x103240u;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x103244: 0xe43821
    ctx->pc = 0x103244u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x103248: 0x3463ff3f
    ctx->pc = 0x103248u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65343));
    // 0x10324c: 0x63180
    ctx->pc = 0x10324cu;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 6));
    // 0x103250: 0x1431824
    ctx->pc = 0x103250u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x103254: 0x90e40000
    ctx->pc = 0x103254u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x103258: 0x3c02ffff
    ctx->pc = 0x103258u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x10325c: 0x665025
    ctx->pc = 0x10325cu;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x103260: 0x3442fff3
    ctx->pc = 0x103260u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65523));
    // 0x103264: 0x42080
    ctx->pc = 0x103264u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
    // 0x103268: 0x1421024
    ctx->pc = 0x103268u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x10326c: 0x1160000a
    ctx->pc = 0x10326Cu;
    {
        const bool branch_taken_0x10326c = (GPR_U32(ctx, 11) == GPR_U32(ctx, 0));
        ctx->pc = 0x103270u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        if (branch_taken_0x10326c) {
            ctx->pc = 0x103298u;
            goto label_103298;
        }
    }
    ctx->pc = 0x103274u;
    // 0x103274: 0x91230003
    ctx->pc = 0x103274u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
    // 0x103278: 0x3c02ffff
    ctx->pc = 0x103278u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x10327c: 0x354a0002
    ctx->pc = 0x10327cu;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 10), 2));
    // 0x103280: 0x3442fcff
    ctx->pc = 0x103280u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 64767));
    // 0x103284: 0x2463ffff
    ctx->pc = 0x103284u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x103288: 0x1421024
    ctx->pc = 0x103288u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x10328c: 0x31a00
    ctx->pc = 0x10328cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x103290: 0x10000004
    ctx->pc = 0x103290u;
    {
        const bool branch_taken_0x103290 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x103294u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        if (branch_taken_0x103290) {
            ctx->pc = 0x1032A4u;
            goto label_1032a4;
        }
    }
    ctx->pc = 0x103298u;
label_103298:
    // 0x103298: 0x3c02ffff
    ctx->pc = 0x103298u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x10329c: 0x3442fffd
    ctx->pc = 0x10329cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65533));
    // 0x1032a0: 0x1425024
    ctx->pc = 0x1032a0u;
    SET_GPR_U32(ctx, 10, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
label_1032a4:
    // 0x1032a4: 0x95220004
    ctx->pc = 0x1032a4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x1032a8: 0x3c041000
    ctx->pc = 0x1032a8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1032ac: 0x95260006
    ctx->pc = 0x1032acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 6)));
    // 0x1032b0: 0x3484e000
    ctx->pc = 0x1032b0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 57344));
    // 0x1032b4: 0x9525000a
    ctx->pc = 0x1032b4u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 10)));
    // 0x1032b8: 0x21400
    ctx->pc = 0x1032b8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 16));
    // 0x1032bc: 0x8d280010
    ctx->pc = 0x1032bcu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1032c0: 0x463025
    ctx->pc = 0x1032c0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1032c4: 0x95270008
    ctx->pc = 0x1032c4u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1032c8: 0x3c031000
    ctx->pc = 0x1032c8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1032cc: 0xac8a0000
    ctx->pc = 0x1032ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 10));
    // 0x1032d0: 0x3463e020
    ctx->pc = 0x1032d0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57376));
    // 0x1032d4: 0x52c00
    ctx->pc = 0x1032d4u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 16));
    // 0x1032d8: 0x3c021000
    ctx->pc = 0x1032d8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1032dc: 0xac660000
    ctx->pc = 0x1032dcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x1032e0: 0xa72825
    ctx->pc = 0x1032e0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1032e4: 0x3442e030
    ctx->pc = 0x1032e4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57392));
    // 0x1032e8: 0x8d26000c
    ctx->pc = 0x1032e8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x1032ec: 0xac450000
    ctx->pc = 0x1032ecu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1032f0: 0x3c031000
    ctx->pc = 0x1032f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1032f4: 0x3463e050
    ctx->pc = 0x1032f4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57424));
    // 0x1032f8: 0x3c021000
    ctx->pc = 0x1032f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1032fc: 0xac660000
    ctx->pc = 0x1032fcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x103300: 0x3442e040
    ctx->pc = 0x103300u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57408));
    // 0x103304: 0xac480000
    ctx->pc = 0x103304u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8)); // MMIO: 0x10000000
    // 0x103308: 0x3c030026
    ctx->pc = 0x103308u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x10330c: 0x2466a218
    ctx->pc = 0x10330cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 3), 4294943256));
    // 0x103310: 0x69220007
    ctx->pc = 0x103310u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x103314: 0x6d220000
    ctx->pc = 0x103314u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x103318: 0x6924000f
    ctx->pc = 0x103318u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x10331c: 0x6d240008
    ctx->pc = 0x10331cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x103320: 0x8d250010
    ctx->pc = 0x103320u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x103324: 0xb0c20007
    ctx->pc = 0x103324u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 2) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103328: 0xb4c20000
    ctx->pc = 0x103328u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 2) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x10332c: 0xb0c4000f
    ctx->pc = 0x10332cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103330: 0xb4c40008
    ctx->pc = 0x103330u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103334: 0xacc50010
    ctx->pc = 0x103334u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 5));
    // 0x103338: 0x3e00008
    ctx->pc = 0x103338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10333Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103340u;
    // 0x103340: 0x3c030026
    ctx->pc = 0x103340u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x103344: 0x2468a218
    ctx->pc = 0x103344u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 3), 4294943256));
    // 0x103348: 0x69050007
    ctx->pc = 0x103348u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x10334c: 0x6d050000
    ctx->pc = 0x10334cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x103350: 0x6906000f
    ctx->pc = 0x103350u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x103354: 0x6d060008
    ctx->pc = 0x103354u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x103358: 0x8d070010
    ctx->pc = 0x103358u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x10335c: 0xb0850007
    ctx->pc = 0x10335cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103360: 0xb4850000
    ctx->pc = 0x103360u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103364: 0xb086000f
    ctx->pc = 0x103364u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103368: 0xb4860008
    ctx->pc = 0x103368u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x10336c: 0xac870010
    ctx->pc = 0x10336cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 7));
    // 0x103370: 0x3e00008
    ctx->pc = 0x103370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103374u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103378u;
    // 0x103378: 0x3c031000
    ctx->pc = 0x103378u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x10337c: 0x3463e060
    ctx->pc = 0x10337cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 57440));
    // 0x103380: 0x8c620000
    ctx->pc = 0x103380u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103384: 0x3e00008
    ctx->pc = 0x103384u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103388u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10338Cu;
    // 0x10338c: 0x0
    ctx->pc = 0x10338cu;
    // NOP
}
