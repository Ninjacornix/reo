#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010B808
// Address: 0x10b808 - 0x10c7a8
void sub_0010B808_0x10b808(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010B808_0x10b808");
#endif

    switch (ctx->pc) {
        case 0x10b820u: goto label_10b820;
        case 0x10b828u: goto label_10b828;
        case 0x10b850u: goto label_10b850;
        case 0x10b8d8u: goto label_10b8d8;
        case 0x10b940u: goto label_10b940;
        case 0x10b988u: goto label_10b988;
        case 0x10ba18u: goto label_10ba18;
        case 0x10ba68u: goto label_10ba68;
        case 0x10ba88u: goto label_10ba88;
        case 0x10bbc0u: goto label_10bbc0;
        case 0x10bc0cu: goto label_10bc0c;
        case 0x10bcc0u: goto label_10bcc0;
        case 0x10bce0u: goto label_10bce0;
        case 0x10bd10u: goto label_10bd10;
        case 0x10bd24u: goto label_10bd24;
        case 0x10bd3cu: goto label_10bd3c;
        case 0x10bd4cu: goto label_10bd4c;
        case 0x10bd5cu: goto label_10bd5c;
        case 0x10bd94u: goto label_10bd94;
        case 0x10bdb4u: goto label_10bdb4;
        case 0x10bdf0u: goto label_10bdf0;
        case 0x10be0cu: goto label_10be0c;
        case 0x10be60u: goto label_10be60;
        case 0x10bef0u: goto label_10bef0;
        case 0x10bf28u: goto label_10bf28;
        case 0x10bf44u: goto label_10bf44;
        case 0x10bf8cu: goto label_10bf8c;
        case 0x10bfa0u: goto label_10bfa0;
        case 0x10bfb8u: goto label_10bfb8;
        case 0x10bfc8u: goto label_10bfc8;
        case 0x10bfd8u: goto label_10bfd8;
        case 0x10bfe0u: goto label_10bfe0;
        case 0x10bfe4u: goto label_10bfe4;
        case 0x10c000u: goto label_10c000;
        case 0x10c00cu: goto label_10c00c;
        case 0x10c01cu: goto label_10c01c;
        case 0x10c040u: goto label_10c040;
        case 0x10c050u: goto label_10c050;
        case 0x10c05cu: goto label_10c05c;
        case 0x10c06cu: goto label_10c06c;
        case 0x10c080u: goto label_10c080;
        case 0x10c158u: goto label_10c158;
        case 0x10c168u: goto label_10c168;
        case 0x10c17cu: goto label_10c17c;
        case 0x10c198u: goto label_10c198;
        case 0x10c1b0u: goto label_10c1b0;
        case 0x10c224u: goto label_10c224;
        case 0x10c254u: goto label_10c254;
        case 0x10c268u: goto label_10c268;
        case 0x10c288u: goto label_10c288;
        case 0x10c2a8u: goto label_10c2a8;
        case 0x10c2bcu: goto label_10c2bc;
        case 0x10c304u: goto label_10c304;
        case 0x10c314u: goto label_10c314;
        case 0x10c324u: goto label_10c324;
        case 0x10c3c0u: goto label_10c3c0;
        case 0x10c3dcu: goto label_10c3dc;
        case 0x10c3e8u: goto label_10c3e8;
        case 0x10c3f0u: goto label_10c3f0;
        case 0x10c40cu: goto label_10c40c;
        case 0x10c41cu: goto label_10c41c;
        case 0x10c42cu: goto label_10c42c;
        case 0x10c43cu: goto label_10c43c;
        case 0x10c46cu: goto label_10c46c;
        case 0x10c474u: goto label_10c474;
        case 0x10c484u: goto label_10c484;
        case 0x10c4b8u: goto label_10c4b8;
        case 0x10c4d4u: goto label_10c4d4;
        case 0x10c4fcu: goto label_10c4fc;
        case 0x10c510u: goto label_10c510;
        case 0x10c51cu: goto label_10c51c;
        case 0x10c528u: goto label_10c528;
        case 0x10c534u: goto label_10c534;
        case 0x10c544u: goto label_10c544;
        case 0x10c564u: goto label_10c564;
        case 0x10c578u: goto label_10c578;
        case 0x10c588u: goto label_10c588;
        case 0x10c630u: goto label_10c630;
        case 0x10c644u: goto label_10c644;
        case 0x10c654u: goto label_10c654;
        case 0x10c66cu: goto label_10c66c;
        case 0x10c684u: goto label_10c684;
        case 0x10c69cu: goto label_10c69c;
        case 0x10c6b8u: goto label_10c6b8;
        case 0x10c6ccu: goto label_10c6cc;
        case 0x10c6e4u: goto label_10c6e4;
        case 0x10c718u: goto label_10c718;
        case 0x10c724u: goto label_10c724;
        case 0x10c730u: goto label_10c730;
        case 0x10c73cu: goto label_10c73c;
        case 0x10c748u: goto label_10c748;
        case 0x10c774u: goto label_10c774;
        default: break;
    }

    ctx->pc = 0x10b808u;

    // 0x10b808: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10b808u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b80c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10B80Cu;
    {
        const bool branch_taken_0x10b80c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B80Cu;
            // 0x10b810: 0x80a30000  lb          $v1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b80c) {
            ctx->pc = 0x10B828u;
            goto label_10b828;
        }
    }
    ctx->pc = 0x10B814u;
    // 0x10b814: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10b814u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b818: 0x3e00008  jr          $ra
    ctx->pc = 0x10B818u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B818u;
            // 0x10b81c: 0x83100a  movz        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B820u: goto label_10b820;
            case 0x10B828u: goto label_10b828;
            case 0x10B850u: goto label_10b850;
            case 0x10B878u: goto label_10b878;
            case 0x10B8D8u: goto label_10b8d8;
            case 0x10B900u: goto label_10b900;
            case 0x10B908u: goto label_10b908;
            case 0x10B920u: goto label_10b920;
            case 0x10B928u: goto label_10b928;
            case 0x10B940u: goto label_10b940;
            case 0x10B964u: goto label_10b964;
            case 0x10B988u: goto label_10b988;
            case 0x10B9B0u: goto label_10b9b0;
            case 0x10B9CCu: goto label_10b9cc;
            case 0x10B9D0u: goto label_10b9d0;
            case 0x10B9DCu: goto label_10b9dc;
            case 0x10B9F4u: goto label_10b9f4;
            case 0x10BA18u: goto label_10ba18;
            case 0x10BA38u: goto label_10ba38;
            case 0x10BA58u: goto label_10ba58;
            case 0x10BA68u: goto label_10ba68;
            case 0x10BA88u: goto label_10ba88;
            case 0x10BAB0u: goto label_10bab0;
            case 0x10BAC8u: goto label_10bac8;
            case 0x10BACCu: goto label_10bacc;
            case 0x10BAD4u: goto label_10bad4;
            case 0x10BB00u: goto label_10bb00;
            case 0x10BB1Cu: goto label_10bb1c;
            case 0x10BB20u: goto label_10bb20;
            case 0x10BB3Cu: goto label_10bb3c;
            case 0x10BB40u: goto label_10bb40;
            case 0x10BB54u: goto label_10bb54;
            case 0x10BB70u: goto label_10bb70;
            case 0x10BB94u: goto label_10bb94;
            case 0x10BBA0u: goto label_10bba0;
            case 0x10BBC0u: goto label_10bbc0;
            case 0x10BBE0u: goto label_10bbe0;
            case 0x10BC0Cu: goto label_10bc0c;
            case 0x10BC48u: goto label_10bc48;
            case 0x10BC6Cu: goto label_10bc6c;
            case 0x10BC84u: goto label_10bc84;
            case 0x10BC90u: goto label_10bc90;
            case 0x10BCC0u: goto label_10bcc0;
            case 0x10BCE0u: goto label_10bce0;
            case 0x10BCE4u: goto label_10bce4;
            case 0x10BD10u: goto label_10bd10;
            case 0x10BD24u: goto label_10bd24;
            case 0x10BD30u: goto label_10bd30;
            case 0x10BD3Cu: goto label_10bd3c;
            case 0x10BD4Cu: goto label_10bd4c;
            case 0x10BD5Cu: goto label_10bd5c;
            case 0x10BD64u: goto label_10bd64;
            case 0x10BD94u: goto label_10bd94;
            case 0x10BD98u: goto label_10bd98;
            case 0x10BDB4u: goto label_10bdb4;
            case 0x10BDD8u: goto label_10bdd8;
            case 0x10BDF0u: goto label_10bdf0;
            case 0x10BE0Cu: goto label_10be0c;
            case 0x10BE10u: goto label_10be10;
            case 0x10BE28u: goto label_10be28;
            case 0x10BE30u: goto label_10be30;
            case 0x10BE60u: goto label_10be60;
            case 0x10BEA8u: goto label_10bea8;
            case 0x10BEC0u: goto label_10bec0;
            case 0x10BEF0u: goto label_10bef0;
            case 0x10BEF4u: goto label_10bef4;
            case 0x10BF28u: goto label_10bf28;
            case 0x10BF44u: goto label_10bf44;
            case 0x10BF48u: goto label_10bf48;
            case 0x10BF60u: goto label_10bf60;
            case 0x10BF68u: goto label_10bf68;
            case 0x10BF8Cu: goto label_10bf8c;
            case 0x10BFA0u: goto label_10bfa0;
            case 0x10BFB8u: goto label_10bfb8;
            case 0x10BFC8u: goto label_10bfc8;
            case 0x10BFD8u: goto label_10bfd8;
            case 0x10BFE0u: goto label_10bfe0;
            case 0x10BFE4u: goto label_10bfe4;
            case 0x10C000u: goto label_10c000;
            case 0x10C00Cu: goto label_10c00c;
            case 0x10C01Cu: goto label_10c01c;
            case 0x10C028u: goto label_10c028;
            case 0x10C02Cu: goto label_10c02c;
            case 0x10C040u: goto label_10c040;
            case 0x10C050u: goto label_10c050;
            case 0x10C05Cu: goto label_10c05c;
            case 0x10C06Cu: goto label_10c06c;
            case 0x10C080u: goto label_10c080;
            case 0x10C0D8u: goto label_10c0d8;
            case 0x10C0ECu: goto label_10c0ec;
            case 0x10C130u: goto label_10c130;
            case 0x10C158u: goto label_10c158;
            case 0x10C168u: goto label_10c168;
            case 0x10C17Cu: goto label_10c17c;
            case 0x10C190u: goto label_10c190;
            case 0x10C198u: goto label_10c198;
            case 0x10C1B0u: goto label_10c1b0;
            case 0x10C1D8u: goto label_10c1d8;
            case 0x10C210u: goto label_10c210;
            case 0x10C224u: goto label_10c224;
            case 0x10C240u: goto label_10c240;
            case 0x10C254u: goto label_10c254;
            case 0x10C258u: goto label_10c258;
            case 0x10C268u: goto label_10c268;
            case 0x10C270u: goto label_10c270;
            case 0x10C288u: goto label_10c288;
            case 0x10C2A8u: goto label_10c2a8;
            case 0x10C2ACu: goto label_10c2ac;
            case 0x10C2BCu: goto label_10c2bc;
            case 0x10C2C0u: goto label_10c2c0;
            case 0x10C304u: goto label_10c304;
            case 0x10C314u: goto label_10c314;
            case 0x10C324u: goto label_10c324;
            case 0x10C380u: goto label_10c380;
            case 0x10C398u: goto label_10c398;
            case 0x10C3C0u: goto label_10c3c0;
            case 0x10C3DCu: goto label_10c3dc;
            case 0x10C3E8u: goto label_10c3e8;
            case 0x10C3F0u: goto label_10c3f0;
            case 0x10C40Cu: goto label_10c40c;
            case 0x10C410u: goto label_10c410;
            case 0x10C41Cu: goto label_10c41c;
            case 0x10C42Cu: goto label_10c42c;
            case 0x10C43Cu: goto label_10c43c;
            case 0x10C440u: goto label_10c440;
            case 0x10C46Cu: goto label_10c46c;
            case 0x10C474u: goto label_10c474;
            case 0x10C484u: goto label_10c484;
            case 0x10C4A4u: goto label_10c4a4;
            case 0x10C4B8u: goto label_10c4b8;
            case 0x10C4D4u: goto label_10c4d4;
            case 0x10C4E8u: goto label_10c4e8;
            case 0x10C4FCu: goto label_10c4fc;
            case 0x10C504u: goto label_10c504;
            case 0x10C508u: goto label_10c508;
            case 0x10C510u: goto label_10c510;
            case 0x10C51Cu: goto label_10c51c;
            case 0x10C528u: goto label_10c528;
            case 0x10C534u: goto label_10c534;
            case 0x10C544u: goto label_10c544;
            case 0x10C564u: goto label_10c564;
            case 0x10C578u: goto label_10c578;
            case 0x10C588u: goto label_10c588;
            case 0x10C5A8u: goto label_10c5a8;
            case 0x10C5BCu: goto label_10c5bc;
            case 0x10C5CCu: goto label_10c5cc;
            case 0x10C5F0u: goto label_10c5f0;
            case 0x10C620u: goto label_10c620;
            case 0x10C630u: goto label_10c630;
            case 0x10C644u: goto label_10c644;
            case 0x10C654u: goto label_10c654;
            case 0x10C658u: goto label_10c658;
            case 0x10C66Cu: goto label_10c66c;
            case 0x10C670u: goto label_10c670;
            case 0x10C684u: goto label_10c684;
            case 0x10C688u: goto label_10c688;
            case 0x10C69Cu: goto label_10c69c;
            case 0x10C6A0u: goto label_10c6a0;
            case 0x10C6B8u: goto label_10c6b8;
            case 0x10C6C0u: goto label_10c6c0;
            case 0x10C6CCu: goto label_10c6cc;
            case 0x10C6E4u: goto label_10c6e4;
            case 0x10C70Cu: goto label_10c70c;
            case 0x10C710u: goto label_10c710;
            case 0x10C718u: goto label_10c718;
            case 0x10C724u: goto label_10c724;
            case 0x10C730u: goto label_10c730;
            case 0x10C73Cu: goto label_10c73c;
            case 0x10C748u: goto label_10c748;
            case 0x10C74Cu: goto label_10c74c;
            case 0x10C754u: goto label_10c754;
            case 0x10C774u: goto label_10c774;
            case 0x10C778u: goto label_10c778;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B820u;
label_10b820:
    // 0x10b820: 0x3e00008  jr          $ra
    ctx->pc = 0x10B820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B820u;
            // 0x10b824: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B820u: goto label_10b820;
            case 0x10B828u: goto label_10b828;
            case 0x10B850u: goto label_10b850;
            case 0x10B878u: goto label_10b878;
            case 0x10B8D8u: goto label_10b8d8;
            case 0x10B900u: goto label_10b900;
            case 0x10B908u: goto label_10b908;
            case 0x10B920u: goto label_10b920;
            case 0x10B928u: goto label_10b928;
            case 0x10B940u: goto label_10b940;
            case 0x10B964u: goto label_10b964;
            case 0x10B988u: goto label_10b988;
            case 0x10B9B0u: goto label_10b9b0;
            case 0x10B9CCu: goto label_10b9cc;
            case 0x10B9D0u: goto label_10b9d0;
            case 0x10B9DCu: goto label_10b9dc;
            case 0x10B9F4u: goto label_10b9f4;
            case 0x10BA18u: goto label_10ba18;
            case 0x10BA38u: goto label_10ba38;
            case 0x10BA58u: goto label_10ba58;
            case 0x10BA68u: goto label_10ba68;
            case 0x10BA88u: goto label_10ba88;
            case 0x10BAB0u: goto label_10bab0;
            case 0x10BAC8u: goto label_10bac8;
            case 0x10BACCu: goto label_10bacc;
            case 0x10BAD4u: goto label_10bad4;
            case 0x10BB00u: goto label_10bb00;
            case 0x10BB1Cu: goto label_10bb1c;
            case 0x10BB20u: goto label_10bb20;
            case 0x10BB3Cu: goto label_10bb3c;
            case 0x10BB40u: goto label_10bb40;
            case 0x10BB54u: goto label_10bb54;
            case 0x10BB70u: goto label_10bb70;
            case 0x10BB94u: goto label_10bb94;
            case 0x10BBA0u: goto label_10bba0;
            case 0x10BBC0u: goto label_10bbc0;
            case 0x10BBE0u: goto label_10bbe0;
            case 0x10BC0Cu: goto label_10bc0c;
            case 0x10BC48u: goto label_10bc48;
            case 0x10BC6Cu: goto label_10bc6c;
            case 0x10BC84u: goto label_10bc84;
            case 0x10BC90u: goto label_10bc90;
            case 0x10BCC0u: goto label_10bcc0;
            case 0x10BCE0u: goto label_10bce0;
            case 0x10BCE4u: goto label_10bce4;
            case 0x10BD10u: goto label_10bd10;
            case 0x10BD24u: goto label_10bd24;
            case 0x10BD30u: goto label_10bd30;
            case 0x10BD3Cu: goto label_10bd3c;
            case 0x10BD4Cu: goto label_10bd4c;
            case 0x10BD5Cu: goto label_10bd5c;
            case 0x10BD64u: goto label_10bd64;
            case 0x10BD94u: goto label_10bd94;
            case 0x10BD98u: goto label_10bd98;
            case 0x10BDB4u: goto label_10bdb4;
            case 0x10BDD8u: goto label_10bdd8;
            case 0x10BDF0u: goto label_10bdf0;
            case 0x10BE0Cu: goto label_10be0c;
            case 0x10BE10u: goto label_10be10;
            case 0x10BE28u: goto label_10be28;
            case 0x10BE30u: goto label_10be30;
            case 0x10BE60u: goto label_10be60;
            case 0x10BEA8u: goto label_10bea8;
            case 0x10BEC0u: goto label_10bec0;
            case 0x10BEF0u: goto label_10bef0;
            case 0x10BEF4u: goto label_10bef4;
            case 0x10BF28u: goto label_10bf28;
            case 0x10BF44u: goto label_10bf44;
            case 0x10BF48u: goto label_10bf48;
            case 0x10BF60u: goto label_10bf60;
            case 0x10BF68u: goto label_10bf68;
            case 0x10BF8Cu: goto label_10bf8c;
            case 0x10BFA0u: goto label_10bfa0;
            case 0x10BFB8u: goto label_10bfb8;
            case 0x10BFC8u: goto label_10bfc8;
            case 0x10BFD8u: goto label_10bfd8;
            case 0x10BFE0u: goto label_10bfe0;
            case 0x10BFE4u: goto label_10bfe4;
            case 0x10C000u: goto label_10c000;
            case 0x10C00Cu: goto label_10c00c;
            case 0x10C01Cu: goto label_10c01c;
            case 0x10C028u: goto label_10c028;
            case 0x10C02Cu: goto label_10c02c;
            case 0x10C040u: goto label_10c040;
            case 0x10C050u: goto label_10c050;
            case 0x10C05Cu: goto label_10c05c;
            case 0x10C06Cu: goto label_10c06c;
            case 0x10C080u: goto label_10c080;
            case 0x10C0D8u: goto label_10c0d8;
            case 0x10C0ECu: goto label_10c0ec;
            case 0x10C130u: goto label_10c130;
            case 0x10C158u: goto label_10c158;
            case 0x10C168u: goto label_10c168;
            case 0x10C17Cu: goto label_10c17c;
            case 0x10C190u: goto label_10c190;
            case 0x10C198u: goto label_10c198;
            case 0x10C1B0u: goto label_10c1b0;
            case 0x10C1D8u: goto label_10c1d8;
            case 0x10C210u: goto label_10c210;
            case 0x10C224u: goto label_10c224;
            case 0x10C240u: goto label_10c240;
            case 0x10C254u: goto label_10c254;
            case 0x10C258u: goto label_10c258;
            case 0x10C268u: goto label_10c268;
            case 0x10C270u: goto label_10c270;
            case 0x10C288u: goto label_10c288;
            case 0x10C2A8u: goto label_10c2a8;
            case 0x10C2ACu: goto label_10c2ac;
            case 0x10C2BCu: goto label_10c2bc;
            case 0x10C2C0u: goto label_10c2c0;
            case 0x10C304u: goto label_10c304;
            case 0x10C314u: goto label_10c314;
            case 0x10C324u: goto label_10c324;
            case 0x10C380u: goto label_10c380;
            case 0x10C398u: goto label_10c398;
            case 0x10C3C0u: goto label_10c3c0;
            case 0x10C3DCu: goto label_10c3dc;
            case 0x10C3E8u: goto label_10c3e8;
            case 0x10C3F0u: goto label_10c3f0;
            case 0x10C40Cu: goto label_10c40c;
            case 0x10C410u: goto label_10c410;
            case 0x10C41Cu: goto label_10c41c;
            case 0x10C42Cu: goto label_10c42c;
            case 0x10C43Cu: goto label_10c43c;
            case 0x10C440u: goto label_10c440;
            case 0x10C46Cu: goto label_10c46c;
            case 0x10C474u: goto label_10c474;
            case 0x10C484u: goto label_10c484;
            case 0x10C4A4u: goto label_10c4a4;
            case 0x10C4B8u: goto label_10c4b8;
            case 0x10C4D4u: goto label_10c4d4;
            case 0x10C4E8u: goto label_10c4e8;
            case 0x10C4FCu: goto label_10c4fc;
            case 0x10C504u: goto label_10c504;
            case 0x10C508u: goto label_10c508;
            case 0x10C510u: goto label_10c510;
            case 0x10C51Cu: goto label_10c51c;
            case 0x10C528u: goto label_10c528;
            case 0x10C534u: goto label_10c534;
            case 0x10C544u: goto label_10c544;
            case 0x10C564u: goto label_10c564;
            case 0x10C578u: goto label_10c578;
            case 0x10C588u: goto label_10c588;
            case 0x10C5A8u: goto label_10c5a8;
            case 0x10C5BCu: goto label_10c5bc;
            case 0x10C5CCu: goto label_10c5cc;
            case 0x10C5F0u: goto label_10c5f0;
            case 0x10C620u: goto label_10c620;
            case 0x10C630u: goto label_10c630;
            case 0x10C644u: goto label_10c644;
            case 0x10C654u: goto label_10c654;
            case 0x10C658u: goto label_10c658;
            case 0x10C66Cu: goto label_10c66c;
            case 0x10C670u: goto label_10c670;
            case 0x10C684u: goto label_10c684;
            case 0x10C688u: goto label_10c688;
            case 0x10C69Cu: goto label_10c69c;
            case 0x10C6A0u: goto label_10c6a0;
            case 0x10C6B8u: goto label_10c6b8;
            case 0x10C6C0u: goto label_10c6c0;
            case 0x10C6CCu: goto label_10c6cc;
            case 0x10C6E4u: goto label_10c6e4;
            case 0x10C70Cu: goto label_10c70c;
            case 0x10C710u: goto label_10c710;
            case 0x10C718u: goto label_10c718;
            case 0x10C724u: goto label_10c724;
            case 0x10C730u: goto label_10c730;
            case 0x10C73Cu: goto label_10c73c;
            case 0x10C748u: goto label_10c748;
            case 0x10C74Cu: goto label_10c74c;
            case 0x10C754u: goto label_10c754;
            case 0x10C774u: goto label_10c774;
            case 0x10C778u: goto label_10c778;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B828u;
label_10b828:
    // 0x10b828: 0x0  nop
    ctx->pc = 0x10b828u;
    // NOP
    // 0x10b82c: 0x0  nop
    ctx->pc = 0x10b82cu;
    // NOP
    // 0x10b830: 0x0  nop
    ctx->pc = 0x10b830u;
    // NOP
    // 0x10b834: 0x1060fffa  beqz        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10B834u;
    {
        const bool branch_taken_0x10b834 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B834u;
            // 0x10b838: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b834) {
            ctx->pc = 0x10B820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b820;
        }
    }
    ctx->pc = 0x10B83Cu;
    // 0x10b83c: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10b83cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b840: 0x5462000d  bnel        $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x10B840u;
    {
        const bool branch_taken_0x10b840 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x10b840) {
            ctx->pc = 0x10B844u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B840u;
            // 0x10b844: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B878u;
            goto label_10b878;
        }
    }
    ctx->pc = 0x10B848u;
    // 0x10b848: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x10b848u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x10b84c: 0x0  nop
    ctx->pc = 0x10b84cu;
    // NOP
label_10b850:
    // 0x10b850: 0xa71021  addu        $v0, $a1, $a3
    ctx->pc = 0x10b850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x10b854: 0x80430000  lb          $v1, 0x0($v0)
    ctx->pc = 0x10b854u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10b858: 0x1060fff1  beqz        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x10B858u;
    {
        const bool branch_taken_0x10b858 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B85Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B858u;
            // 0x10b85c: 0x873021  addu        $a2, $a0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b858) {
            ctx->pc = 0x10B820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b820;
        }
    }
    ctx->pc = 0x10B860u;
    // 0x10b860: 0x80c20000  lb          $v0, 0x0($a2)
    ctx->pc = 0x10b860u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10b864: 0x0  nop
    ctx->pc = 0x10b864u;
    // NOP
    // 0x10b868: 0x0  nop
    ctx->pc = 0x10b868u;
    // NOP
    // 0x10b86c: 0x5062fff8  beql        $v1, $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10B86Cu;
    {
        const bool branch_taken_0x10b86c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x10b86c) {
            ctx->pc = 0x10B870u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B86Cu;
            // 0x10b870: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B850u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b850;
        }
    }
    ctx->pc = 0x10B874u;
    // 0x10b874: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10b874u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_10b878:
    // 0x10b878: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10b878u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b87c: 0x5440ffea  bnel        $v0, $zero, . + 4 + (-0x16 << 2)
    ctx->pc = 0x10B87Cu;
    {
        const bool branch_taken_0x10b87c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b87c) {
            ctx->pc = 0x10B880u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B87Cu;
            // 0x10b880: 0x80a30000  lb          $v1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B828u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b828;
        }
    }
    ctx->pc = 0x10B884u;
    // 0x10b884: 0x3e00008  jr          $ra
    ctx->pc = 0x10B884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B884u;
            // 0x10b888: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B820u: goto label_10b820;
            case 0x10B828u: goto label_10b828;
            case 0x10B850u: goto label_10b850;
            case 0x10B878u: goto label_10b878;
            case 0x10B8D8u: goto label_10b8d8;
            case 0x10B900u: goto label_10b900;
            case 0x10B908u: goto label_10b908;
            case 0x10B920u: goto label_10b920;
            case 0x10B928u: goto label_10b928;
            case 0x10B940u: goto label_10b940;
            case 0x10B964u: goto label_10b964;
            case 0x10B988u: goto label_10b988;
            case 0x10B9B0u: goto label_10b9b0;
            case 0x10B9CCu: goto label_10b9cc;
            case 0x10B9D0u: goto label_10b9d0;
            case 0x10B9DCu: goto label_10b9dc;
            case 0x10B9F4u: goto label_10b9f4;
            case 0x10BA18u: goto label_10ba18;
            case 0x10BA38u: goto label_10ba38;
            case 0x10BA58u: goto label_10ba58;
            case 0x10BA68u: goto label_10ba68;
            case 0x10BA88u: goto label_10ba88;
            case 0x10BAB0u: goto label_10bab0;
            case 0x10BAC8u: goto label_10bac8;
            case 0x10BACCu: goto label_10bacc;
            case 0x10BAD4u: goto label_10bad4;
            case 0x10BB00u: goto label_10bb00;
            case 0x10BB1Cu: goto label_10bb1c;
            case 0x10BB20u: goto label_10bb20;
            case 0x10BB3Cu: goto label_10bb3c;
            case 0x10BB40u: goto label_10bb40;
            case 0x10BB54u: goto label_10bb54;
            case 0x10BB70u: goto label_10bb70;
            case 0x10BB94u: goto label_10bb94;
            case 0x10BBA0u: goto label_10bba0;
            case 0x10BBC0u: goto label_10bbc0;
            case 0x10BBE0u: goto label_10bbe0;
            case 0x10BC0Cu: goto label_10bc0c;
            case 0x10BC48u: goto label_10bc48;
            case 0x10BC6Cu: goto label_10bc6c;
            case 0x10BC84u: goto label_10bc84;
            case 0x10BC90u: goto label_10bc90;
            case 0x10BCC0u: goto label_10bcc0;
            case 0x10BCE0u: goto label_10bce0;
            case 0x10BCE4u: goto label_10bce4;
            case 0x10BD10u: goto label_10bd10;
            case 0x10BD24u: goto label_10bd24;
            case 0x10BD30u: goto label_10bd30;
            case 0x10BD3Cu: goto label_10bd3c;
            case 0x10BD4Cu: goto label_10bd4c;
            case 0x10BD5Cu: goto label_10bd5c;
            case 0x10BD64u: goto label_10bd64;
            case 0x10BD94u: goto label_10bd94;
            case 0x10BD98u: goto label_10bd98;
            case 0x10BDB4u: goto label_10bdb4;
            case 0x10BDD8u: goto label_10bdd8;
            case 0x10BDF0u: goto label_10bdf0;
            case 0x10BE0Cu: goto label_10be0c;
            case 0x10BE10u: goto label_10be10;
            case 0x10BE28u: goto label_10be28;
            case 0x10BE30u: goto label_10be30;
            case 0x10BE60u: goto label_10be60;
            case 0x10BEA8u: goto label_10bea8;
            case 0x10BEC0u: goto label_10bec0;
            case 0x10BEF0u: goto label_10bef0;
            case 0x10BEF4u: goto label_10bef4;
            case 0x10BF28u: goto label_10bf28;
            case 0x10BF44u: goto label_10bf44;
            case 0x10BF48u: goto label_10bf48;
            case 0x10BF60u: goto label_10bf60;
            case 0x10BF68u: goto label_10bf68;
            case 0x10BF8Cu: goto label_10bf8c;
            case 0x10BFA0u: goto label_10bfa0;
            case 0x10BFB8u: goto label_10bfb8;
            case 0x10BFC8u: goto label_10bfc8;
            case 0x10BFD8u: goto label_10bfd8;
            case 0x10BFE0u: goto label_10bfe0;
            case 0x10BFE4u: goto label_10bfe4;
            case 0x10C000u: goto label_10c000;
            case 0x10C00Cu: goto label_10c00c;
            case 0x10C01Cu: goto label_10c01c;
            case 0x10C028u: goto label_10c028;
            case 0x10C02Cu: goto label_10c02c;
            case 0x10C040u: goto label_10c040;
            case 0x10C050u: goto label_10c050;
            case 0x10C05Cu: goto label_10c05c;
            case 0x10C06Cu: goto label_10c06c;
            case 0x10C080u: goto label_10c080;
            case 0x10C0D8u: goto label_10c0d8;
            case 0x10C0ECu: goto label_10c0ec;
            case 0x10C130u: goto label_10c130;
            case 0x10C158u: goto label_10c158;
            case 0x10C168u: goto label_10c168;
            case 0x10C17Cu: goto label_10c17c;
            case 0x10C190u: goto label_10c190;
            case 0x10C198u: goto label_10c198;
            case 0x10C1B0u: goto label_10c1b0;
            case 0x10C1D8u: goto label_10c1d8;
            case 0x10C210u: goto label_10c210;
            case 0x10C224u: goto label_10c224;
            case 0x10C240u: goto label_10c240;
            case 0x10C254u: goto label_10c254;
            case 0x10C258u: goto label_10c258;
            case 0x10C268u: goto label_10c268;
            case 0x10C270u: goto label_10c270;
            case 0x10C288u: goto label_10c288;
            case 0x10C2A8u: goto label_10c2a8;
            case 0x10C2ACu: goto label_10c2ac;
            case 0x10C2BCu: goto label_10c2bc;
            case 0x10C2C0u: goto label_10c2c0;
            case 0x10C304u: goto label_10c304;
            case 0x10C314u: goto label_10c314;
            case 0x10C324u: goto label_10c324;
            case 0x10C380u: goto label_10c380;
            case 0x10C398u: goto label_10c398;
            case 0x10C3C0u: goto label_10c3c0;
            case 0x10C3DCu: goto label_10c3dc;
            case 0x10C3E8u: goto label_10c3e8;
            case 0x10C3F0u: goto label_10c3f0;
            case 0x10C40Cu: goto label_10c40c;
            case 0x10C410u: goto label_10c410;
            case 0x10C41Cu: goto label_10c41c;
            case 0x10C42Cu: goto label_10c42c;
            case 0x10C43Cu: goto label_10c43c;
            case 0x10C440u: goto label_10c440;
            case 0x10C46Cu: goto label_10c46c;
            case 0x10C474u: goto label_10c474;
            case 0x10C484u: goto label_10c484;
            case 0x10C4A4u: goto label_10c4a4;
            case 0x10C4B8u: goto label_10c4b8;
            case 0x10C4D4u: goto label_10c4d4;
            case 0x10C4E8u: goto label_10c4e8;
            case 0x10C4FCu: goto label_10c4fc;
            case 0x10C504u: goto label_10c504;
            case 0x10C508u: goto label_10c508;
            case 0x10C510u: goto label_10c510;
            case 0x10C51Cu: goto label_10c51c;
            case 0x10C528u: goto label_10c528;
            case 0x10C534u: goto label_10c534;
            case 0x10C544u: goto label_10c544;
            case 0x10C564u: goto label_10c564;
            case 0x10C578u: goto label_10c578;
            case 0x10C588u: goto label_10c588;
            case 0x10C5A8u: goto label_10c5a8;
            case 0x10C5BCu: goto label_10c5bc;
            case 0x10C5CCu: goto label_10c5cc;
            case 0x10C5F0u: goto label_10c5f0;
            case 0x10C620u: goto label_10c620;
            case 0x10C630u: goto label_10c630;
            case 0x10C644u: goto label_10c644;
            case 0x10C654u: goto label_10c654;
            case 0x10C658u: goto label_10c658;
            case 0x10C66Cu: goto label_10c66c;
            case 0x10C670u: goto label_10c670;
            case 0x10C684u: goto label_10c684;
            case 0x10C688u: goto label_10c688;
            case 0x10C69Cu: goto label_10c69c;
            case 0x10C6A0u: goto label_10c6a0;
            case 0x10C6B8u: goto label_10c6b8;
            case 0x10C6C0u: goto label_10c6c0;
            case 0x10C6CCu: goto label_10c6cc;
            case 0x10C6E4u: goto label_10c6e4;
            case 0x10C70Cu: goto label_10c70c;
            case 0x10C710u: goto label_10c710;
            case 0x10C718u: goto label_10c718;
            case 0x10C724u: goto label_10c724;
            case 0x10C730u: goto label_10c730;
            case 0x10C73Cu: goto label_10c73c;
            case 0x10C748u: goto label_10c748;
            case 0x10C74Cu: goto label_10c74c;
            case 0x10C754u: goto label_10c754;
            case 0x10C774u: goto label_10c774;
            case 0x10C778u: goto label_10c778;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B88Cu;
    // 0x10b88c: 0x0  nop
    ctx->pc = 0x10b88cu;
    // NOP
    // 0x10b890: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x10b890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x10b894: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x10b894u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b898: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x10b898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x10b89c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x10b89cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b8a0: 0xffb10058  sd          $s1, 0x58($sp)
    ctx->pc = 0x10b8a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 17));
    // 0x10b8a4: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x10b8a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x10b8a8: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x10b8a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x10b8ac: 0xffb50078  sd          $s5, 0x78($sp)
    ctx->pc = 0x10b8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 21));
    // 0x10b8b0: 0xffb70088  sd          $s7, 0x88($sp)
    ctx->pc = 0x10b8b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 23));
    // 0x10b8b4: 0xffbf0098  sd          $ra, 0x98($sp)
    ctx->pc = 0x10b8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 31));
    // 0x10b8b8: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x10b8b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x10b8bc: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x10b8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
    // 0x10b8c0: 0xffb30068  sd          $s3, 0x68($sp)
    ctx->pc = 0x10b8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 19));
    // 0x10b8c4: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x10b8c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b8c8: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x10b8c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x10b8cc: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x10b8ccu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b8d0: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x10b8d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x10b8d4: 0x80f02d  daddu       $fp, $a0, $zero
    ctx->pc = 0x10b8d4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10b8d8:
    // 0x10b8d8: 0x82c30000  lb          $v1, 0x0($s6)
    ctx->pc = 0x10b8d8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10b8dc: 0x2c62002e  sltiu       $v0, $v1, 0x2E
    ctx->pc = 0x10b8dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)46) ? 1 : 0);
    // 0x10b8e0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x10B8E0u;
    {
        const bool branch_taken_0x10b8e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B8E0u;
            // 0x10b8e4: 0x92c40000  lbu         $a0, 0x0($s6) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b8e0) {
            ctx->pc = 0x10B928u;
            goto label_10b928;
        }
    }
    ctx->pc = 0x10B8E8u;
    // 0x10b8e8: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x10b8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x10b8ec: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10b8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10b8f0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10b8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10b8f4: 0x8c637a50  lw          $v1, 0x7A50($v1)
    ctx->pc = 0x10b8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31312)));
    // 0x10b8f8: 0x600008  jr          $v1
    ctx->pc = 0x10B8F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B900u: goto label_10b900;
            case 0x10B908u: goto label_10b908;
            case 0x10B920u: goto label_10b920;
            case 0x10B928u: goto label_10b928;
            case 0x10BC84u: goto label_10bc84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B900u;
label_10b900:
    // 0x10b900: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10b900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10b904: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x10b904u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
label_10b908:
    // 0x10b908: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10b908u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10b90c: 0x82c20000  lb          $v0, 0x0($s6)
    ctx->pc = 0x10b90cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10b910: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10B910u;
    {
        const bool branch_taken_0x10b910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B910u;
            // 0x10b914: 0x92c40000  lbu         $a0, 0x0($s6) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b910) {
            ctx->pc = 0x10B928u;
            goto label_10b928;
        }
    }
    ctx->pc = 0x10B918u;
    // 0x10b918: 0x1000038b  b           . + 4 + (0x38B << 2)
    ctx->pc = 0x10B918u;
    {
        const bool branch_taken_0x10b918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B918u;
            // 0x10b91c: 0xa0b02d  daddu       $s6, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b918) {
            ctx->pc = 0x10C748u;
            goto label_10c748;
        }
    }
    ctx->pc = 0x10B920u;
label_10b920:
    // 0x10b920: 0x1000ffed  b           . + 4 + (-0x13 << 2)
    ctx->pc = 0x10B920u;
    {
        const bool branch_taken_0x10b920 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B920u;
            // 0x10b924: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b920) {
            ctx->pc = 0x10B8D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b8d8;
        }
    }
    ctx->pc = 0x10B928u;
label_10b928:
    // 0x10b928: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x10b928u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x10b92c: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x10b92cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10b930: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b930u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b934: 0x1443000b  bne         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x10B934u;
    {
        const bool branch_taken_0x10b934 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10B938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B934u;
            // 0x10b938: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b934) {
            ctx->pc = 0x10B964u;
            goto label_10b964;
        }
    }
    ctx->pc = 0x10B93Cu;
    // 0x10b93c: 0x240a0001  addiu       $t2, $zero, 0x1
    ctx->pc = 0x10b93cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_10b940:
    // 0x10b940: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10b940u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10b944: 0x82c20000  lb          $v0, 0x0($s6)
    ctx->pc = 0x10b944u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10b948: 0x0  nop
    ctx->pc = 0x10b948u;
    // NOP
    // 0x10b94c: 0x0  nop
    ctx->pc = 0x10b94cu;
    // NOP
    // 0x10b950: 0x0  nop
    ctx->pc = 0x10b950u;
    // NOP
    // 0x10b954: 0x1043fffa  beq         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10B954u;
    {
        const bool branch_taken_0x10b954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x10B958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B954u;
            // 0x10b958: 0x92c40000  lbu         $a0, 0x0($s6) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b954) {
            ctx->pc = 0x10B940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b940;
        }
    }
    ctx->pc = 0x10B95Cu;
    // 0x10b95c: 0x1040037a  beqz        $v0, . + 4 + (0x37A << 2)
    ctx->pc = 0x10B95Cu;
    {
        const bool branch_taken_0x10b95c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B95Cu;
            // 0x10b960: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b95c) {
            ctx->pc = 0x10C748u;
            goto label_10c748;
        }
    }
    ctx->pc = 0x10B964u;
label_10b964:
    // 0x10b964: 0xafb60018  sw          $s6, 0x18($sp)
    ctx->pc = 0x10b964u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 22));
    // 0x10b968: 0x22603  sra         $a0, $v0, 24
    ctx->pc = 0x10b968u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b96c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x10b96cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b970: 0x28820030  slti        $v0, $a0, 0x30
    ctx->pc = 0x10b970u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x10b974: 0xafa00020  sw          $zero, 0x20($sp)
    ctx->pc = 0x10b974u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x10b978: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x10b978u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b97c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x10B97Cu;
    {
        const bool branch_taken_0x10b97c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B97Cu;
            // 0x10b980: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b97c) {
            ctx->pc = 0x10B9DCu;
            goto label_10b9dc;
        }
    }
    ctx->pc = 0x10B984u;
    // 0x10b984: 0x0  nop
    ctx->pc = 0x10b984u;
    // NOP
label_10b988:
    // 0x10b988: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B988u;
    {
        const bool branch_taken_0x10b988 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B988u;
            // 0x10b98c: 0x2a420010  slti        $v0, $s2, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)16) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b988) {
            ctx->pc = 0x10B9B0u;
            goto label_10b9b0;
        }
    }
    ctx->pc = 0x10B990u;
    // 0x10b990: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x10b990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10b994: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x10b994u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x10b998: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10b998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10b99c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10b99cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10b9a0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10b9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10b9a4: 0x2442ffd0  addiu       $v0, $v0, -0x30
    ctx->pc = 0x10b9a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
    // 0x10b9a8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10B9A8u;
    {
        const bool branch_taken_0x10b9a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B9ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B9A8u;
            // 0x10b9ac: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b9a8) {
            ctx->pc = 0x10B9CCu;
            goto label_10b9cc;
        }
    }
    ctx->pc = 0x10B9B0u;
label_10b9b0:
    // 0x10b9b0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x10B9B0u;
    {
        const bool branch_taken_0x10b9b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10b9b0) {
            ctx->pc = 0x10B9B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B9B0u;
            // 0x10b9b4: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B9D0u;
            goto label_10b9d0;
        }
    }
    ctx->pc = 0x10B9B8u;
    // 0x10b9b8: 0x1110b8  dsll        $v0, $s1, 2
    ctx->pc = 0x10b9b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << 2);
    // 0x10b9bc: 0x51102d  daddu       $v0, $v0, $s1
    ctx->pc = 0x10b9bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 17));
    // 0x10b9c0: 0x21078  dsll        $v0, $v0, 1
    ctx->pc = 0x10b9c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 1);
    // 0x10b9c4: 0x82102d  daddu       $v0, $a0, $v0
    ctx->pc = 0x10b9c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 2));
    // 0x10b9c8: 0x6451ffd0  daddiu      $s1, $v0, -0x30
    ctx->pc = 0x10b9c8u;
    SET_GPR_S64(ctx, 17, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)4294967248);
label_10b9cc:
    // 0x10b9cc: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10b9ccu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
label_10b9d0:
    // 0x10b9d0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10b9d0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x10b9d4: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10b9d4u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10b9d8: 0x28820030  slti        $v0, $a0, 0x30
    ctx->pc = 0x10b9d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)48) ? 1 : 0);
label_10b9dc:
    // 0x10b9dc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10B9DCu;
    {
        const bool branch_taken_0x10b9dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B9E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B9DCu;
            // 0x10b9e0: 0x2402002e  addiu       $v0, $zero, 0x2E (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b9dc) {
            ctx->pc = 0x10B9F4u;
            goto label_10b9f4;
        }
    }
    ctx->pc = 0x10B9E4u;
    // 0x10b9e4: 0x2882003a  slti        $v0, $a0, 0x3A
    ctx->pc = 0x10b9e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)58) ? 1 : 0);
    // 0x10b9e8: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x10B9E8u;
    {
        const bool branch_taken_0x10b9e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B9E8u;
            // 0x10b9ec: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b9e8) {
            ctx->pc = 0x10B988u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b988;
        }
    }
    ctx->pc = 0x10B9F0u;
    // 0x10b9f0: 0x2402002e  addiu       $v0, $zero, 0x2E
    ctx->pc = 0x10b9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
label_10b9f4:
    // 0x10b9f4: 0x14820051  bne         $a0, $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x10B9F4u;
    {
        const bool branch_taken_0x10b9f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x10B9F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B9F4u;
            // 0x10b9f8: 0x240b82d  daddu       $s7, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b9f4) {
            ctx->pc = 0x10BB3Cu;
            goto label_10bb3c;
        }
    }
    ctx->pc = 0x10B9FCu;
    // 0x10b9fc: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10b9fcu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10ba00: 0x16400015  bnez        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x10BA00u;
    {
        const bool branch_taken_0x10ba00 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BA04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA00u;
            // 0x10ba04: 0x82c40000  lb          $a0, 0x0($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba00) {
            ctx->pc = 0x10BA58u;
            goto label_10ba58;
        }
    }
    ctx->pc = 0x10BA08u;
    // 0x10ba08: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10ba08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10ba0c: 0x5482000a  bnel        $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10BA0Cu;
    {
        const bool branch_taken_0x10ba0c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x10ba0c) {
            ctx->pc = 0x10BA10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA0Cu;
            // 0x10ba10: 0x2482ffcf  addiu       $v0, $a0, -0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967247));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BA38u;
            goto label_10ba38;
        }
    }
    ctx->pc = 0x10BA14u;
    // 0x10ba14: 0x0  nop
    ctx->pc = 0x10ba14u;
    // NOP
label_10ba18:
    // 0x10ba18: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10ba18u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10ba1c: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10ba1cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10ba20: 0x0  nop
    ctx->pc = 0x10ba20u;
    // NOP
    // 0x10ba24: 0x0  nop
    ctx->pc = 0x10ba24u;
    // NOP
    // 0x10ba28: 0x0  nop
    ctx->pc = 0x10ba28u;
    // NOP
    // 0x10ba2c: 0x1082fffa  beq         $a0, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10BA2Cu;
    {
        const bool branch_taken_0x10ba2c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x10BA30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA2Cu;
            // 0x10ba30: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba2c) {
            ctx->pc = 0x10BA18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ba18;
        }
    }
    ctx->pc = 0x10BA34u;
    // 0x10ba34: 0x2482ffcf  addiu       $v0, $a0, -0x31
    ctx->pc = 0x10ba34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967247));
label_10ba38:
    // 0x10ba38: 0x2c420009  sltiu       $v0, $v0, 0x9
    ctx->pc = 0x10ba38u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)9) ? 1 : 0);
    // 0x10ba3c: 0x10400040  beqz        $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x10BA3Cu;
    {
        const bool branch_taken_0x10ba3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA3Cu;
            // 0x10ba40: 0x24020065  addiu       $v0, $zero, 0x65 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba3c) {
            ctx->pc = 0x10BB40u;
            goto label_10bb40;
        }
    }
    ctx->pc = 0x10BA44u;
    // 0x10ba44: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x10ba44u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ba48: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x10ba48u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ba4c: 0x2486ffd0  addiu       $a2, $a0, -0x30
    ctx->pc = 0x10ba4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x10ba50: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10BA50u;
    {
        const bool branch_taken_0x10ba50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA50u;
            // 0x10ba54: 0xafb60018  sw          $s6, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba50) {
            ctx->pc = 0x10BA68u;
            goto label_10ba68;
        }
    }
    ctx->pc = 0x10BA58u;
label_10ba58:
    // 0x10ba58: 0x2486ffd0  addiu       $a2, $a0, -0x30
    ctx->pc = 0x10ba58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x10ba5c: 0x2cc2000a  sltiu       $v0, $a2, 0xA
    ctx->pc = 0x10ba5cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10ba60: 0x10400037  beqz        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x10BA60u;
    {
        const bool branch_taken_0x10ba60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA60u;
            // 0x10ba64: 0x24020065  addiu       $v0, $zero, 0x65 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba60) {
            ctx->pc = 0x10BB40u;
            goto label_10bb40;
        }
    }
    ctx->pc = 0x10BA68u;
label_10ba68:
    // 0x10ba68: 0x10c0002d  beqz        $a2, . + 4 + (0x2D << 2)
    ctx->pc = 0x10BA68u;
    {
        const bool branch_taken_0x10ba68 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA68u;
            // 0x10ba6c: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba68) {
            ctx->pc = 0x10BB20u;
            goto label_10bb20;
        }
    }
    ctx->pc = 0x10BA70u;
    // 0x10ba70: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x10ba70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10ba74: 0x87102a  slt         $v0, $a0, $a3
    ctx->pc = 0x10ba74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x10ba78: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x10BA78u;
    {
        const bool branch_taken_0x10ba78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA78u;
            // 0x10ba7c: 0x1074021  addu        $t0, $t0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba78) {
            ctx->pc = 0x10BAD4u;
            goto label_10bad4;
        }
    }
    ctx->pc = 0x10BA80u;
    // 0x10ba80: 0x24e4ffff  addiu       $a0, $a3, -0x1
    ctx->pc = 0x10ba80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10ba84: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x10ba84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_10ba88:
    // 0x10ba88: 0x28420009  slti        $v0, $v0, 0x9
    ctx->pc = 0x10ba88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x10ba8c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10BA8Cu;
    {
        const bool branch_taken_0x10ba8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BA8Cu;
            // 0x10ba90: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ba8c) {
            ctx->pc = 0x10BAB0u;
            goto label_10bab0;
        }
    }
    ctx->pc = 0x10BA94u;
    // 0x10ba94: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x10ba94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10ba98: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x10ba98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x10ba9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10ba9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10baa0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10baa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10baa4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10BAA4u;
    {
        const bool branch_taken_0x10baa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BAA4u;
            // 0x10baa8: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10baa4) {
            ctx->pc = 0x10BAC8u;
            goto label_10bac8;
        }
    }
    ctx->pc = 0x10BAACu;
    // 0x10baac: 0x0  nop
    ctx->pc = 0x10baacu;
    // NOP
label_10bab0:
    // 0x10bab0: 0x2a420011  slti        $v0, $s2, 0x11
    ctx->pc = 0x10bab0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10bab4: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10BAB4u;
    {
        const bool branch_taken_0x10bab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bab4) {
            ctx->pc = 0x10BAB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BAB4u;
            // 0x10bab8: 0x2484ffff  addiu       $a0, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BACCu;
            goto label_10bacc;
        }
    }
    ctx->pc = 0x10BABCu;
    // 0x10babc: 0x1110b8  dsll        $v0, $s1, 2
    ctx->pc = 0x10babcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << 2);
    // 0x10bac0: 0x51102d  daddu       $v0, $v0, $s1
    ctx->pc = 0x10bac0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 17));
    // 0x10bac4: 0x28878  dsll        $s1, $v0, 1
    ctx->pc = 0x10bac4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << 1);
label_10bac8:
    // 0x10bac8: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x10bac8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_10bacc:
    // 0x10bacc: 0x1480ffee  bnez        $a0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x10BACCu;
    {
        const bool branch_taken_0x10bacc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BACCu;
            // 0x10bad0: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bacc) {
            ctx->pc = 0x10BA88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ba88;
        }
    }
    ctx->pc = 0x10BAD4u;
label_10bad4:
    // 0x10bad4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x10bad4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bad8: 0x28420009  slti        $v0, $v0, 0x9
    ctx->pc = 0x10bad8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x10badc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10BADCu;
    {
        const bool branch_taken_0x10badc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BADCu;
            // 0x10bae0: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10badc) {
            ctx->pc = 0x10BB00u;
            goto label_10bb00;
        }
    }
    ctx->pc = 0x10BAE4u;
    // 0x10bae4: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x10bae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10bae8: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x10bae8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x10baec: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10baecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10baf0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10baf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10baf4: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x10baf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x10baf8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10BAF8u;
    {
        const bool branch_taken_0x10baf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BAF8u;
            // 0x10bafc: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10baf8) {
            ctx->pc = 0x10BB1Cu;
            goto label_10bb1c;
        }
    }
    ctx->pc = 0x10BB00u;
label_10bb00:
    // 0x10bb00: 0x2a420011  slti        $v0, $s2, 0x11
    ctx->pc = 0x10bb00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10bb04: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BB04u;
    {
        const bool branch_taken_0x10bb04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB04u;
            // 0x10bb08: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bb04) {
            ctx->pc = 0x10BB20u;
            goto label_10bb20;
        }
    }
    ctx->pc = 0x10BB0Cu;
    // 0x10bb0c: 0x1110b8  dsll        $v0, $s1, 2
    ctx->pc = 0x10bb0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << 2);
    // 0x10bb10: 0x51102d  daddu       $v0, $v0, $s1
    ctx->pc = 0x10bb10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 17));
    // 0x10bb14: 0x21078  dsll        $v0, $v0, 1
    ctx->pc = 0x10bb14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 1);
    // 0x10bb18: 0xc2882d  daddu       $s1, $a2, $v0
    ctx->pc = 0x10bb18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 2));
label_10bb1c:
    // 0x10bb1c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x10bb1cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10bb20:
    // 0x10bb20: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bb20u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bb24: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bb24u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bb28: 0x2482ffd0  addiu       $v0, $a0, -0x30
    ctx->pc = 0x10bb28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x10bb2c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x10bb2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bb30: 0x2cc3000a  sltiu       $v1, $a2, 0xA
    ctx->pc = 0x10bb30u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10bb34: 0x1460ffcc  bnez        $v1, . + 4 + (-0x34 << 2)
    ctx->pc = 0x10BB34u;
    {
        const bool branch_taken_0x10bb34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bb34) {
            ctx->pc = 0x10BA68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ba68;
        }
    }
    ctx->pc = 0x10BB3Cu;
label_10bb3c:
    // 0x10bb3c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x10bb3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
label_10bb40:
    // 0x10bb40: 0x10820004  beq         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10BB40u;
    {
        const bool branch_taken_0x10bb40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x10BB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB40u;
            // 0x10bb44: 0xffa00010  sd          $zero, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bb40) {
            ctx->pc = 0x10BB54u;
            goto label_10bb54;
        }
    }
    ctx->pc = 0x10BB48u;
    // 0x10bb48: 0x24020045  addiu       $v0, $zero, 0x45
    ctx->pc = 0x10bb48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x10bb4c: 0x14820047  bne         $a0, $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x10BB4Cu;
    {
        const bool branch_taken_0x10bb4c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x10bb4c) {
            ctx->pc = 0x10BC6Cu;
            goto label_10bc6c;
        }
    }
    ctx->pc = 0x10BB54u;
label_10bb54:
    // 0x10bb54: 0x56400006  bnel        $s2, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BB54u;
    {
        const bool branch_taken_0x10bb54 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bb54) {
            ctx->pc = 0x10BB58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB54u;
            // 0x10bb58: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BB70u;
            goto label_10bb70;
        }
    }
    ctx->pc = 0x10BB5Cu;
    // 0x10bb5c: 0x54e00004  bnel        $a3, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10BB5Cu;
    {
        const bool branch_taken_0x10bb5c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bb5c) {
            ctx->pc = 0x10BB60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB5Cu;
            // 0x10bb60: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BB70u;
            goto label_10bb70;
        }
    }
    ctx->pc = 0x10BB64u;
    // 0x10bb64: 0x514002f8  beql        $t2, $zero, . + 4 + (0x2F8 << 2)
    ctx->pc = 0x10BB64u;
    {
        const bool branch_taken_0x10bb64 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bb64) {
            ctx->pc = 0x10BB68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB64u;
            // 0x10bb68: 0xa0b02d  daddu       $s6, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C748u;
            goto label_10c748;
        }
    }
    ctx->pc = 0x10BB6Cu;
    // 0x10bb6c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x10bb6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_10bb70:
    // 0x10bb70: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bb70u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bb74: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bb74u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bb78: 0x2402002b  addiu       $v0, $zero, 0x2B
    ctx->pc = 0x10bb78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x10bb7c: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10BB7Cu;
    {
        const bool branch_taken_0x10bb7c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x10BB80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB7Cu;
            // 0x10bb80: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bb7c) {
            ctx->pc = 0x10BB94u;
            goto label_10bb94;
        }
    }
    ctx->pc = 0x10BB84u;
    // 0x10bb84: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10bb84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10bb88: 0x14820005  bne         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10BB88u;
    {
        const bool branch_taken_0x10bb88 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x10BB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BB88u;
            // 0x10bb8c: 0x2482ffd0  addiu       $v0, $a0, -0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bb88) {
            ctx->pc = 0x10BBA0u;
            goto label_10bba0;
        }
    }
    ctx->pc = 0x10BB90u;
    // 0x10bb90: 0x24090001  addiu       $t1, $zero, 0x1
    ctx->pc = 0x10bb90u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_10bb94:
    // 0x10bb94: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bb94u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bb98: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bb98u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bb9c: 0x2482ffd0  addiu       $v0, $a0, -0x30
    ctx->pc = 0x10bb9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
label_10bba0:
    // 0x10bba0: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x10bba0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10bba4: 0x50400031  beql        $v0, $zero, . + 4 + (0x31 << 2)
    ctx->pc = 0x10BBA4u;
    {
        const bool branch_taken_0x10bba4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bba4) {
            ctx->pc = 0x10BBA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BBA4u;
            // 0x10bba8: 0xa0b02d  daddu       $s6, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BC6Cu;
            goto label_10bc6c;
        }
    }
    ctx->pc = 0x10BBACu;
    // 0x10bbac: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10bbacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10bbb0: 0x5482000b  bnel        $a0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10BBB0u;
    {
        const bool branch_taken_0x10bbb0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x10bbb0) {
            ctx->pc = 0x10BBB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BBB0u;
            // 0x10bbb4: 0x2482ffcf  addiu       $v0, $a0, -0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967247));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BBE0u;
            goto label_10bbe0;
        }
    }
    ctx->pc = 0x10BBB8u;
    // 0x10bbb8: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bbb8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bbbc: 0x0  nop
    ctx->pc = 0x10bbbcu;
    // NOP
label_10bbc0:
    // 0x10bbc0: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bbc0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bbc4: 0x0  nop
    ctx->pc = 0x10bbc4u;
    // NOP
    // 0x10bbc8: 0x0  nop
    ctx->pc = 0x10bbc8u;
    // NOP
    // 0x10bbcc: 0x0  nop
    ctx->pc = 0x10bbccu;
    // NOP
    // 0x10bbd0: 0x0  nop
    ctx->pc = 0x10bbd0u;
    // NOP
    // 0x10bbd4: 0x5082fffa  beql        $a0, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10BBD4u;
    {
        const bool branch_taken_0x10bbd4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x10bbd4) {
            ctx->pc = 0x10BBD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BBD4u;
            // 0x10bbd8: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BBC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bbc0;
        }
    }
    ctx->pc = 0x10BBDCu;
    // 0x10bbdc: 0x2482ffcf  addiu       $v0, $a0, -0x31
    ctx->pc = 0x10bbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967247));
label_10bbe0:
    // 0x10bbe0: 0x2c420009  sltiu       $v0, $v0, 0x9
    ctx->pc = 0x10bbe0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)9) ? 1 : 0);
    // 0x10bbe4: 0x50400021  beql        $v0, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x10BBE4u;
    {
        const bool branch_taken_0x10bbe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bbe4) {
            ctx->pc = 0x10BBE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BBE4u;
            // 0x10bbe8: 0xffa00010  sd          $zero, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BC6Cu;
            goto label_10bc6c;
        }
    }
    ctx->pc = 0x10BBECu;
    // 0x10bbec: 0x2484ffd0  addiu       $a0, $a0, -0x30
    ctx->pc = 0x10bbecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x10bbf0: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x10bbf0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bbf4: 0xffa40010  sd          $a0, 0x10($sp)
    ctx->pc = 0x10bbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
    // 0x10bbf8: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bbf8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bbfc: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bbfcu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bc00: 0x28820030  slti        $v0, $a0, 0x30
    ctx->pc = 0x10bc00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x10bc04: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x10BC04u;
    {
        const bool branch_taken_0x10bc04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bc04) {
            ctx->pc = 0x10BC08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC04u;
            // 0x10bc08: 0xdfa40010  ld          $a0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BC48u;
            goto label_10bc48;
        }
    }
    ctx->pc = 0x10BC0Cu;
label_10bc0c:
    // 0x10bc0c: 0x2882003a  slti        $v0, $a0, 0x3A
    ctx->pc = 0x10bc0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)58) ? 1 : 0);
    // 0x10bc10: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x10BC10u;
    {
        const bool branch_taken_0x10bc10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bc10) {
            ctx->pc = 0x10BC14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC10u;
            // 0x10bc14: 0xdfa40010  ld          $a0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BC48u;
            goto label_10bc48;
        }
    }
    ctx->pc = 0x10BC18u;
    // 0x10bc18: 0xdfa30010  ld          $v1, 0x10($sp)
    ctx->pc = 0x10bc18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10bc1c: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x10bc1cu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x10bc20: 0x310b8  dsll        $v0, $v1, 2
    ctx->pc = 0x10bc20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << 2);
    // 0x10bc24: 0x43102d  daddu       $v0, $v0, $v1
    ctx->pc = 0x10bc24u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x10bc28: 0x21078  dsll        $v0, $v0, 1
    ctx->pc = 0x10bc28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 1);
    // 0x10bc2c: 0x82102d  daddu       $v0, $a0, $v0
    ctx->pc = 0x10bc2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 2));
    // 0x10bc30: 0x82c40000  lb          $a0, 0x0($s6)
    ctx->pc = 0x10bc30u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10bc34: 0x6442ffd0  daddiu      $v0, $v0, -0x30
    ctx->pc = 0x10bc34u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)4294967248);
    // 0x10bc38: 0x28830030  slti        $v1, $a0, 0x30
    ctx->pc = 0x10bc38u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x10bc3c: 0x1060fff3  beqz        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x10BC3Cu;
    {
        const bool branch_taken_0x10bc3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BC40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC3Cu;
            // 0x10bc40: 0xffa20010  sd          $v0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bc3c) {
            ctx->pc = 0x10BC0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bc0c;
        }
    }
    ctx->pc = 0x10BC44u;
    // 0x10bc44: 0xdfa40010  ld          $a0, 0x10($sp)
    ctx->pc = 0x10bc44u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10bc48:
    // 0x10bc48: 0x2c61023  subu        $v0, $s6, $a2
    ctx->pc = 0x10bc48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 6)));
    // 0x10bc4c: 0x3c030098  lui         $v1, 0x98
    ctx->pc = 0x10bc4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)152 << 16));
    // 0x10bc50: 0x3463967f  ori         $v1, $v1, 0x967F
    ctx->pc = 0x10bc50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)38527);
    // 0x10bc54: 0x28420009  slti        $v0, $v0, 0x9
    ctx->pc = 0x10bc54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x10bc58: 0x62200a  movz        $a0, $v1, $v0
    ctx->pc = 0x10bc58u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x10bc5c: 0x11200003  beqz        $t1, . + 4 + (0x3 << 2)
    ctx->pc = 0x10BC5Cu;
    {
        const bool branch_taken_0x10bc5c = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC5Cu;
            // 0x10bc60: 0xffa40010  sd          $a0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bc5c) {
            ctx->pc = 0x10BC6Cu;
            goto label_10bc6c;
        }
    }
    ctx->pc = 0x10BC64u;
    // 0x10bc64: 0x4202f  dsubu       $a0, $zero, $a0
    ctx->pc = 0x10bc64u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) - GPR_U64(ctx, 4));
    // 0x10bc68: 0xffa40010  sd          $a0, 0x10($sp)
    ctx->pc = 0x10bc68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
label_10bc6c:
    // 0x10bc6c: 0x16400008  bnez        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x10BC6Cu;
    {
        const bool branch_taken_0x10bc6c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BC70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC6Cu;
            // 0x10bc70: 0xdfa20010  ld          $v0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bc6c) {
            ctx->pc = 0x10BC90u;
            goto label_10bc90;
        }
    }
    ctx->pc = 0x10BC74u;
    // 0x10bc74: 0x14e002b5  bnez        $a3, . + 4 + (0x2B5 << 2)
    ctx->pc = 0x10BC74u;
    {
        const bool branch_taken_0x10bc74 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BC78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC74u;
            // 0x10bc78: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bc74) {
            ctx->pc = 0x10C74Cu;
            goto label_10c74c;
        }
    }
    ctx->pc = 0x10BC7Cu;
    // 0x10bc7c: 0x154002b3  bnez        $t2, . + 4 + (0x2B3 << 2)
    ctx->pc = 0x10BC7Cu;
    {
        const bool branch_taken_0x10bc7c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bc7c) {
            ctx->pc = 0x10C74Cu;
            goto label_10c74c;
        }
    }
    ctx->pc = 0x10BC84u;
label_10bc84:
    // 0x10bc84: 0x100002b0  b           . + 4 + (0x2B0 << 2)
    ctx->pc = 0x10BC84u;
    {
        const bool branch_taken_0x10bc84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BC84u;
            // 0x10bc88: 0xa0b02d  daddu       $s6, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bc84) {
            ctx->pc = 0x10C748u;
            goto label_10c748;
        }
    }
    ctx->pc = 0x10BC8Cu;
    // 0x10bc8c: 0x0  nop
    ctx->pc = 0x10bc8cu;
    // NOP
label_10bc90:
    // 0x10bc90: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10bc90u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10bc94: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x10bc94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10bc98: 0x257b80a  movz        $s7, $s2, $s7
    ctx->pc = 0x10bc98u;
    if (GPR_U64(ctx, 23) == 0) SET_GPR_VEC(ctx, 23, GPR_VEC(ctx, 18));
    // 0x10bc9c: 0x48102f  dsubu       $v0, $v0, $t0
    ctx->pc = 0x10bc9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 8));
    // 0x10bca0: 0xffa20010  sd          $v0, 0x10($sp)
    ctx->pc = 0x10bca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
    // 0x10bca4: 0x2a420011  slti        $v0, $s2, 0x11
    ctx->pc = 0x10bca4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10bca8: 0x242a00b  movn        $s4, $s2, $v0
    ctx->pc = 0x10bca8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 18));
    // 0x10bcac: 0xdfa30010  ld          $v1, 0x10($sp)
    ctx->pc = 0x10bcacu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10bcb0: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10bcb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10bcb4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x10bcb4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x10bcb8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x10BCB8u;
    SET_GPR_U32(ctx, 31, 0x10BCC0u);
    ctx->pc = 0x10BCBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10BCB8u;
            // 0x10bcbc: 0xafa30048  sw          $v1, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BCC0u; }
        if (ctx->pc != 0x10BCC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BCC0u; }
        if (ctx->pc != 0x10BCC0u) { return; }
    }
    ctx->pc = 0x10BCC0u;
label_10bcc0:
    // 0x10bcc0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10bcc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bcc4: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x10bcc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10bcc8: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BCC8u;
    {
        const bool branch_taken_0x10bcc8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10BCCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BCC8u;
            // 0x10bccc: 0x8fb00048  lw          $s0, 0x48($sp) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bcc8) {
            ctx->pc = 0x10BCE4u;
            goto label_10bce4;
        }
    }
    ctx->pc = 0x10BCD0u;
    // 0x10bcd0: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x10bcd0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x10bcd4: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x10bcd4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x10bcd8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10BCD8u;
    SET_GPR_U32(ctx, 31, 0x10BCE0u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BCE0u; }
        if (ctx->pc != 0x10BCE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BCE0u; }
        if (ctx->pc != 0x10BCE0u) { return; }
    }
    ctx->pc = 0x10BCE0u;
label_10bce0:
    // 0x10bce0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10bce0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10bce4:
    // 0x10bce4: 0x2a82000a  slti        $v0, $s4, 0xA
    ctx->pc = 0x10bce4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x10bce8: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x10bce8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bcec: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x10BCECu;
    {
        const bool branch_taken_0x10bcec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BCF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BCECu;
            // 0x10bcf0: 0x2541023  subu        $v0, $s2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bcec) {
            ctx->pc = 0x10BD64u;
            goto label_10bd64;
        }
    }
    ctx->pc = 0x10BCF4u;
    // 0x10bcf4: 0x1410c0  sll         $v0, $s4, 3
    ctx->pc = 0x10bcf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x10bcf8: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10bcf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bcfc: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10bcfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10bd00: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x10bd00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x10bd04: 0xdc8478e0  ld          $a0, 0x78E0($a0)
    ctx->pc = 0x10bd04u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 30944)));
    // 0x10bd08: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BD08u;
    SET_GPR_U32(ctx, 31, 0x10BD10u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD10u; }
        if (ctx->pc != 0x10BD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD10u; }
        if (ctx->pc != 0x10BD10u) { return; }
    }
    ctx->pc = 0x10BD10u;
label_10bd10:
    // 0x10bd10: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bd10u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd14: 0x6220006  bltzl       $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BD14u;
    {
        const bool branch_taken_0x10bd14 = (GPR_S64(ctx, 17) < 0);
        if (branch_taken_0x10bd14) {
            ctx->pc = 0x10BD18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BD14u;
            // 0x10bd18: 0x11107a  dsrl        $v0, $s1, 1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) >> 1);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BD30u;
            goto label_10bd30;
        }
    }
    ctx->pc = 0x10BD1Cu;
    // 0x10bd1c: 0xc0444ca  jal         func_111328
    ctx->pc = 0x10BD1Cu;
    SET_GPR_U32(ctx, 31, 0x10BD24u);
    ctx->pc = 0x10BD20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10BD1Cu;
            // 0x10bd20: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD24u; }
        if (ctx->pc != 0x10BD24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD24u; }
        if (ctx->pc != 0x10BD24u) { return; }
    }
    ctx->pc = 0x10BD24u;
label_10bd24:
    // 0x10bd24: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x10BD24u;
    {
        const bool branch_taken_0x10bd24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10bd24) {
            ctx->pc = 0x10BD4Cu;
            goto label_10bd4c;
        }
    }
    ctx->pc = 0x10BD2Cu;
    // 0x10bd2c: 0x0  nop
    ctx->pc = 0x10bd2cu;
    // NOP
label_10bd30:
    // 0x10bd30: 0x32240001  andi        $a0, $s1, 0x1
    ctx->pc = 0x10bd30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x10bd34: 0xc0444ca  jal         func_111328
    ctx->pc = 0x10BD34u;
    SET_GPR_U32(ctx, 31, 0x10BD3Cu);
    ctx->pc = 0x10BD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10BD34u;
            // 0x10bd38: 0x822025  or          $a0, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD3Cu; }
        if (ctx->pc != 0x10BD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD3Cu; }
        if (ctx->pc != 0x10BD3Cu) { return; }
    }
    ctx->pc = 0x10BD3Cu;
label_10bd3c:
    // 0x10bd3c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10bd3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd40: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10bd40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd44: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10BD44u;
    SET_GPR_U32(ctx, 31, 0x10BD4Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD4Cu; }
        if (ctx->pc != 0x10BD4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD4Cu; }
        if (ctx->pc != 0x10BD4Cu) { return; }
    }
    ctx->pc = 0x10BD4Cu;
label_10bd4c:
    // 0x10bd4c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10bd4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd50: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10bd50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd54: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10BD54u;
    SET_GPR_U32(ctx, 31, 0x10BD5Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD5Cu; }
        if (ctx->pc != 0x10BD5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD5Cu; }
        if (ctx->pc != 0x10BD5Cu) { return; }
    }
    ctx->pc = 0x10BD5Cu;
label_10bd5c:
    // 0x10bd5c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bd5cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd60: 0x2541023  subu        $v0, $s2, $s4
    ctx->pc = 0x10bd60u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
label_10bd64:
    // 0x10bd64: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x10bd64u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x10bd68: 0x1a000055  blez        $s0, . + 4 + (0x55 << 2)
    ctx->pc = 0x10BD68u;
    {
        const bool branch_taken_0x10bd68 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10BD6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BD68u;
            // 0x10bd6c: 0xafa00038  sw          $zero, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bd68) {
            ctx->pc = 0x10BEC0u;
            goto label_10bec0;
        }
    }
    ctx->pc = 0x10BD70u;
    // 0x10bd70: 0x3204000f  andi        $a0, $s0, 0xF
    ctx->pc = 0x10bd70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
    // 0x10bd74: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10BD74u;
    {
        const bool branch_taken_0x10bd74 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BD74u;
            // 0x10bd78: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bd74) {
            ctx->pc = 0x10BD98u;
            goto label_10bd98;
        }
    }
    ctx->pc = 0x10BD7Cu;
    // 0x10bd7c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10bd7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bd80: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10bd80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10bd84: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x10bd84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x10bd88: 0xdc847928  ld          $a0, 0x7928($a0)
    ctx->pc = 0x10bd88u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 31016)));
    // 0x10bd8c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BD8Cu;
    SET_GPR_U32(ctx, 31, 0x10BD94u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD94u; }
        if (ctx->pc != 0x10BD94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BD94u; }
        if (ctx->pc != 0x10BD94u) { return; }
    }
    ctx->pc = 0x10BD94u;
label_10bd94:
    // 0x10bd94: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bd94u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10bd98:
    // 0x10bd98: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x10bd98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x10bd9c: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x10bd9cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x10bda0: 0x120000a1  beqz        $s0, . + 4 + (0xA1 << 2)
    ctx->pc = 0x10BDA0u;
    {
        const bool branch_taken_0x10bda0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BDA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDA0u;
            // 0x10bda4: 0x2a020135  slti        $v0, $s0, 0x135 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)309) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bda0) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BDA8u;
    // 0x10bda8: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x10BDA8u;
    {
        const bool branch_taken_0x10bda8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10bda8) {
            ctx->pc = 0x10BDACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDA8u;
            // 0x10bdac: 0x108103  sra         $s0, $s0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10BDD8u;
            goto label_10bdd8;
        }
    }
    ctx->pc = 0x10BDB0u;
    // 0x10bdb0: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x10bdb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
label_10bdb4:
    // 0x10bdb4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10bdb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10bdb8: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x10bdb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x10bdbc: 0xdc737a40  ld          $s3, 0x7A40($v1)
    ctx->pc = 0x10bdbcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 3), 31296)));
    // 0x10bdc0: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x10bdc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10bdc4: 0x10600261  beqz        $v1, . + 4 + (0x261 << 2)
    ctx->pc = 0x10BDC4u;
    {
        const bool branch_taken_0x10bdc4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDC4u;
            // 0x10bdc8: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bdc4) {
            ctx->pc = 0x10C74Cu;
            goto label_10c74c;
        }
    }
    ctx->pc = 0x10BDCCu;
    // 0x10bdcc: 0x10000250  b           . + 4 + (0x250 << 2)
    ctx->pc = 0x10BDCCu;
    {
        const bool branch_taken_0x10bdcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDCCu;
            // 0x10bdd0: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bdcc) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10BDD4u;
    // 0x10bdd4: 0x0  nop
    ctx->pc = 0x10bdd4u;
    // NOP
label_10bdd8:
    // 0x10bdd8: 0x12000093  beqz        $s0, . + 4 + (0x93 << 2)
    ctx->pc = 0x10BDD8u;
    {
        const bool branch_taken_0x10bdd8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BDDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDD8u;
            // 0x10bddc: 0x2a020002  slti        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bdd8) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BDE0u;
    // 0x10bde0: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x10BDE0u;
    {
        const bool branch_taken_0x10bde0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDE0u;
            // 0x10bde4: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bde0) {
            ctx->pc = 0x10BE28u;
            goto label_10be28;
        }
    }
    ctx->pc = 0x10BDE8u;
    // 0x10bde8: 0x3c150023  lui         $s5, 0x23
    ctx->pc = 0x10bde8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)35 << 16));
    // 0x10bdec: 0x26b179f0  addiu       $s1, $s5, 0x79F0
    ctx->pc = 0x10bdecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 31216));
label_10bdf0:
    // 0x10bdf0: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x10bdf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x10bdf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BDF4u;
    {
        const bool branch_taken_0x10bdf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BDF4u;
            // 0x10bdf8: 0x108043  sra         $s0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bdf4) {
            ctx->pc = 0x10BE10u;
            goto label_10be10;
        }
    }
    ctx->pc = 0x10BDFCu;
    // 0x10bdfc: 0xde240000  ld          $a0, 0x0($s1)
    ctx->pc = 0x10bdfcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x10be00: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10be00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10be04: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BE04u;
    SET_GPR_U32(ctx, 31, 0x10BE0Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BE0Cu; }
        if (ctx->pc != 0x10BE0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BE0Cu; }
        if (ctx->pc != 0x10BE0Cu) { return; }
    }
    ctx->pc = 0x10BE0Cu;
label_10be0c:
    // 0x10be0c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10be0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10be10:
    // 0x10be10: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x10be10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x10be14: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x10be14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10be18: 0x1040fff5  beqz        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x10BE18u;
    {
        const bool branch_taken_0x10be18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BE18u;
            // 0x10be1c: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10be18) {
            ctx->pc = 0x10BDF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bdf0;
        }
    }
    ctx->pc = 0x10BE20u;
    // 0x10be20: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10BE20u;
    {
        const bool branch_taken_0x10be20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BE20u;
            // 0x10be24: 0x26a479f0  addiu       $a0, $s5, 0x79F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 31216));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10be20) {
            ctx->pc = 0x10BE30u;
            goto label_10be30;
        }
    }
    ctx->pc = 0x10BE28u;
label_10be28:
    // 0x10be28: 0x3c150023  lui         $s5, 0x23
    ctx->pc = 0x10be28u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)35 << 16));
    // 0x10be2c: 0x26a479f0  addiu       $a0, $s5, 0x79F0
    ctx->pc = 0x10be2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 31216));
label_10be30:
    // 0x10be30: 0x13283f  dsra32      $a1, $s3, 0
    ctx->pc = 0x10be30u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10be34: 0x3c02fcb0  lui         $v0, 0xFCB0
    ctx->pc = 0x10be34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64688 << 16));
    // 0x10be38: 0x1418c0  sll         $v1, $s4, 3
    ctx->pc = 0x10be38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x10be3c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10be3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10be40: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x10be40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x10be44: 0x3c10ffff  lui         $s0, 0xFFFF
    ctx->pc = 0x10be44u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)65535 << 16));
    // 0x10be48: 0x10803e  dsrl32      $s0, $s0, 0
    ctx->pc = 0x10be48u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    // 0x10be4c: 0xdc640000  ld          $a0, 0x0($v1)
    ctx->pc = 0x10be4cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10be50: 0x2709824  and         $s3, $s3, $s0
    ctx->pc = 0x10be50u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 16));
    // 0x10be54: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x10be54u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10be58: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BE58u;
    SET_GPR_U32(ctx, 31, 0x10BE60u);
    ctx->pc = 0x10BE5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10BE58u;
            // 0x10be5c: 0x2652825  or          $a1, $s3, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BE60u; }
        if (ctx->pc != 0x10BE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BE60u; }
        if (ctx->pc != 0x10BE60u) { return; }
    }
    ctx->pc = 0x10BE60u;
label_10be60:
    // 0x10be60: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x10be60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x10be64: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10be64u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10be68: 0x3c027ca0  lui         $v0, 0x7CA0
    ctx->pc = 0x10be68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)31904 << 16));
    // 0x10be6c: 0x13203f  dsra32      $a0, $s3, 0
    ctx->pc = 0x10be6cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10be70: 0x838824  and         $s1, $a0, $v1
    ctx->pc = 0x10be70u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x10be74: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x10be74u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x10be78: 0x1440ffce  bnez        $v0, . + 4 + (-0x32 << 2)
    ctx->pc = 0x10BE78u;
    {
        const bool branch_taken_0x10be78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BE7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BE78u;
            // 0x10be7c: 0x24020022  addiu       $v0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10be78) {
            ctx->pc = 0x10BDB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bdb4;
        }
    }
    ctx->pc = 0x10BE80u;
    // 0x10be80: 0x3c027c90  lui         $v0, 0x7C90
    ctx->pc = 0x10be80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)31888 << 16));
    // 0x10be84: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x10be84u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x10be88: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10BE88u;
    {
        const bool branch_taken_0x10be88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BE88u;
            // 0x10be8c: 0x2709824  and         $s3, $s3, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10be88) {
            ctx->pc = 0x10BEA8u;
            goto label_10bea8;
        }
    }
    ctx->pc = 0x10BE90u;
    // 0x10be90: 0x3c027fef  lui         $v0, 0x7FEF
    ctx->pc = 0x10be90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32751 << 16));
    // 0x10be94: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10be94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10be98: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10be98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10be9c: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x10be9cu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x10bea0: 0x10000061  b           . + 4 + (0x61 << 2)
    ctx->pc = 0x10BEA0u;
    {
        const bool branch_taken_0x10bea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BEA0u;
            // 0x10bea4: 0x2709825  or          $s3, $s3, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bea0) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BEA8u;
label_10bea8:
    // 0x10bea8: 0x3c020350  lui         $v0, 0x350
    ctx->pc = 0x10bea8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)848 << 16));
    // 0x10beac: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10beacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10beb0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10beb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10beb4: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x10BEB4u;
    {
        const bool branch_taken_0x10beb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BEB4u;
            // 0x10beb8: 0x2629825  or          $s3, $s3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10beb4) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BEBCu;
    // 0x10bebc: 0x0  nop
    ctx->pc = 0x10bebcu;
    // NOP
label_10bec0:
    // 0x10bec0: 0x601005a  bgez        $s0, . + 4 + (0x5A << 2)
    ctx->pc = 0x10BEC0u;
    {
        const bool branch_taken_0x10bec0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x10BEC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BEC0u;
            // 0x10bec4: 0x8fa50018  lw          $a1, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bec0) {
            ctx->pc = 0x10C02Cu;
            goto label_10c02c;
        }
    }
    ctx->pc = 0x10BEC8u;
    // 0x10bec8: 0x108023  negu        $s0, $s0
    ctx->pc = 0x10bec8u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 16)));
    // 0x10becc: 0x3204000f  andi        $a0, $s0, 0xF
    ctx->pc = 0x10beccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
    // 0x10bed0: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10BED0u;
    {
        const bool branch_taken_0x10bed0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BED0u;
            // 0x10bed4: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bed0) {
            ctx->pc = 0x10BEF4u;
            goto label_10bef4;
        }
    }
    ctx->pc = 0x10BED8u;
    // 0x10bed8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10bed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bedc: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x10bedcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x10bee0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x10bee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x10bee4: 0xdca57928  ld          $a1, 0x7928($a1)
    ctx->pc = 0x10bee4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 5), 31016)));
    // 0x10bee8: 0xc04480e  jal         func_112038
    ctx->pc = 0x10BEE8u;
    SET_GPR_U32(ctx, 31, 0x10BEF0u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BEF0u; }
        if (ctx->pc != 0x10BEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BEF0u; }
        if (ctx->pc != 0x10BEF0u) { return; }
    }
    ctx->pc = 0x10BEF0u;
label_10bef0:
    // 0x10bef0: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bef0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10bef4:
    // 0x10bef4: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x10bef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x10bef8: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x10bef8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x10befc: 0x1200004a  beqz        $s0, . + 4 + (0x4A << 2)
    ctx->pc = 0x10BEFCu;
    {
        const bool branch_taken_0x10befc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BEFCu;
            // 0x10bf00: 0x108103  sra         $s0, $s0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10befc) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BF04u;
    // 0x10bf04: 0x2a020020  slti        $v0, $s0, 0x20
    ctx->pc = 0x10bf04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x10bf08: 0x10400036  beqz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x10BF08u;
    {
        const bool branch_taken_0x10bf08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BF08u;
            // 0x10bf0c: 0x24020022  addiu       $v0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bf08) {
            ctx->pc = 0x10BFE4u;
            goto label_10bfe4;
        }
    }
    ctx->pc = 0x10BF10u;
    // 0x10bf10: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x10bf10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10bf14: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x10BF14u;
    {
        const bool branch_taken_0x10bf14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BF14u;
            // 0x10bf18: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bf14) {
            ctx->pc = 0x10BF60u;
            goto label_10bf60;
        }
    }
    ctx->pc = 0x10BF1Cu;
    // 0x10bf1c: 0x3c150023  lui         $s5, 0x23
    ctx->pc = 0x10bf1cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)35 << 16));
    // 0x10bf20: 0x26b17a18  addiu       $s1, $s5, 0x7A18
    ctx->pc = 0x10bf20u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 31256));
    // 0x10bf24: 0x0  nop
    ctx->pc = 0x10bf24u;
    // NOP
label_10bf28:
    // 0x10bf28: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x10bf28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x10bf2c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10BF2Cu;
    {
        const bool branch_taken_0x10bf2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BF30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BF2Cu;
            // 0x10bf30: 0x108043  sra         $s0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bf2c) {
            ctx->pc = 0x10BF48u;
            goto label_10bf48;
        }
    }
    ctx->pc = 0x10BF34u;
    // 0x10bf34: 0xde240000  ld          $a0, 0x0($s1)
    ctx->pc = 0x10bf34u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x10bf38: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10bf38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf3c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BF3Cu;
    SET_GPR_U32(ctx, 31, 0x10BF44u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BF44u; }
        if (ctx->pc != 0x10BF44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BF44u; }
        if (ctx->pc != 0x10BF44u) { return; }
    }
    ctx->pc = 0x10BF44u;
label_10bf44:
    // 0x10bf44: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bf44u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10bf48:
    // 0x10bf48: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x10bf48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x10bf4c: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x10bf4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10bf50: 0x1040fff5  beqz        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x10BF50u;
    {
        const bool branch_taken_0x10bf50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BF54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BF50u;
            // 0x10bf54: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bf50) {
            ctx->pc = 0x10BF28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bf28;
        }
    }
    ctx->pc = 0x10BF58u;
    // 0x10bf58: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10BF58u;
    {
        const bool branch_taken_0x10bf58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BF58u;
            // 0x10bf5c: 0x26a27a18  addiu       $v0, $s5, 0x7A18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 31256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bf58) {
            ctx->pc = 0x10BF68u;
            goto label_10bf68;
        }
    }
    ctx->pc = 0x10BF60u;
label_10bf60:
    // 0x10bf60: 0x3c150023  lui         $s5, 0x23
    ctx->pc = 0x10bf60u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)35 << 16));
    // 0x10bf64: 0x26a27a18  addiu       $v0, $s5, 0x7A18
    ctx->pc = 0x10bf64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 31256));
label_10bf68:
    // 0x10bf68: 0x1418c0  sll         $v1, $s4, 3
    ctx->pc = 0x10bf68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x10bf6c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10bf6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10bf70: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10bf70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf74: 0xdc700000  ld          $s0, 0x0($v1)
    ctx->pc = 0x10bf74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10bf78: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x10bf78u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf7c: 0x260a02d  daddu       $s4, $s3, $zero
    ctx->pc = 0x10bf7cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf80: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10bf80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf84: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BF84u;
    SET_GPR_U32(ctx, 31, 0x10BF8Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BF8Cu; }
        if (ctx->pc != 0x10BF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BF8Cu; }
        if (ctx->pc != 0x10BF8Cu) { return; }
    }
    ctx->pc = 0x10BF8Cu;
label_10bf8c:
    // 0x10bf8c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x10bf8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf90: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10bf90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf94: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10bf94u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bf98: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10BF98u;
    SET_GPR_U32(ctx, 31, 0x10BFA0u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFA0u; }
        if (ctx->pc != 0x10BFA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFA0u; }
        if (ctx->pc != 0x10BFA0u) { return; }
    }
    ctx->pc = 0x10BFA0u;
label_10bfa0:
    // 0x10bfa0: 0x14400022  bnez        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10BFA0u;
    {
        const bool branch_taken_0x10bfa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BFA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BFA0u;
            // 0x10bfa4: 0x8fa50018  lw          $a1, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bfa0) {
            ctx->pc = 0x10C02Cu;
            goto label_10c02c;
        }
    }
    ctx->pc = 0x10BFA8u;
    // 0x10bfa8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10bfa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfac: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10bfacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfb0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10BFB0u;
    SET_GPR_U32(ctx, 31, 0x10BFB8u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFB8u; }
        if (ctx->pc != 0x10BFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFB8u; }
        if (ctx->pc != 0x10BFB8u) { return; }
    }
    ctx->pc = 0x10BFB8u;
label_10bfb8:
    // 0x10bfb8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10bfb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfbc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10bfbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfc0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10BFC0u;
    SET_GPR_U32(ctx, 31, 0x10BFC8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFC8u; }
        if (ctx->pc != 0x10BFC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFC8u; }
        if (ctx->pc != 0x10BFC8u) { return; }
    }
    ctx->pc = 0x10BFC8u;
label_10bfc8:
    // 0x10bfc8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x10bfc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfcc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10bfccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfd0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10BFD0u;
    SET_GPR_U32(ctx, 31, 0x10BFD8u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFD8u; }
        if (ctx->pc != 0x10BFD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10BFD8u; }
        if (ctx->pc != 0x10BFD8u) { return; }
    }
    ctx->pc = 0x10BFD8u;
label_10bfd8:
    // 0x10bfd8: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x10BFD8u;
    {
        const bool branch_taken_0x10bfd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10BFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BFD8u;
            // 0x10bfdc: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bfd8) {
            ctx->pc = 0x10C028u;
            goto label_10c028;
        }
    }
    ctx->pc = 0x10BFE0u;
label_10bfe0:
    // 0x10bfe0: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x10bfe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
label_10bfe4:
    // 0x10bfe4: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x10bfe4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10bfe8: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x10bfe8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x10bfec: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x10bfecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10bff0: 0x108001d6  beqz        $a0, . + 4 + (0x1D6 << 2)
    ctx->pc = 0x10BFF0u;
    {
        const bool branch_taken_0x10bff0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BFF0u;
            // 0x10bff4: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bff0) {
            ctx->pc = 0x10C74Cu;
            goto label_10c74c;
        }
    }
    ctx->pc = 0x10BFF8u;
    // 0x10bff8: 0x100001c5  b           . + 4 + (0x1C5 << 2)
    ctx->pc = 0x10BFF8u;
    {
        const bool branch_taken_0x10bff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10BFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10BFF8u;
            // 0x10bffc: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10bff8) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C000u;
label_10c000:
    // 0x10c000: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10c000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c004: 0xc042238  jal         func_1088E0
    ctx->pc = 0x10C004u;
    SET_GPR_U32(ctx, 31, 0x10C00Cu);
    ctx->pc = 0x1088E0u;
    if (runtime->hasFunction(0x1088E0u)) {
        auto targetFn = runtime->lookupFunction(0x1088E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C00Cu; }
        if (ctx->pc != 0x10C00Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001088E0_0x1088e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C00Cu; }
        if (ctx->pc != 0x10C00Cu) { return; }
    }
    ctx->pc = 0x10C00Cu;
label_10c00c:
    // 0x10c00c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10c00cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c010: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c014: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10C014u;
    SET_GPR_U32(ctx, 31, 0x10C01Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C01Cu; }
        if (ctx->pc != 0x10C01Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C01Cu; }
        if (ctx->pc != 0x10C01Cu) { return; }
    }
    ctx->pc = 0x10C01Cu;
label_10c01c:
    // 0x10c01c: 0x100001bb  b           . + 4 + (0x1BB << 2)
    ctx->pc = 0x10C01Cu;
    {
        const bool branch_taken_0x10c01c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C01Cu;
            // 0x10c020: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c01c) {
            ctx->pc = 0x10C70Cu;
            goto label_10c70c;
        }
    }
    ctx->pc = 0x10C024u;
    // 0x10c024: 0x0  nop
    ctx->pc = 0x10c024u;
    // NOP
label_10c028:
    // 0x10c028: 0x8fa50018  lw          $a1, 0x18($sp)
    ctx->pc = 0x10c028u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_10c02c:
    // 0x10c02c: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x10c02cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c030: 0x8fa80020  lw          $t0, 0x20($sp)
    ctx->pc = 0x10c030u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10c034: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x10c034u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c038: 0xc041ff6  jal         func_107FD8
    ctx->pc = 0x10C038u;
    SET_GPR_U32(ctx, 31, 0x10C040u);
    ctx->pc = 0x10C03Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C038u;
            // 0x10c03c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107FD8u;
    if (runtime->hasFunction(0x107FD8u)) {
        auto targetFn = runtime->lookupFunction(0x107FD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C040u; }
        if (ctx->pc != 0x10C040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107FD8_0x107fd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C040u; }
        if (ctx->pc != 0x10C040u) { return; }
    }
    ctx->pc = 0x10C040u;
label_10c040:
    // 0x10c040: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x10c040u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x10c044: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x10c044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x10c048: 0x1000013a  b           . + 4 + (0x13A << 2)
    ctx->pc = 0x10C048u;
    {
        const bool branch_taken_0x10c048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C048u;
            // 0x10c04c: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c048) {
            ctx->pc = 0x10C534u;
            goto label_10c534;
        }
    }
    ctx->pc = 0x10C050u;
label_10c050:
    // 0x10c050: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c054: 0xc042164  jal         func_108590
    ctx->pc = 0x10C054u;
    SET_GPR_U32(ctx, 31, 0x10C05Cu);
    ctx->pc = 0x10C058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C054u;
            // 0x10c058: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C05Cu; }
        if (ctx->pc != 0x10C05Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C05Cu; }
        if (ctx->pc != 0x10C05Cu) { return; }
    }
    ctx->pc = 0x10C05Cu;
label_10c05c:
    // 0x10c05c: 0x8fa5003c  lw          $a1, 0x3C($sp)
    ctx->pc = 0x10c05cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x10c060: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c064: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x10C064u;
    SET_GPR_U32(ctx, 31, 0x10C06Cu);
    ctx->pc = 0x10C068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C064u;
            // 0x10c068: 0xafa20040  sw          $v0, 0x40($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C06Cu; }
        if (ctx->pc != 0x10C06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C06Cu; }
        if (ctx->pc != 0x10C06Cu) { return; }
    }
    ctx->pc = 0x10C06Cu;
label_10c06c:
    // 0x10c06c: 0x184001a8  blez        $v0, . + 4 + (0x1A8 << 2)
    ctx->pc = 0x10C06Cu;
    {
        const bool branch_taken_0x10c06c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x10C070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C06Cu;
            // 0x10c070: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c06c) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C074u;
    // 0x10c074: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x10C074u;
    {
        const bool branch_taken_0x10c074 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c074) {
            ctx->pc = 0x10C0ECu;
            goto label_10c0ec;
        }
    }
    ctx->pc = 0x10C07Cu;
    // 0x10c07c: 0x0  nop
    ctx->pc = 0x10c07cu;
    // NOP
label_10c080:
    // 0x10c080: 0x14800043  bnez        $a0, . + 4 + (0x43 << 2)
    ctx->pc = 0x10C080u;
    {
        const bool branch_taken_0x10c080 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C080u;
            // 0x10c084: 0x8fa5003c  lw          $a1, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c080) {
            ctx->pc = 0x10C190u;
            goto label_10c190;
        }
    }
    ctx->pc = 0x10C088u;
    // 0x10c088: 0x12a00013  beqz        $s5, . + 4 + (0x13 << 2)
    ctx->pc = 0x10C088u;
    {
        const bool branch_taken_0x10c088 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c088) {
            ctx->pc = 0x10C0D8u;
            goto label_10c0d8;
        }
    }
    ctx->pc = 0x10C090u;
    // 0x10c090: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10c090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c094: 0x31b3a  dsrl        $v1, $v1, 12
    ctx->pc = 0x10c094u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 12);
    // 0x10c098: 0x2631024  and         $v0, $s3, $v1
    ctx->pc = 0x10c098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 3));
    // 0x10c09c: 0x14430024  bne         $v0, $v1, . + 4 + (0x24 << 2)
    ctx->pc = 0x10C09Cu;
    {
        const bool branch_taken_0x10c09c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10C0A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C09Cu;
            // 0x10c0a0: 0x3c037ff0  lui         $v1, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c09c) {
            ctx->pc = 0x10C130u;
            goto label_10c130;
        }
    }
    ctx->pc = 0x10C0A4u;
    // 0x10c0a4: 0x13103f  dsra32      $v0, $s3, 0
    ctx->pc = 0x10c0a4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10c0a8: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10c0a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10c0ac: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x10c0acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x10c0b0: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x10c0b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x10c0b4: 0x3c040010  lui         $a0, 0x10
    ctx->pc = 0x10c0b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16 << 16));
    // 0x10c0b8: 0x2639824  and         $s3, $s3, $v1
    ctx->pc = 0x10c0b8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 3));
    // 0x10c0bc: 0x44102d  daddu       $v0, $v0, $a0
    ctx->pc = 0x10c0bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x10c0c0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10c0c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c0c4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10c0c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10c0c8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10c0c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c0cc: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x10c0ccu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x10c0d0: 0x1000018e  b           . + 4 + (0x18E << 2)
    ctx->pc = 0x10C0D0u;
    {
        const bool branch_taken_0x10c0d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C0D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C0D0u;
            // 0x10c0d4: 0x2639824  and         $s3, $s3, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c0d0) {
            ctx->pc = 0x10C70Cu;
            goto label_10c70c;
        }
    }
    ctx->pc = 0x10C0D8u;
label_10c0d8:
    // 0x10c0d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10c0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c0dc: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x10c0dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x10c0e0: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x10c0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x10c0e4: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x10C0E4u;
    {
        const bool branch_taken_0x10c0e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c0e4) {
            ctx->pc = 0x10C130u;
            goto label_10c130;
        }
    }
    ctx->pc = 0x10C0ECu;
label_10c0ec:
    // 0x10c0ec: 0x13103f  dsra32      $v0, $s3, 0
    ctx->pc = 0x10c0ecu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10c0f0: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x10c0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x10c0f4: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10c0f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10c0f8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10c0f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c0fc: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x10c0fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x10c100: 0x31b3a  dsrl        $v1, $v1, 12
    ctx->pc = 0x10c100u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 12);
    // 0x10c104: 0x3c04fff0  lui         $a0, 0xFFF0
    ctx->pc = 0x10c104u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65520 << 16));
    // 0x10c108: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x10c108u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x10c10c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x10c10cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x10c110: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10c110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10c114: 0x2659824  and         $s3, $s3, $a1
    ctx->pc = 0x10c114u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 5));
    // 0x10c118: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10c118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c11c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x10c11cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10c120: 0x2639825  or          $s3, $s3, $v1
    ctx->pc = 0x10c120u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 3));
    // 0x10c124: 0x10000179  b           . + 4 + (0x179 << 2)
    ctx->pc = 0x10C124u;
    {
        const bool branch_taken_0x10c124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C124u;
            // 0x10c128: 0x2659825  or          $s3, $s3, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c124) {
            ctx->pc = 0x10C70Cu;
            goto label_10c70c;
        }
    }
    ctx->pc = 0x10C12Cu;
    // 0x10c12c: 0x0  nop
    ctx->pc = 0x10c12cu;
    // NOP
label_10c130:
    // 0x10c130: 0x13103c  dsll32      $v0, $s3, 0
    ctx->pc = 0x10c130u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) << (32 + 0));
    // 0x10c134: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10c134u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10c138: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x10c138u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x10c13c: 0x10400174  beqz        $v0, . + 4 + (0x174 << 2)
    ctx->pc = 0x10C13Cu;
    {
        const bool branch_taken_0x10c13c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C13Cu;
            // 0x10c140: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c13c) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C144u;
    // 0x10c144: 0x16a0ffae  bnez        $s5, . + 4 + (-0x52 << 2)
    ctx->pc = 0x10C144u;
    {
        const bool branch_taken_0x10c144 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c144) {
            ctx->pc = 0x10C000u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c000;
        }
    }
    ctx->pc = 0x10C14Cu;
    // 0x10c14c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10c14cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c150: 0xc042238  jal         func_1088E0
    ctx->pc = 0x10C150u;
    SET_GPR_U32(ctx, 31, 0x10C158u);
    ctx->pc = 0x1088E0u;
    if (runtime->hasFunction(0x1088E0u)) {
        auto targetFn = runtime->lookupFunction(0x1088E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C158u; }
        if (ctx->pc != 0x10C158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001088E0_0x1088e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C158u; }
        if (ctx->pc != 0x10C158u) { return; }
    }
    ctx->pc = 0x10C158u;
label_10c158:
    // 0x10c158: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10c158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c15c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c15cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c160: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C160u;
    SET_GPR_U32(ctx, 31, 0x10C168u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C168u; }
        if (ctx->pc != 0x10C168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C168u; }
        if (ctx->pc != 0x10C168u) { return; }
    }
    ctx->pc = 0x10C168u;
label_10c168:
    // 0x10c168: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10c168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c16c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c16cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c170: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10c170u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c174: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C174u;
    SET_GPR_U32(ctx, 31, 0x10C17Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C17Cu; }
        if (ctx->pc != 0x10C17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C17Cu; }
        if (ctx->pc != 0x10C17Cu) { return; }
    }
    ctx->pc = 0x10C17Cu;
label_10c17c:
    // 0x10c17c: 0x1040ff98  beqz        $v0, . + 4 + (-0x68 << 2)
    ctx->pc = 0x10C17Cu;
    {
        const bool branch_taken_0x10c17c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C17Cu;
            // 0x10c180: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c17c) {
            ctx->pc = 0x10BFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bfe0;
        }
    }
    ctx->pc = 0x10C184u;
    // 0x10c184: 0x10000162  b           . + 4 + (0x162 << 2)
    ctx->pc = 0x10C184u;
    {
        const bool branch_taken_0x10c184 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c184) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C18Cu;
    // 0x10c18c: 0x0  nop
    ctx->pc = 0x10c18cu;
    // NOP
label_10c190:
    // 0x10c190: 0xc042334  jal         func_108CD0
    ctx->pc = 0x10C190u;
    SET_GPR_U32(ctx, 31, 0x10C198u);
    ctx->pc = 0x10C194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C190u;
            // 0x10c194: 0x8fa40040  lw          $a0, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108CD0u;
    if (runtime->hasFunction(0x108CD0u)) {
        auto targetFn = runtime->lookupFunction(0x108CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C198u; }
        if (ctx->pc != 0x10C198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108CD0_0x108cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C198u; }
        if (ctx->pc != 0x10C198u) { return; }
    }
    ctx->pc = 0x10C198u;
label_10c198:
    // 0x10c198: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x10c198u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x10c19c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x10c19cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x10c1a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10c1a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c1a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c1a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c1a8: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C1A8u;
    SET_GPR_U32(ctx, 31, 0x10C1B0u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C1B0u; }
        if (ctx->pc != 0x10C1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C1B0u; }
        if (ctx->pc != 0x10C1B0u) { return; }
    }
    ctx->pc = 0x10C1B0u;
label_10c1b0:
    // 0x10c1b0: 0x1c40002f  bgtz        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x10C1B0u;
    {
        const bool branch_taken_0x10c1b0 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10c1b0) {
            ctx->pc = 0x10C270u;
            goto label_10c270;
        }
    }
    ctx->pc = 0x10C1B8u;
    // 0x10c1b8: 0x12a00007  beqz        $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x10C1B8u;
    {
        const bool branch_taken_0x10c1b8 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c1b8) {
            ctx->pc = 0x10C1D8u;
            goto label_10c1d8;
        }
    }
    ctx->pc = 0x10C1C0u;
    // 0x10c1c0: 0x3410ffc0  ori         $s0, $zero, 0xFFC0
    ctx->pc = 0x10c1c0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x10c1c4: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x10c1c4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x10c1c8: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x10c1c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c1cc: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x10C1CCu;
    {
        const bool branch_taken_0x10c1cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c1cc) {
            ctx->pc = 0x10C2C0u;
            goto label_10c2c0;
        }
    }
    ctx->pc = 0x10C1D4u;
    // 0x10c1d4: 0x0  nop
    ctx->pc = 0x10c1d4u;
    // NOP
label_10c1d8:
    // 0x10c1d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10c1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c1dc: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x10c1dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x10c1e0: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x10c1e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x10c1e4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10C1E4u;
    {
        const bool branch_taken_0x10c1e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C1E4u;
            // 0x10c1e8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c1e4) {
            ctx->pc = 0x10C210u;
            goto label_10c210;
        }
    }
    ctx->pc = 0x10C1ECu;
    // 0x10c1ec: 0x1262ff7d  beq         $s3, $v0, . + 4 + (-0x83 << 2)
    ctx->pc = 0x10C1ECu;
    {
        const bool branch_taken_0x10c1ec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x10C1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C1ECu;
            // 0x10c1f0: 0x24020022  addiu       $v0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c1ec) {
            ctx->pc = 0x10BFE4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bfe4;
        }
    }
    ctx->pc = 0x10C1F4u;
    // 0x10c1f4: 0x3410ffc0  ori         $s0, $zero, 0xFFC0
    ctx->pc = 0x10c1f4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x10c1f8: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x10c1f8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x10c1fc: 0x3411bff0  ori         $s1, $zero, 0xBFF0
    ctx->pc = 0x10c1fcu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49136);
    // 0x10c200: 0x118c3c  dsll32      $s1, $s1, 16
    ctx->pc = 0x10c200u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 16));
    // 0x10c204: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x10C204u;
    {
        const bool branch_taken_0x10c204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c204) {
            ctx->pc = 0x10C2C0u;
            goto label_10c2c0;
        }
    }
    ctx->pc = 0x10C20Cu;
    // 0x10c20c: 0x0  nop
    ctx->pc = 0x10c20cu;
    // NOP
label_10c210:
    // 0x10c210: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x10c210u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x10c214: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x10c214u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x10c218: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c21c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C21Cu;
    SET_GPR_U32(ctx, 31, 0x10C224u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C224u; }
        if (ctx->pc != 0x10C224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C224u; }
        if (ctx->pc != 0x10C224u) { return; }
    }
    ctx->pc = 0x10C224u;
label_10c224:
    // 0x10c224: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C224u;
    {
        const bool branch_taken_0x10c224 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x10c224) {
            ctx->pc = 0x10C240u;
            goto label_10c240;
        }
    }
    ctx->pc = 0x10C22Cu;
    // 0x10c22c: 0x3410ff80  ori         $s0, $zero, 0xFF80
    ctx->pc = 0x10c22cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x10c230: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x10c230u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x10c234: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10C234u;
    {
        const bool branch_taken_0x10c234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c234) {
            ctx->pc = 0x10C258u;
            goto label_10c258;
        }
    }
    ctx->pc = 0x10C23Cu;
    // 0x10c23c: 0x0  nop
    ctx->pc = 0x10c23cu;
    // NOP
label_10c240:
    // 0x10c240: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x10c240u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x10c244: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x10c244u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x10c248: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c24c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10C24Cu;
    SET_GPR_U32(ctx, 31, 0x10C254u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C254u; }
        if (ctx->pc != 0x10C254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C254u; }
        if (ctx->pc != 0x10C254u) { return; }
    }
    ctx->pc = 0x10C254u;
label_10c254:
    // 0x10c254: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10c254u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10c258:
    // 0x10c258: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10c258u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c25c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10c25cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c260: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C260u;
    SET_GPR_U32(ctx, 31, 0x10C268u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C268u; }
        if (ctx->pc != 0x10C268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C268u; }
        if (ctx->pc != 0x10C268u) { return; }
    }
    ctx->pc = 0x10C268u;
label_10c268:
    // 0x10c268: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x10C268u;
    {
        const bool branch_taken_0x10c268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c268) {
            ctx->pc = 0x10C2BCu;
            goto label_10c2bc;
        }
    }
    ctx->pc = 0x10C270u;
label_10c270:
    // 0x10c270: 0x3412ff80  ori         $s2, $zero, 0xFF80
    ctx->pc = 0x10c270u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x10c274: 0x1293bc  dsll32      $s2, $s2, 14
    ctx->pc = 0x10c274u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) << (32 + 14));
    // 0x10c278: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c278u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c27c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10c27cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c280: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10C280u;
    SET_GPR_U32(ctx, 31, 0x10C288u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C288u; }
        if (ctx->pc != 0x10C288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C288u; }
        if (ctx->pc != 0x10C288u) { return; }
    }
    ctx->pc = 0x10C288u;
label_10c288:
    // 0x10c288: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10c288u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c28c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10c28cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c290: 0x16a00006  bnez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C290u;
    {
        const bool branch_taken_0x10c290 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c290) {
            ctx->pc = 0x10C2ACu;
            goto label_10c2ac;
        }
    }
    ctx->pc = 0x10C298u;
    // 0x10c298: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10c298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c29c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10c29cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c2a0: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C2A0u;
    SET_GPR_U32(ctx, 31, 0x10C2A8u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C2A8u; }
        if (ctx->pc != 0x10C2A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C2A8u; }
        if (ctx->pc != 0x10C2A8u) { return; }
    }
    ctx->pc = 0x10C2A8u;
label_10c2a8:
    // 0x10c2a8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10c2a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10c2ac:
    // 0x10c2ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10c2acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c2b0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10c2b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c2b4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10C2B4u;
    SET_GPR_U32(ctx, 31, 0x10C2BCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C2BCu; }
        if (ctx->pc != 0x10C2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C2BCu; }
        if (ctx->pc != 0x10C2BCu) { return; }
    }
    ctx->pc = 0x10C2BCu;
label_10c2bc:
    // 0x10c2bc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10c2bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10c2c0:
    // 0x10c2c0: 0x13183f  dsra32      $v1, $s3, 0
    ctx->pc = 0x10c2c0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10c2c4: 0x3c177ff0  lui         $s7, 0x7FF0
    ctx->pc = 0x10c2c4u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32752 << 16));
    // 0x10c2c8: 0x772024  and         $a0, $v1, $s7
    ctx->pc = 0x10c2c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 23));
    // 0x10c2cc: 0x3c027fe0  lui         $v0, 0x7FE0
    ctx->pc = 0x10c2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32736 << 16));
    // 0x10c2d0: 0x14820031  bne         $a0, $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x10C2D0u;
    {
        const bool branch_taken_0x10c2d0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x10C2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C2D0u;
            // 0x10c2d4: 0xafa40020  sw          $a0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c2d0) {
            ctx->pc = 0x10C398u;
            goto label_10c398;
        }
    }
    ctx->pc = 0x10C2D8u;
    // 0x10c2d8: 0x3c02fcb0  lui         $v0, 0xFCB0
    ctx->pc = 0x10c2d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64688 << 16));
    // 0x10c2dc: 0x3c12ffff  lui         $s2, 0xFFFF
    ctx->pc = 0x10c2dcu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)65535 << 16));
    // 0x10c2e0: 0x12903e  dsrl32      $s2, $s2, 0
    ctx->pc = 0x10c2e0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) >> (32 + 0));
    // 0x10c2e4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x10c2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10c2e8: 0x260a02d  daddu       $s4, $s3, $zero
    ctx->pc = 0x10c2e8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c2ec: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10c2ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c2f0: 0x2729824  and         $s3, $s3, $s2
    ctx->pc = 0x10c2f0u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 18));
    // 0x10c2f4: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x10c2f4u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x10c2f8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10c2f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c2fc: 0xc042238  jal         func_1088E0
    ctx->pc = 0x10C2FCu;
    SET_GPR_U32(ctx, 31, 0x10C304u);
    ctx->pc = 0x1088E0u;
    if (runtime->hasFunction(0x1088E0u)) {
        auto targetFn = runtime->lookupFunction(0x1088E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C304u; }
        if (ctx->pc != 0x10C304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001088E0_0x1088e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C304u; }
        if (ctx->pc != 0x10C304u) { return; }
    }
    ctx->pc = 0x10C304u;
label_10c304:
    // 0x10c304: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10c304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c308: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c308u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c30c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10C30Cu;
    SET_GPR_U32(ctx, 31, 0x10C314u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C314u; }
        if (ctx->pc != 0x10C314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C314u; }
        if (ctx->pc != 0x10C314u) { return; }
    }
    ctx->pc = 0x10C314u;
label_10c314:
    // 0x10c314: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10c314u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c318: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c31c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10C31Cu;
    SET_GPR_U32(ctx, 31, 0x10C324u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C324u; }
        if (ctx->pc != 0x10C324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C324u; }
        if (ctx->pc != 0x10C324u) { return; }
    }
    ctx->pc = 0x10C324u;
label_10c324:
    // 0x10c324: 0x3c037c9f  lui         $v1, 0x7C9F
    ctx->pc = 0x10c324u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)31903 << 16));
    // 0x10c328: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10c328u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c32c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10c32cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10c330: 0x13203f  dsra32      $a0, $s3, 0
    ctx->pc = 0x10c330u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10c334: 0x971024  and         $v0, $a0, $s7
    ctx->pc = 0x10c334u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 23));
    // 0x10c338: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x10c338u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10c33c: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x10C33Cu;
    {
        const bool branch_taken_0x10c33c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C33Cu;
            // 0x10c340: 0x2729824  and         $s3, $s3, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c33c) {
            ctx->pc = 0x10C380u;
            goto label_10c380;
        }
    }
    ctx->pc = 0x10C344u;
    // 0x10c344: 0x3c027fef  lui         $v0, 0x7FEF
    ctx->pc = 0x10c344u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32751 << 16));
    // 0x10c348: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10c348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10c34c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x10c34cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x10c350: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10c350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10c354: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x10c354u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x10c358: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10c358u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10c35c: 0x1282fe95  beq         $s4, $v0, . + 4 + (-0x16B << 2)
    ctx->pc = 0x10C35Cu;
    {
        const bool branch_taken_0x10c35c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        ctx->pc = 0x10C360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C35Cu;
            // 0x10c360: 0x24020022  addiu       $v0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c35c) {
            ctx->pc = 0x10BDB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10bdb4;
        }
    }
    ctx->pc = 0x10C364u;
    // 0x10c364: 0x3c027fef  lui         $v0, 0x7FEF
    ctx->pc = 0x10c364u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32751 << 16));
    // 0x10c368: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10c368u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10c36c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10c36cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c370: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x10c370u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x10c374: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x10C374u;
    {
        const bool branch_taken_0x10c374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C374u;
            // 0x10c378: 0x2729825  or          $s3, $s3, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c374) {
            ctx->pc = 0x10C504u;
            goto label_10c504;
        }
    }
    ctx->pc = 0x10C37Cu;
    // 0x10c37c: 0x0  nop
    ctx->pc = 0x10c37cu;
    // NOP
label_10c380:
    // 0x10c380: 0x3c020350  lui         $v0, 0x350
    ctx->pc = 0x10c380u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)848 << 16));
    // 0x10c384: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10c384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10c388: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10c388u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c38c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x10C38Cu;
    {
        const bool branch_taken_0x10c38c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C38Cu;
            // 0x10c390: 0x2629825  or          $s3, $s3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c38c) {
            ctx->pc = 0x10C440u;
            goto label_10c440;
        }
    }
    ctx->pc = 0x10C394u;
    // 0x10c394: 0x0  nop
    ctx->pc = 0x10c394u;
    // NOP
label_10c398:
    // 0x10c398: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x10c398u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10c39c: 0x3c020340  lui         $v0, 0x340
    ctx->pc = 0x10c39cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)832 << 16));
    // 0x10c3a0: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x10c3a0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x10c3a4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x10C3A4u;
    {
        const bool branch_taken_0x10c3a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c3a4) {
            ctx->pc = 0x10C410u;
            goto label_10c410;
        }
    }
    ctx->pc = 0x10C3ACu;
    // 0x10c3ac: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x10c3acu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x10c3b0: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x10c3b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x10c3b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c3b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c3b8: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C3B8u;
    SET_GPR_U32(ctx, 31, 0x10C3C0u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3C0u; }
        if (ctx->pc != 0x10C3C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3C0u; }
        if (ctx->pc != 0x10C3C0u) { return; }
    }
    ctx->pc = 0x10C3C0u;
label_10c3c0:
    // 0x10c3c0: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x10C3C0u;
    {
        const bool branch_taken_0x10c3c0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x10c3c0) {
            ctx->pc = 0x10C410u;
            goto label_10c410;
        }
    }
    ctx->pc = 0x10C3C8u;
    // 0x10c3c8: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x10c3c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x10c3cc: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x10c3ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x10c3d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c3d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c3d4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10C3D4u;
    SET_GPR_U32(ctx, 31, 0x10C3DCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3DCu; }
        if (ctx->pc != 0x10C3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3DCu; }
        if (ctx->pc != 0x10C3DCu) { return; }
    }
    ctx->pc = 0x10C3DCu;
label_10c3dc:
    // 0x10c3dc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c3dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c3e0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x10C3E0u;
    SET_GPR_U32(ctx, 31, 0x10C3E8u);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3E8u; }
        if (ctx->pc != 0x10C3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3E8u; }
        if (ctx->pc != 0x10C3E8u) { return; }
    }
    ctx->pc = 0x10C3E8u;
label_10c3e8:
    // 0x10c3e8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x10C3E8u;
    SET_GPR_U32(ctx, 31, 0x10C3F0u);
    ctx->pc = 0x10C3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C3E8u;
            // 0x10c3ec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3F0u; }
        if (ctx->pc != 0x10C3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C3F0u; }
        if (ctx->pc != 0x10C3F0u) { return; }
    }
    ctx->pc = 0x10C3F0u;
label_10c3f0:
    // 0x10c3f0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10c3f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c3f4: 0x16a00006  bnez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C3F4u;
    {
        const bool branch_taken_0x10c3f4 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c3f4) {
            ctx->pc = 0x10C410u;
            goto label_10c410;
        }
    }
    ctx->pc = 0x10C3FCu;
    // 0x10c3fc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x10c3fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c400: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10c400u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c404: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C404u;
    SET_GPR_U32(ctx, 31, 0x10C40Cu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C40Cu; }
        if (ctx->pc != 0x10C40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C40Cu; }
        if (ctx->pc != 0x10C40Cu) { return; }
    }
    ctx->pc = 0x10C40Cu;
label_10c40c:
    // 0x10c40c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10c40cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10c410:
    // 0x10c410: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10c410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c414: 0xc042238  jal         func_1088E0
    ctx->pc = 0x10C414u;
    SET_GPR_U32(ctx, 31, 0x10C41Cu);
    ctx->pc = 0x1088E0u;
    if (runtime->hasFunction(0x1088E0u)) {
        auto targetFn = runtime->lookupFunction(0x1088E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C41Cu; }
        if (ctx->pc != 0x10C41Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001088E0_0x1088e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C41Cu; }
        if (ctx->pc != 0x10C41Cu) { return; }
    }
    ctx->pc = 0x10C41Cu;
label_10c41c:
    // 0x10c41c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10c41cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c420: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c420u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c424: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10C424u;
    SET_GPR_U32(ctx, 31, 0x10C42Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C42Cu; }
        if (ctx->pc != 0x10C42Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C42Cu; }
        if (ctx->pc != 0x10C42Cu) { return; }
    }
    ctx->pc = 0x10C42Cu;
label_10c42c:
    // 0x10c42c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10c42cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c430: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c430u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c434: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x10C434u;
    SET_GPR_U32(ctx, 31, 0x10C43Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C43Cu; }
        if (ctx->pc != 0x10C43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C43Cu; }
        if (ctx->pc != 0x10C43Cu) { return; }
    }
    ctx->pc = 0x10C43Cu;
label_10c43c:
    // 0x10c43c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10c43cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10c440:
    // 0x10c440: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x10c440u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10c444: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x10c444u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x10c448: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x10c448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x10c44c: 0x13203f  dsra32      $a0, $s3, 0
    ctx->pc = 0x10c44cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x10c450: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x10c450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10c454: 0x838824  and         $s1, $a0, $v1
    ctx->pc = 0x10c454u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x10c458: 0x1451002b  bne         $v0, $s1, . + 4 + (0x2B << 2)
    ctx->pc = 0x10C458u;
    {
        const bool branch_taken_0x10c458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x10C45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C458u;
            // 0x10c45c: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c458) {
            ctx->pc = 0x10C508u;
            goto label_10c508;
        }
    }
    ctx->pc = 0x10C460u;
    // 0x10c460: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c460u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c464: 0xc044574  jal         func_1115D0
    ctx->pc = 0x10C464u;
    SET_GPR_U32(ctx, 31, 0x10C46Cu);
    ctx->pc = 0x1115D0u;
    if (runtime->hasFunction(0x1115D0u)) {
        auto targetFn = runtime->lookupFunction(0x1115D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C46Cu; }
        if (ctx->pc != 0x10C46Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001115D0_0x1115d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C46Cu; }
        if (ctx->pc != 0x10C46Cu) { return; }
    }
    ctx->pc = 0x10C46Cu;
label_10c46c:
    // 0x10c46c: 0xc0444ca  jal         func_111328
    ctx->pc = 0x10C46Cu;
    SET_GPR_U32(ctx, 31, 0x10C474u);
    ctx->pc = 0x10C470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C46Cu;
            // 0x10c470: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C474u; }
        if (ctx->pc != 0x10C474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C474u; }
        if (ctx->pc != 0x10C474u) { return; }
    }
    ctx->pc = 0x10C474u;
label_10c474:
    // 0x10c474: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c478: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c478u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c47c: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C47Cu;
    SET_GPR_U32(ctx, 31, 0x10C484u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C484u; }
        if (ctx->pc != 0x10C484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C484u; }
        if (ctx->pc != 0x10C484u) { return; }
    }
    ctx->pc = 0x10C484u;
label_10c484:
    // 0x10c484: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10c484u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c488: 0x16a00006  bnez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C488u;
    {
        const bool branch_taken_0x10c488 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c488) {
            ctx->pc = 0x10C4A4u;
            goto label_10c4a4;
        }
    }
    ctx->pc = 0x10C490u;
    // 0x10c490: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10c490u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c494: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x10c494u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x10c498: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x10c498u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x10c49c: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x10C49Cu;
    {
        const bool branch_taken_0x10c49c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c49c) {
            ctx->pc = 0x10C4E8u;
            goto label_10c4e8;
        }
    }
    ctx->pc = 0x10C4A4u;
label_10c4a4:
    // 0x10c4a4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x10c4a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x10c4a8: 0xdc257b08  ld          $a1, 0x7B08($at)
    ctx->pc = 0x10c4a8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 31496)));
    // 0x10c4ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c4acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c4b0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C4B0u;
    SET_GPR_U32(ctx, 31, 0x10C4B8u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4B8u; }
        if (ctx->pc != 0x10C4B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4B8u; }
        if (ctx->pc != 0x10C4B8u) { return; }
    }
    ctx->pc = 0x10C4B8u;
label_10c4b8:
    // 0x10c4b8: 0x4400095  bltz        $v0, . + 4 + (0x95 << 2)
    ctx->pc = 0x10C4B8u;
    {
        const bool branch_taken_0x10c4b8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10C4BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C4B8u;
            // 0x10c4bc: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c4b8) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C4C0u;
    // 0x10c4c0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x10c4c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x10c4c4: 0xdc257b10  ld          $a1, 0x7B10($at)
    ctx->pc = 0x10c4c4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 31504)));
    // 0x10c4c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c4c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c4cc: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C4CCu;
    SET_GPR_U32(ctx, 31, 0x10C4D4u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4D4u; }
        if (ctx->pc != 0x10C4D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4D4u; }
        if (ctx->pc != 0x10C4D4u) { return; }
    }
    ctx->pc = 0x10C4D4u;
label_10c4d4:
    // 0x10c4d4: 0x1c40008e  bgtz        $v0, . + 4 + (0x8E << 2)
    ctx->pc = 0x10C4D4u;
    {
        const bool branch_taken_0x10c4d4 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x10C4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C4D4u;
            // 0x10c4d8: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c4d4) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C4DCu;
    // 0x10c4dc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10C4DCu;
    {
        const bool branch_taken_0x10c4dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10c4dc) {
            ctx->pc = 0x10C508u;
            goto label_10c508;
        }
    }
    ctx->pc = 0x10C4E4u;
    // 0x10c4e4: 0x0  nop
    ctx->pc = 0x10c4e4u;
    // NOP
label_10c4e8:
    // 0x10c4e8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x10c4e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x10c4ec: 0xdc257b18  ld          $a1, 0x7B18($at)
    ctx->pc = 0x10c4ecu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 31512)));
    // 0x10c4f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10c4f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c4f4: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10C4F4u;
    SET_GPR_U32(ctx, 31, 0x10C4FCu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4FCu; }
        if (ctx->pc != 0x10C4FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C4FCu; }
        if (ctx->pc != 0x10C4FCu) { return; }
    }
    ctx->pc = 0x10C4FCu;
label_10c4fc:
    // 0x10c4fc: 0x4400084  bltz        $v0, . + 4 + (0x84 << 2)
    ctx->pc = 0x10C4FCu;
    {
        const bool branch_taken_0x10c4fc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10C500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C4FCu;
            // 0x10c500: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c4fc) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C504u;
label_10c504:
    // 0x10c504: 0x8fa50030  lw          $a1, 0x30($sp)
    ctx->pc = 0x10c504u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_10c508:
    // 0x10c508: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C508u;
    SET_GPR_U32(ctx, 31, 0x10C510u);
    ctx->pc = 0x10C50Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C508u;
            // 0x10c50c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C510u; }
        if (ctx->pc != 0x10C510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C510u; }
        if (ctx->pc != 0x10C510u) { return; }
    }
    ctx->pc = 0x10C510u;
label_10c510:
    // 0x10c510: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c514: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C514u;
    SET_GPR_U32(ctx, 31, 0x10C51Cu);
    ctx->pc = 0x10C518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C514u;
            // 0x10c518: 0x8fa50034  lw          $a1, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C51Cu; }
        if (ctx->pc != 0x10C51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C51Cu; }
        if (ctx->pc != 0x10C51Cu) { return; }
    }
    ctx->pc = 0x10C51Cu;
label_10c51c:
    // 0x10c51c: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c51cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c520: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C520u;
    SET_GPR_U32(ctx, 31, 0x10C528u);
    ctx->pc = 0x10C524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C520u;
            // 0x10c524: 0x8fa5003c  lw          $a1, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C528u; }
        if (ctx->pc != 0x10C528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C528u; }
        if (ctx->pc != 0x10C528u) { return; }
    }
    ctx->pc = 0x10C528u;
label_10c528:
    // 0x10c528: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c52c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C52Cu;
    SET_GPR_U32(ctx, 31, 0x10C534u);
    ctx->pc = 0x10C530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C52Cu;
            // 0x10c530: 0x8fa50040  lw          $a1, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C534u; }
        if (ctx->pc != 0x10C534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C534u; }
        if (ctx->pc != 0x10C534u) { return; }
    }
    ctx->pc = 0x10C534u;
label_10c534:
    // 0x10c534: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x10c534u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10c538: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c538u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c53c: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x10C53Cu;
    SET_GPR_U32(ctx, 31, 0x10C544u);
    ctx->pc = 0x10C540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C53Cu;
            // 0x10c540: 0x8c450004  lw          $a1, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C544u; }
        if (ctx->pc != 0x10C544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C544u; }
        if (ctx->pc != 0x10C544u) { return; }
    }
    ctx->pc = 0x10C544u;
label_10c544:
    // 0x10c544: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x10c544u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x10c548: 0x2444000c  addiu       $a0, $v0, 0xC
    ctx->pc = 0x10c548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x10c54c: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x10c54cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10c550: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x10c550u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x10c554: 0x8c660010  lw          $a2, 0x10($v1)
    ctx->pc = 0x10c554u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x10c558: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x10c558u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x10c55c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x10C55Cu;
    SET_GPR_U32(ctx, 31, 0x10C564u);
    ctx->pc = 0x10C560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C55Cu;
            // 0x10c560: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C564u; }
        if (ctx->pc != 0x10C564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C564u; }
        if (ctx->pc != 0x10C564u) { return; }
    }
    ctx->pc = 0x10C564u;
label_10c564:
    // 0x10c564: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c564u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c568: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x10c568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c56c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x10c56cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c570: 0xc0422d2  jal         func_108B48
    ctx->pc = 0x10C570u;
    SET_GPR_U32(ctx, 31, 0x10C578u);
    ctx->pc = 0x10C574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C570u;
            // 0x10c574: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108B48u;
    if (runtime->hasFunction(0x108B48u)) {
        auto targetFn = runtime->lookupFunction(0x108B48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C578u; }
        if (ctx->pc != 0x10C578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108B48_0x108b48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C578u; }
        if (ctx->pc != 0x10C578u) { return; }
    }
    ctx->pc = 0x10C578u;
label_10c578:
    // 0x10c578: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c578u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c57c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x10c57cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10c580: 0xc042092  jal         func_108248
    ctx->pc = 0x10C580u;
    SET_GPR_U32(ctx, 31, 0x10C588u);
    ctx->pc = 0x10C584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C580u;
            // 0x10c584: 0xafa20030  sw          $v0, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108248u;
    if (runtime->hasFunction(0x108248u)) {
        auto targetFn = runtime->lookupFunction(0x108248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C588u; }
        if (ctx->pc != 0x10C588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108248_0x108248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C588u; }
        if (ctx->pc != 0x10C588u) { return; }
    }
    ctx->pc = 0x10C588u;
label_10c588:
    // 0x10c588: 0xdfa40010  ld          $a0, 0x10($sp)
    ctx->pc = 0x10c588u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10c58c: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C58Cu;
    {
        const bool branch_taken_0x10c58c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x10C590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C58Cu;
            // 0x10c590: 0xafa2003c  sw          $v0, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c58c) {
            ctx->pc = 0x10C5A8u;
            goto label_10c5a8;
        }
    }
    ctx->pc = 0x10C594u;
    // 0x10c594: 0x8fb10048  lw          $s1, 0x48($sp)
    ctx->pc = 0x10c594u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10c598: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x10c598u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c59c: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x10c59cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c5a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10C5A0u;
    {
        const bool branch_taken_0x10c5a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C5A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C5A0u;
            // 0x10c5a4: 0x220b82d  daddu       $s7, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c5a0) {
            ctx->pc = 0x10C5BCu;
            goto label_10c5bc;
        }
    }
    ctx->pc = 0x10C5A8u;
label_10c5a8:
    // 0x10c5a8: 0x8fa20048  lw          $v0, 0x48($sp)
    ctx->pc = 0x10c5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10c5ac: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x10c5acu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c5b0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x10c5b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c5b4: 0x29023  negu        $s2, $v0
    ctx->pc = 0x10c5b4u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10c5b8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x10c5b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_10c5bc:
    // 0x10c5bc: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x10c5bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10c5c0: 0x4420002  bltzl       $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x10C5C0u;
    {
        const bool branch_taken_0x10c5c0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x10c5c0) {
            ctx->pc = 0x10C5C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C5C0u;
            // 0x10c5c4: 0x2228823  subu        $s1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C5CCu;
            goto label_10c5cc;
        }
    }
    ctx->pc = 0x10C5C8u;
    // 0x10c5c8: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x10c5c8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_10c5cc:
    // 0x10c5cc: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x10c5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x10c5d0: 0x24540433  addiu       $s4, $v0, 0x433
    ctx->pc = 0x10c5d0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 1075));
    // 0x10c5d4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x10c5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x10c5d8: 0x2444ffff  addiu       $a0, $v0, -0x1
    ctx->pc = 0x10c5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10c5dc: 0x2883fc02  slti        $v1, $a0, -0x3FE
    ctx->pc = 0x10c5dcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294966274) ? 1 : 0);
    // 0x10c5e0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x10C5E0u;
    {
        const bool branch_taken_0x10c5e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C5E0u;
            // 0x10c5e4: 0x240a82d  daddu       $s5, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c5e0) {
            ctx->pc = 0x10C5F0u;
            goto label_10c5f0;
        }
    }
    ctx->pc = 0x10C5E8u;
    // 0x10c5e8: 0x24020036  addiu       $v0, $zero, 0x36
    ctx->pc = 0x10c5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x10c5ec: 0x45a023  subu        $s4, $v0, $a1
    ctx->pc = 0x10c5ecu;
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_10c5f0:
    // 0x10c5f0: 0x2342021  addu        $a0, $s1, $s4
    ctx->pc = 0x10c5f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x10c5f4: 0x2549021  addu        $s2, $s2, $s4
    ctx->pc = 0x10c5f4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
    // 0x10c5f8: 0x244182a  slt         $v1, $s2, $a0
    ctx->pc = 0x10c5f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x10c5fc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x10c5fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c600: 0x243200b  movn        $a0, $s2, $v1
    ctx->pc = 0x10c600u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 18));
    // 0x10c604: 0x2a4102a  slt         $v0, $s5, $a0
    ctx->pc = 0x10c604u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x10c608: 0x2a2200b  movn        $a0, $s5, $v0
    ctx->pc = 0x10c608u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 21));
    // 0x10c60c: 0x18800004  blez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10C60Cu;
    {
        const bool branch_taken_0x10c60c = (GPR_S64(ctx, 4) <= 0);
        if (branch_taken_0x10c60c) {
            ctx->pc = 0x10C620u;
            goto label_10c620;
        }
    }
    ctx->pc = 0x10C614u;
    // 0x10c614: 0x2a4a823  subu        $s5, $s5, $a0
    ctx->pc = 0x10c614u;
    SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
    // 0x10c618: 0x2449023  subu        $s2, $s2, $a0
    ctx->pc = 0x10c618u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    // 0x10c61c: 0x2248823  subu        $s1, $s1, $a0
    ctx->pc = 0x10c61cu;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
label_10c620:
    // 0x10c620: 0x18c0000d  blez        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x10C620u;
    {
        const bool branch_taken_0x10c620 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x10C624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C620u;
            // 0x10c624: 0x8fa5003c  lw          $a1, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c620) {
            ctx->pc = 0x10C658u;
            goto label_10c658;
        }
    }
    ctx->pc = 0x10C628u;
    // 0x10c628: 0xc042124  jal         func_108490
    ctx->pc = 0x10C628u;
    SET_GPR_U32(ctx, 31, 0x10C630u);
    ctx->pc = 0x10C62Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C628u;
            // 0x10c62c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C630u; }
        if (ctx->pc != 0x10C630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C630u; }
        if (ctx->pc != 0x10C630u) { return; }
    }
    ctx->pc = 0x10C630u;
label_10c630:
    // 0x10c630: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c630u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c634: 0x8fa60030  lw          $a2, 0x30($sp)
    ctx->pc = 0x10c634u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10c638: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c638u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c63c: 0xc0420a0  jal         func_108280
    ctx->pc = 0x10C63Cu;
    SET_GPR_U32(ctx, 31, 0x10C644u);
    ctx->pc = 0x10C640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C63Cu;
            // 0x10c640: 0xafa2003c  sw          $v0, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108280u;
    if (runtime->hasFunction(0x108280u)) {
        auto targetFn = runtime->lookupFunction(0x108280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C644u; }
        if (ctx->pc != 0x10C644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108280_0x108280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C644u; }
        if (ctx->pc != 0x10C644u) { return; }
    }
    ctx->pc = 0x10C644u;
label_10c644:
    // 0x10c644: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c644u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c648: 0x8fa50030  lw          $a1, 0x30($sp)
    ctx->pc = 0x10c648u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10c64c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C64Cu;
    SET_GPR_U32(ctx, 31, 0x10C654u);
    ctx->pc = 0x10C650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C64Cu;
            // 0x10c650: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C654u; }
        if (ctx->pc != 0x10C654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C654u; }
        if (ctx->pc != 0x10C654u) { return; }
    }
    ctx->pc = 0x10C654u;
label_10c654:
    // 0x10c654: 0xafb00030  sw          $s0, 0x30($sp)
    ctx->pc = 0x10c654u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
label_10c658:
    // 0x10c658: 0x1a400005  blez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x10C658u;
    {
        const bool branch_taken_0x10c658 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x10C65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C658u;
            // 0x10c65c: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c658) {
            ctx->pc = 0x10C670u;
            goto label_10c670;
        }
    }
    ctx->pc = 0x10C660u;
    // 0x10c660: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x10c660u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c664: 0xc042164  jal         func_108590
    ctx->pc = 0x10C664u;
    SET_GPR_U32(ctx, 31, 0x10C66Cu);
    ctx->pc = 0x10C668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C664u;
            // 0x10c668: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C66Cu; }
        if (ctx->pc != 0x10C66Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C66Cu; }
        if (ctx->pc != 0x10C66Cu) { return; }
    }
    ctx->pc = 0x10C66Cu;
label_10c66c:
    // 0x10c66c: 0xafa20030  sw          $v0, 0x30($sp)
    ctx->pc = 0x10c66cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
label_10c670:
    // 0x10c670: 0x1ae00005  blez        $s7, . + 4 + (0x5 << 2)
    ctx->pc = 0x10C670u;
    {
        const bool branch_taken_0x10c670 = (GPR_S64(ctx, 23) <= 0);
        ctx->pc = 0x10C674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C670u;
            // 0x10c674: 0x8fa50034  lw          $a1, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c670) {
            ctx->pc = 0x10C688u;
            goto label_10c688;
        }
    }
    ctx->pc = 0x10C678u;
    // 0x10c678: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x10c678u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c67c: 0xc042124  jal         func_108490
    ctx->pc = 0x10C67Cu;
    SET_GPR_U32(ctx, 31, 0x10C684u);
    ctx->pc = 0x10C680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C67Cu;
            // 0x10c680: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C684u; }
        if (ctx->pc != 0x10C684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C684u; }
        if (ctx->pc != 0x10C684u) { return; }
    }
    ctx->pc = 0x10C684u;
label_10c684:
    // 0x10c684: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x10c684u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
label_10c688:
    // 0x10c688: 0x1a200005  blez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x10C688u;
    {
        const bool branch_taken_0x10c688 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x10C68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C688u;
            // 0x10c68c: 0x8fa50034  lw          $a1, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c688) {
            ctx->pc = 0x10C6A0u;
            goto label_10c6a0;
        }
    }
    ctx->pc = 0x10C690u;
    // 0x10c690: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10c690u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c694: 0xc042164  jal         func_108590
    ctx->pc = 0x10C694u;
    SET_GPR_U32(ctx, 31, 0x10C69Cu);
    ctx->pc = 0x10C698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C694u;
            // 0x10c698: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C69Cu; }
        if (ctx->pc != 0x10C69Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C69Cu; }
        if (ctx->pc != 0x10C69Cu) { return; }
    }
    ctx->pc = 0x10C69Cu;
label_10c69c:
    // 0x10c69c: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x10c69cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
label_10c6a0:
    // 0x10c6a0: 0x1aa00007  blez        $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x10C6A0u;
    {
        const bool branch_taken_0x10c6a0 = (GPR_S64(ctx, 21) <= 0);
        ctx->pc = 0x10C6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C6A0u;
            // 0x10c6a4: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c6a0) {
            ctx->pc = 0x10C6C0u;
            goto label_10c6c0;
        }
    }
    ctx->pc = 0x10C6A8u;
    // 0x10c6a8: 0x8fa5003c  lw          $a1, 0x3C($sp)
    ctx->pc = 0x10c6a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x10c6ac: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x10c6acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c6b0: 0xc042164  jal         func_108590
    ctx->pc = 0x10C6B0u;
    SET_GPR_U32(ctx, 31, 0x10C6B8u);
    ctx->pc = 0x10C6B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C6B0u;
            // 0x10c6b4: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6B8u; }
        if (ctx->pc != 0x10C6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6B8u; }
        if (ctx->pc != 0x10C6B8u) { return; }
    }
    ctx->pc = 0x10C6B8u;
label_10c6b8:
    // 0x10c6b8: 0xafa2003c  sw          $v0, 0x3C($sp)
    ctx->pc = 0x10c6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
    // 0x10c6bc: 0x8fa50030  lw          $a1, 0x30($sp)
    ctx->pc = 0x10c6bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_10c6c0:
    // 0x10c6c0: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c6c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c6c4: 0xc0421d4  jal         func_108750
    ctx->pc = 0x10C6C4u;
    SET_GPR_U32(ctx, 31, 0x10C6CCu);
    ctx->pc = 0x10C6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C6C4u;
            // 0x10c6c8: 0x8fa60034  lw          $a2, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108750u;
    if (runtime->hasFunction(0x108750u)) {
        auto targetFn = runtime->lookupFunction(0x108750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6CCu; }
        if (ctx->pc != 0x10C6CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108750_0x108750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6CCu; }
        if (ctx->pc != 0x10C6CCu) { return; }
    }
    ctx->pc = 0x10C6CCu;
label_10c6cc:
    // 0x10c6cc: 0xafa20040  sw          $v0, 0x40($sp)
    ctx->pc = 0x10c6ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
    // 0x10c6d0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c6d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c6d4: 0x8fa5003c  lw          $a1, 0x3C($sp)
    ctx->pc = 0x10c6d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x10c6d8: 0x8c55000c  lw          $s5, 0xC($v0)
    ctx->pc = 0x10c6d8u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x10c6dc: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x10C6DCu;
    SET_GPR_U32(ctx, 31, 0x10C6E4u);
    ctx->pc = 0x10C6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C6DCu;
            // 0x10c6e0: 0xac80000c  sw          $zero, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6E4u; }
        if (ctx->pc != 0x10C6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C6E4u; }
        if (ctx->pc != 0x10C6E4u) { return; }
    }
    ctx->pc = 0x10C6E4u;
label_10c6e4:
    // 0x10c6e4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c6e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c6e8: 0x481fe65  bgez        $a0, . + 4 + (-0x19B << 2)
    ctx->pc = 0x10C6E8u;
    {
        const bool branch_taken_0x10c6e8 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x10c6e8) {
            ctx->pc = 0x10C080u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c080;
        }
    }
    ctx->pc = 0x10C6F0u;
    // 0x10c6f0: 0x16a00007  bnez        $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x10C6F0u;
    {
        const bool branch_taken_0x10c6f0 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C6F0u;
            // 0x10c6f4: 0x8fa50030  lw          $a1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c6f0) {
            ctx->pc = 0x10C710u;
            goto label_10c710;
        }
    }
    ctx->pc = 0x10C6F8u;
    // 0x10c6f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10c6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c6fc: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x10c6fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x10c700: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x10c700u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x10c704: 0x1040fe52  beqz        $v0, . + 4 + (-0x1AE << 2)
    ctx->pc = 0x10C704u;
    {
        const bool branch_taken_0x10c704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C704u;
            // 0x10c708: 0x8fa50040  lw          $a1, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c704) {
            ctx->pc = 0x10C050u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c050;
        }
    }
    ctx->pc = 0x10C70Cu;
label_10c70c:
    // 0x10c70c: 0x8fa50030  lw          $a1, 0x30($sp)
    ctx->pc = 0x10c70cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_10c710:
    // 0x10c710: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C710u;
    SET_GPR_U32(ctx, 31, 0x10C718u);
    ctx->pc = 0x10C714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C710u;
            // 0x10c714: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C718u; }
        if (ctx->pc != 0x10C718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C718u; }
        if (ctx->pc != 0x10C718u) { return; }
    }
    ctx->pc = 0x10C718u;
label_10c718:
    // 0x10c718: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c71c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C71Cu;
    SET_GPR_U32(ctx, 31, 0x10C724u);
    ctx->pc = 0x10C720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C71Cu;
            // 0x10c720: 0x8fa50034  lw          $a1, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C724u; }
        if (ctx->pc != 0x10C724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C724u; }
        if (ctx->pc != 0x10C724u) { return; }
    }
    ctx->pc = 0x10C724u;
label_10c724:
    // 0x10c724: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c724u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c728: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C728u;
    SET_GPR_U32(ctx, 31, 0x10C730u);
    ctx->pc = 0x10C72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C728u;
            // 0x10c72c: 0x8fa5003c  lw          $a1, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C730u; }
        if (ctx->pc != 0x10C730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C730u; }
        if (ctx->pc != 0x10C730u) { return; }
    }
    ctx->pc = 0x10C730u;
label_10c730:
    // 0x10c730: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c730u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c734: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C734u;
    SET_GPR_U32(ctx, 31, 0x10C73Cu);
    ctx->pc = 0x10C738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C734u;
            // 0x10c738: 0x8fa50038  lw          $a1, 0x38($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C73Cu; }
        if (ctx->pc != 0x10C73Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C73Cu; }
        if (ctx->pc != 0x10C73Cu) { return; }
    }
    ctx->pc = 0x10C73Cu;
label_10c73c:
    // 0x10c73c: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10c73cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c740: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10C740u;
    SET_GPR_U32(ctx, 31, 0x10C748u);
    ctx->pc = 0x10C744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C740u;
            // 0x10c744: 0x8fa50040  lw          $a1, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C748u; }
        if (ctx->pc != 0x10C748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C748u; }
        if (ctx->pc != 0x10C748u) { return; }
    }
    ctx->pc = 0x10C748u;
label_10c748:
    // 0x10c748: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x10c748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_10c74c:
    // 0x10c74c: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10C74Cu;
    {
        const bool branch_taken_0x10c74c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c74c) {
            ctx->pc = 0x10C750u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C74Cu;
            // 0x10c750: 0xac760000  sw          $s6, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C754u;
            goto label_10c754;
        }
    }
    ctx->pc = 0x10C754u;
label_10c754:
    // 0x10c754: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x10c754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x10c758: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x10c758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c75c: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10C75Cu;
    {
        const bool branch_taken_0x10c75c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C75Cu;
            // 0x10c760: 0xdfb00050  ld          $s0, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c75c) {
            ctx->pc = 0x10C778u;
            goto label_10c778;
        }
    }
    ctx->pc = 0x10C764u;
    // 0x10c764: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10c764u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c768: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10c768u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c76c: 0xc044752  jal         func_111D48
    ctx->pc = 0x10C76Cu;
    SET_GPR_U32(ctx, 31, 0x10C774u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C774u; }
        if (ctx->pc != 0x10C774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C774u; }
        if (ctx->pc != 0x10C774u) { return; }
    }
    ctx->pc = 0x10C774u;
label_10c774:
    // 0x10c774: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x10c774u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_10c778:
    // 0x10c778: 0xdfb10058  ld          $s1, 0x58($sp)
    ctx->pc = 0x10c778u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x10c77c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x10c77cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10c780: 0xdfb30068  ld          $s3, 0x68($sp)
    ctx->pc = 0x10c780u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x10c784: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x10c784u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x10c788: 0xdfb50078  ld          $s5, 0x78($sp)
    ctx->pc = 0x10c788u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x10c78c: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x10c78cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x10c790: 0xdfb70088  ld          $s7, 0x88($sp)
    ctx->pc = 0x10c790u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x10c794: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x10c794u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x10c798: 0xdfbf0098  ld          $ra, 0x98($sp)
    ctx->pc = 0x10c798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x10c79c: 0x3e00008  jr          $ra
    ctx->pc = 0x10C79Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10C7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C79Cu;
            // 0x10c7a0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B820u: goto label_10b820;
            case 0x10B828u: goto label_10b828;
            case 0x10B850u: goto label_10b850;
            case 0x10B878u: goto label_10b878;
            case 0x10B8D8u: goto label_10b8d8;
            case 0x10B900u: goto label_10b900;
            case 0x10B908u: goto label_10b908;
            case 0x10B920u: goto label_10b920;
            case 0x10B928u: goto label_10b928;
            case 0x10B940u: goto label_10b940;
            case 0x10B964u: goto label_10b964;
            case 0x10B988u: goto label_10b988;
            case 0x10B9B0u: goto label_10b9b0;
            case 0x10B9CCu: goto label_10b9cc;
            case 0x10B9D0u: goto label_10b9d0;
            case 0x10B9DCu: goto label_10b9dc;
            case 0x10B9F4u: goto label_10b9f4;
            case 0x10BA18u: goto label_10ba18;
            case 0x10BA38u: goto label_10ba38;
            case 0x10BA58u: goto label_10ba58;
            case 0x10BA68u: goto label_10ba68;
            case 0x10BA88u: goto label_10ba88;
            case 0x10BAB0u: goto label_10bab0;
            case 0x10BAC8u: goto label_10bac8;
            case 0x10BACCu: goto label_10bacc;
            case 0x10BAD4u: goto label_10bad4;
            case 0x10BB00u: goto label_10bb00;
            case 0x10BB1Cu: goto label_10bb1c;
            case 0x10BB20u: goto label_10bb20;
            case 0x10BB3Cu: goto label_10bb3c;
            case 0x10BB40u: goto label_10bb40;
            case 0x10BB54u: goto label_10bb54;
            case 0x10BB70u: goto label_10bb70;
            case 0x10BB94u: goto label_10bb94;
            case 0x10BBA0u: goto label_10bba0;
            case 0x10BBC0u: goto label_10bbc0;
            case 0x10BBE0u: goto label_10bbe0;
            case 0x10BC0Cu: goto label_10bc0c;
            case 0x10BC48u: goto label_10bc48;
            case 0x10BC6Cu: goto label_10bc6c;
            case 0x10BC84u: goto label_10bc84;
            case 0x10BC90u: goto label_10bc90;
            case 0x10BCC0u: goto label_10bcc0;
            case 0x10BCE0u: goto label_10bce0;
            case 0x10BCE4u: goto label_10bce4;
            case 0x10BD10u: goto label_10bd10;
            case 0x10BD24u: goto label_10bd24;
            case 0x10BD30u: goto label_10bd30;
            case 0x10BD3Cu: goto label_10bd3c;
            case 0x10BD4Cu: goto label_10bd4c;
            case 0x10BD5Cu: goto label_10bd5c;
            case 0x10BD64u: goto label_10bd64;
            case 0x10BD94u: goto label_10bd94;
            case 0x10BD98u: goto label_10bd98;
            case 0x10BDB4u: goto label_10bdb4;
            case 0x10BDD8u: goto label_10bdd8;
            case 0x10BDF0u: goto label_10bdf0;
            case 0x10BE0Cu: goto label_10be0c;
            case 0x10BE10u: goto label_10be10;
            case 0x10BE28u: goto label_10be28;
            case 0x10BE30u: goto label_10be30;
            case 0x10BE60u: goto label_10be60;
            case 0x10BEA8u: goto label_10bea8;
            case 0x10BEC0u: goto label_10bec0;
            case 0x10BEF0u: goto label_10bef0;
            case 0x10BEF4u: goto label_10bef4;
            case 0x10BF28u: goto label_10bf28;
            case 0x10BF44u: goto label_10bf44;
            case 0x10BF48u: goto label_10bf48;
            case 0x10BF60u: goto label_10bf60;
            case 0x10BF68u: goto label_10bf68;
            case 0x10BF8Cu: goto label_10bf8c;
            case 0x10BFA0u: goto label_10bfa0;
            case 0x10BFB8u: goto label_10bfb8;
            case 0x10BFC8u: goto label_10bfc8;
            case 0x10BFD8u: goto label_10bfd8;
            case 0x10BFE0u: goto label_10bfe0;
            case 0x10BFE4u: goto label_10bfe4;
            case 0x10C000u: goto label_10c000;
            case 0x10C00Cu: goto label_10c00c;
            case 0x10C01Cu: goto label_10c01c;
            case 0x10C028u: goto label_10c028;
            case 0x10C02Cu: goto label_10c02c;
            case 0x10C040u: goto label_10c040;
            case 0x10C050u: goto label_10c050;
            case 0x10C05Cu: goto label_10c05c;
            case 0x10C06Cu: goto label_10c06c;
            case 0x10C080u: goto label_10c080;
            case 0x10C0D8u: goto label_10c0d8;
            case 0x10C0ECu: goto label_10c0ec;
            case 0x10C130u: goto label_10c130;
            case 0x10C158u: goto label_10c158;
            case 0x10C168u: goto label_10c168;
            case 0x10C17Cu: goto label_10c17c;
            case 0x10C190u: goto label_10c190;
            case 0x10C198u: goto label_10c198;
            case 0x10C1B0u: goto label_10c1b0;
            case 0x10C1D8u: goto label_10c1d8;
            case 0x10C210u: goto label_10c210;
            case 0x10C224u: goto label_10c224;
            case 0x10C240u: goto label_10c240;
            case 0x10C254u: goto label_10c254;
            case 0x10C258u: goto label_10c258;
            case 0x10C268u: goto label_10c268;
            case 0x10C270u: goto label_10c270;
            case 0x10C288u: goto label_10c288;
            case 0x10C2A8u: goto label_10c2a8;
            case 0x10C2ACu: goto label_10c2ac;
            case 0x10C2BCu: goto label_10c2bc;
            case 0x10C2C0u: goto label_10c2c0;
            case 0x10C304u: goto label_10c304;
            case 0x10C314u: goto label_10c314;
            case 0x10C324u: goto label_10c324;
            case 0x10C380u: goto label_10c380;
            case 0x10C398u: goto label_10c398;
            case 0x10C3C0u: goto label_10c3c0;
            case 0x10C3DCu: goto label_10c3dc;
            case 0x10C3E8u: goto label_10c3e8;
            case 0x10C3F0u: goto label_10c3f0;
            case 0x10C40Cu: goto label_10c40c;
            case 0x10C410u: goto label_10c410;
            case 0x10C41Cu: goto label_10c41c;
            case 0x10C42Cu: goto label_10c42c;
            case 0x10C43Cu: goto label_10c43c;
            case 0x10C440u: goto label_10c440;
            case 0x10C46Cu: goto label_10c46c;
            case 0x10C474u: goto label_10c474;
            case 0x10C484u: goto label_10c484;
            case 0x10C4A4u: goto label_10c4a4;
            case 0x10C4B8u: goto label_10c4b8;
            case 0x10C4D4u: goto label_10c4d4;
            case 0x10C4E8u: goto label_10c4e8;
            case 0x10C4FCu: goto label_10c4fc;
            case 0x10C504u: goto label_10c504;
            case 0x10C508u: goto label_10c508;
            case 0x10C510u: goto label_10c510;
            case 0x10C51Cu: goto label_10c51c;
            case 0x10C528u: goto label_10c528;
            case 0x10C534u: goto label_10c534;
            case 0x10C544u: goto label_10c544;
            case 0x10C564u: goto label_10c564;
            case 0x10C578u: goto label_10c578;
            case 0x10C588u: goto label_10c588;
            case 0x10C5A8u: goto label_10c5a8;
            case 0x10C5BCu: goto label_10c5bc;
            case 0x10C5CCu: goto label_10c5cc;
            case 0x10C5F0u: goto label_10c5f0;
            case 0x10C620u: goto label_10c620;
            case 0x10C630u: goto label_10c630;
            case 0x10C644u: goto label_10c644;
            case 0x10C654u: goto label_10c654;
            case 0x10C658u: goto label_10c658;
            case 0x10C66Cu: goto label_10c66c;
            case 0x10C670u: goto label_10c670;
            case 0x10C684u: goto label_10c684;
            case 0x10C688u: goto label_10c688;
            case 0x10C69Cu: goto label_10c69c;
            case 0x10C6A0u: goto label_10c6a0;
            case 0x10C6B8u: goto label_10c6b8;
            case 0x10C6C0u: goto label_10c6c0;
            case 0x10C6CCu: goto label_10c6cc;
            case 0x10C6E4u: goto label_10c6e4;
            case 0x10C70Cu: goto label_10c70c;
            case 0x10C710u: goto label_10c710;
            case 0x10C718u: goto label_10c718;
            case 0x10C724u: goto label_10c724;
            case 0x10C730u: goto label_10c730;
            case 0x10C73Cu: goto label_10c73c;
            case 0x10C748u: goto label_10c748;
            case 0x10C74Cu: goto label_10c74c;
            case 0x10C754u: goto label_10c754;
            case 0x10C774u: goto label_10c774;
            case 0x10C778u: goto label_10c778;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10C7A4u;
    // 0x10c7a4: 0x0  nop
    ctx->pc = 0x10c7a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
