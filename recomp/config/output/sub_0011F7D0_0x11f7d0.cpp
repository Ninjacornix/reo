#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F7D0
// Address: 0x11f7d0 - 0x120ae8
void sub_0011F7D0_0x11f7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F7D0_0x11f7d0");
#endif

    switch (ctx->pc) {
        case 0x11f820u: goto label_11f820;
        case 0x11f848u: goto label_11f848;
        case 0x11f900u: goto label_11f900;
        case 0x11fac8u: goto label_11fac8;
        case 0x11fad4u: goto label_11fad4;
        case 0x11fae0u: goto label_11fae0;
        case 0x11fb60u: goto label_11fb60;
        case 0x11fb74u: goto label_11fb74;
        case 0x11fb90u: goto label_11fb90;
        case 0x11fba4u: goto label_11fba4;
        case 0x11fc4cu: goto label_11fc4c;
        case 0x11fc5cu: goto label_11fc5c;
        case 0x11fc78u: goto label_11fc78;
        case 0x11fca4u: goto label_11fca4;
        case 0x11fd10u: goto label_11fd10;
        case 0x11fd3cu: goto label_11fd3c;
        case 0x11fd58u: goto label_11fd58;
        case 0x11fd70u: goto label_11fd70;
        case 0x11fd88u: goto label_11fd88;
        case 0x11fd98u: goto label_11fd98;
        case 0x11fdb0u: goto label_11fdb0;
        case 0x11fdc8u: goto label_11fdc8;
        case 0x11fddcu: goto label_11fddc;
        case 0x11fdecu: goto label_11fdec;
        case 0x11fe08u: goto label_11fe08;
        case 0x11fe18u: goto label_11fe18;
        case 0x11fe30u: goto label_11fe30;
        case 0x11fe48u: goto label_11fe48;
        case 0x11fe58u: goto label_11fe58;
        case 0x11fe68u: goto label_11fe68;
        case 0x11fe8cu: goto label_11fe8c;
        case 0x11fe9cu: goto label_11fe9c;
        case 0x11fea8u: goto label_11fea8;
        case 0x11febcu: goto label_11febc;
        case 0x11fed8u: goto label_11fed8;
        case 0x11fef0u: goto label_11fef0;
        case 0x11ff04u: goto label_11ff04;
        case 0x11ff14u: goto label_11ff14;
        case 0x11ff28u: goto label_11ff28;
        case 0x11ff38u: goto label_11ff38;
        case 0x11ff50u: goto label_11ff50;
        case 0x11ff64u: goto label_11ff64;
        case 0x11ff74u: goto label_11ff74;
        case 0x11ff88u: goto label_11ff88;
        case 0x11ff98u: goto label_11ff98;
        case 0x11ffacu: goto label_11ffac;
        case 0x11ffbcu: goto label_11ffbc;
        case 0x11ffccu: goto label_11ffcc;
        case 0x11ffecu: goto label_11ffec;
        case 0x11fffcu: goto label_11fffc;
        case 0x120018u: goto label_120018;
        case 0x120028u: goto label_120028;
        case 0x120038u: goto label_120038;
        case 0x120054u: goto label_120054;
        case 0x120068u: goto label_120068;
        case 0x120078u: goto label_120078;
        case 0x120090u: goto label_120090;
        case 0x1200a0u: goto label_1200a0;
        case 0x1200b0u: goto label_1200b0;
        case 0x1200c0u: goto label_1200c0;
        case 0x1200e8u: goto label_1200e8;
        case 0x1200f8u: goto label_1200f8;
        case 0x120108u: goto label_120108;
        case 0x120124u: goto label_120124;
        case 0x120138u: goto label_120138;
        case 0x120148u: goto label_120148;
        case 0x120160u: goto label_120160;
        case 0x120170u: goto label_120170;
        case 0x120180u: goto label_120180;
        case 0x120190u: goto label_120190;
        case 0x120210u: goto label_120210;
        case 0x120220u: goto label_120220;
        case 0x120260u: goto label_120260;
        case 0x120270u: goto label_120270;
        case 0x120288u: goto label_120288;
        case 0x1202b8u: goto label_1202b8;
        case 0x120350u: goto label_120350;
        case 0x120388u: goto label_120388;
        case 0x120414u: goto label_120414;
        case 0x120440u: goto label_120440;
        case 0x120774u: goto label_120774;
        case 0x1207d8u: goto label_1207d8;
        case 0x120a2cu: goto label_120a2c;
        case 0x120a34u: goto label_120a34;
        default: break;
    }

    ctx->pc = 0x11f7d0u;

    // 0x11f7d0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11f7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11f7d4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f7d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11f7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11f7dc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x11f7dcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f7e0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f7e4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f7e8: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11F7E8u;
    {
        const bool branch_taken_0x11f7e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F7ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7E8u;
            // 0x11f7ec: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f7e8) {
            ctx->pc = 0x11F800u;
            goto label_11f800;
        }
    }
    ctx->pc = 0x11F7F0u;
    // 0x11f7f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11f7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11f7f4: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x11f7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11f7f8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11F7F8u;
    {
        const bool branch_taken_0x11f7f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7F8u;
            // 0x11f7fc: 0x24421d08  addiu       $v0, $v0, 0x1D08 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f7f8) {
            ctx->pc = 0x11F810u;
            goto label_11f810;
        }
    }
    ctx->pc = 0x11F800u;
label_11f800:
    // 0x11f800: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11f800u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11f804: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f804u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f808: 0x8c42b408  lw          $v0, -0x4BF8($v0)
    ctx->pc = 0x11f808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947848)));
    // 0x11f80c: 0x8c63b40c  lw          $v1, -0x4BF4($v1)
    ctx->pc = 0x11f80cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947852)));
label_11f810:
    // 0x11f810: 0x380902d  daddu       $s2, $gp, $zero
    ctx->pc = 0x11f810u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f814: 0x1860000f  blez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x11F814u;
    {
        const bool branch_taken_0x11f814 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x11F818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F814u;
            // 0x11f818: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f814) {
            ctx->pc = 0x11F854u;
            goto label_11f854;
        }
    }
    ctx->pc = 0x11F81Cu;
    // 0x11f81c: 0x60882d  daddu       $s1, $v1, $zero
    ctx->pc = 0x11f81cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_11f820:
    // 0x11f820: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x11f820u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11f824: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x11F824u;
    {
        const bool branch_taken_0x11f824 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f824) {
            ctx->pc = 0x11F828u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F824u;
            // 0x11f828: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F84Cu;
            goto label_11f84c;
        }
    }
    ctx->pc = 0x11F82Cu;
    // 0x11f82c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11f82cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11f830: 0x380182d  daddu       $v1, $gp, $zero
    ctx->pc = 0x11f830u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f834: 0x40e02d  daddu       $gp, $v0, $zero
    ctx->pc = 0x11f834u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f838: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x11f838u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11f83c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x11f83cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f840: 0xc0f809  jalr        $a2
    ctx->pc = 0x11F840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x11F848u);
        ctx->pc = 0x11F844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F840u;
            // 0x11f844: 0x8e050004  lw          $a1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11F848u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11F848u; }
            if (ctx->pc != 0x11F848u) { return; }
        }
        }
    }
    ctx->pc = 0x11F848u;
label_11f848:
    // 0x11f848: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x11f848u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_11f84c:
    // 0x11f84c: 0x1620fff4  bnez        $s1, . + 4 + (-0xC << 2)
    ctx->pc = 0x11F84Cu;
    {
        const bool branch_taken_0x11f84c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F84Cu;
            // 0x11f850: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f84c) {
            ctx->pc = 0x11F820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11f820;
        }
    }
    ctx->pc = 0x11F854u;
label_11f854:
    // 0x11f854: 0x380102d  daddu       $v0, $gp, $zero
    ctx->pc = 0x11f854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f858: 0x240e02d  daddu       $gp, $s2, $zero
    ctx->pc = 0x11f858u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f85c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11f85cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f860: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f860u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f864: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f864u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f868: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f868u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f86c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f86cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f870: 0x3e00008  jr          $ra
    ctx->pc = 0x11F870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F870u;
            // 0x11f874: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F878u;
    // 0x11f878: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11f878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11f87c: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x11f87cu;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f880: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f884: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x11f884u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f888: 0x3383c  dsll32      $a3, $v1, 0
    ctx->pc = 0x11f888u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11f88c: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x11f88cu;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x11f890: 0x3583f  dsra32      $t3, $v1, 0
    ctx->pc = 0x11f890u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x11f894: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f894u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f898: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f898u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f89c: 0x1624824  and         $t1, $t3, $v0
    ctx->pc = 0x11f89cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 11) & GPR_U64(ctx, 2));
    // 0x11f8a0: 0x180182d  daddu       $v1, $t4, $zero
    ctx->pc = 0x11f8a0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8a4: 0x3303c  dsll32      $a2, $v1, 0
    ctx->pc = 0x11f8a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11f8a8: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x11f8a8u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x11f8ac: 0x3503f  dsra32      $t2, $v1, 0
    ctx->pc = 0x11f8acu;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x11f8b0: 0x1424024  and         $t0, $t2, $v0
    ctx->pc = 0x11f8b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x11f8b4: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x11f8b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x11f8b8: 0x71023  negu        $v0, $a3
    ctx->pc = 0x11f8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 7)));
    // 0x11f8bc: 0xe21025  or          $v0, $a3, $v0
    ctx->pc = 0x11f8bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x11f8c0: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x11f8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x11f8c4: 0x1221025  or          $v0, $t1, $v0
    ctx->pc = 0x11f8c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x11f8c8: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x11f8c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f8cc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F8CCu;
    {
        const bool branch_taken_0x11f8cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F8CCu;
            // 0x11f8d0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f8cc) {
            ctx->pc = 0x11F8F0u;
            goto label_11f8f0;
        }
    }
    ctx->pc = 0x11F8D4u;
    // 0x11f8d4: 0x61023  negu        $v0, $a2
    ctx->pc = 0x11f8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 6)));
    // 0x11f8d8: 0xc21025  or          $v0, $a2, $v0
    ctx->pc = 0x11f8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x11f8dc: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x11f8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x11f8e0: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x11f8e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x11f8e4: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x11f8e4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f8e8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F8E8u;
    {
        const bool branch_taken_0x11f8e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f8e8) {
            ctx->pc = 0x11F8ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F8E8u;
            // 0x11f8ec: 0x3c02c010  lui         $v0, 0xC010 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49168 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F908u;
            goto label_11f908;
        }
    }
    ctx->pc = 0x11F8F0u;
label_11f8f0:
    // 0x11f8f0: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x11f8f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8f4: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x11f8f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8f8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11F8F8u;
    SET_GPR_U32(ctx, 31, 0x11F900u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F900u; }
        if (ctx->pc != 0x11F900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F900u; }
        if (ctx->pc != 0x11F900u) { return; }
    }
    ctx->pc = 0x11F900u;
label_11f900:
    // 0x11f900: 0x100000a9  b           . + 4 + (0xA9 << 2)
    ctx->pc = 0x11F900u;
    {
        const bool branch_taken_0x11f900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F900u;
            // 0x11f904: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f900) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F908u;
label_11f908:
    // 0x11f908: 0x1621021  addu        $v0, $t3, $v0
    ctx->pc = 0x11f908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x11f90c: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x11f90cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x11f910: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x11F910u;
    {
        const bool branch_taken_0x11f910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f910) {
            ctx->pc = 0x11F914u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F910u;
            // 0x11f914: 0xb1783  sra         $v0, $t3, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 11), 30));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F928u;
            goto label_11f928;
        }
    }
    ctx->pc = 0x11F918u;
    // 0x11f918: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f918u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f91c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x11f91cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x11f920: 0x804868a  j           func_121A28
    ctx->pc = 0x11F920u;
    ctx->pc = 0x11F924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F920u;
            // 0x11f924: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x121A28u;
    if (runtime->hasFunction(0x121A28u)) {
        auto targetFn = runtime->lookupFunction(0x121A28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00121A28_0x121a28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11F928u;
label_11f928:
    // 0x11f928: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x11f928u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x11f92c: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x11f92cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x11f930: 0x1062025  or          $a0, $t0, $a2
    ctx->pc = 0x11f930u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) | GPR_U64(ctx, 6));
    // 0x11f934: 0x14800012  bnez        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x11F934u;
    {
        const bool branch_taken_0x11f934 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F934u;
            // 0x11f938: 0x628025  or          $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f934) {
            ctx->pc = 0x11F980u;
            goto label_11f980;
        }
    }
    ctx->pc = 0x11F93Cu;
    // 0x11f93c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x11f93cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11f940: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f944: 0xdc228c90  ld          $v0, -0x7370($at)
    ctx->pc = 0x11f944u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937744)));
    // 0x11f948: 0x52030097  beql        $s0, $v1, . + 4 + (0x97 << 2)
    ctx->pc = 0x11F948u;
    {
        const bool branch_taken_0x11f948 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f948) {
            ctx->pc = 0x11F94Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F948u;
            // 0x11f94c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F950u;
    // 0x11f950: 0x2a020003  slti        $v0, $s0, 0x3
    ctx->pc = 0x11f950u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x11f954: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F954u;
    {
        const bool branch_taken_0x11f954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f954) {
            ctx->pc = 0x11F958u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F954u;
            // 0x11f958: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F970u;
            goto label_11f970;
        }
    }
    ctx->pc = 0x11F95Cu;
    // 0x11f95c: 0x6020009  bltzl       $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11F95Cu;
    {
        const bool branch_taken_0x11f95c = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x11f95c) {
            ctx->pc = 0x11F960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F95Cu;
            // 0x11f960: 0x1271025  or          $v0, $t1, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F984u;
            goto label_11f984;
        }
    }
    ctx->pc = 0x11F964u;
    // 0x11f964: 0x180102d  daddu       $v0, $t4, $zero
    ctx->pc = 0x11f964u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f968: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x11F968u;
    {
        const bool branch_taken_0x11f968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F968u;
            // 0x11f96c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f968) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F970u;
label_11f970:
    // 0x11f970: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f970u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f974: 0xdc228c98  ld          $v0, -0x7368($at)
    ctx->pc = 0x11f974u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937752)));
    // 0x11f978: 0x5203008b  beql        $s0, $v1, . + 4 + (0x8B << 2)
    ctx->pc = 0x11F978u;
    {
        const bool branch_taken_0x11f978 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f978) {
            ctx->pc = 0x11F97Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F978u;
            // 0x11f97c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F980u;
label_11f980:
    // 0x11f980: 0x1271025  or          $v0, $t1, $a3
    ctx->pc = 0x11f980u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
label_11f984:
    // 0x11f984: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x11F984u;
    {
        const bool branch_taken_0x11f984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F984u;
            // 0x11f988: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f984) {
            ctx->pc = 0x11FA70u;
            goto label_11fa70;
        }
    }
    ctx->pc = 0x11F98Cu;
    // 0x11f98c: 0x15220036  bne         $t1, $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x11F98Cu;
    {
        const bool branch_taken_0x11f98c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        if (branch_taken_0x11f98c) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F994u;
    // 0x11f994: 0x1509001c  bne         $t0, $t1, . + 4 + (0x1C << 2)
    ctx->pc = 0x11F994u;
    {
        const bool branch_taken_0x11f994 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 9));
        ctx->pc = 0x11F998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F994u;
            // 0x11f998: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f994) {
            ctx->pc = 0x11FA08u;
            goto label_11fa08;
        }
    }
    ctx->pc = 0x11F99Cu;
    // 0x11f99c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x11f99cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11f9a0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9a4: 0xdc228ca0  ld          $v0, -0x7360($at)
    ctx->pc = 0x11f9a4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937760)));
    // 0x11f9a8: 0x5203007f  beql        $s0, $v1, . + 4 + (0x7F << 2)
    ctx->pc = 0x11F9A8u;
    {
        const bool branch_taken_0x11f9a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f9a8) {
            ctx->pc = 0x11F9ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9A8u;
            // 0x11f9ac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9B0u;
    // 0x11f9b0: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11f9b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11f9b4: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F9B4u;
    {
        const bool branch_taken_0x11f9b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f9b4) {
            ctx->pc = 0x11F9B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9B4u;
            // 0x11f9b8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F9D8u;
            goto label_11f9d8;
        }
    }
    ctx->pc = 0x11F9BCu;
    // 0x11f9bc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9c0: 0xdc228ca8  ld          $v0, -0x7358($at)
    ctx->pc = 0x11f9c0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937768)));
    // 0x11f9c4: 0x52000078  beql        $s0, $zero, . + 4 + (0x78 << 2)
    ctx->pc = 0x11F9C4u;
    {
        const bool branch_taken_0x11f9c4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f9c4) {
            ctx->pc = 0x11F9C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9C4u;
            // 0x11f9c8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9CCu;
    // 0x11f9cc: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x11F9CCu;
    {
        const bool branch_taken_0x11f9cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9CCu;
            // 0x11f9d0: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f9cc) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F9D4u;
    // 0x11f9d4: 0x0  nop
    ctx->pc = 0x11f9d4u;
    // NOP
label_11f9d8:
    // 0x11f9d8: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9dc: 0xdc228cb0  ld          $v0, -0x7350($at)
    ctx->pc = 0x11f9dcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937776)));
    // 0x11f9e0: 0x52030071  beql        $s0, $v1, . + 4 + (0x71 << 2)
    ctx->pc = 0x11F9E0u;
    {
        const bool branch_taken_0x11f9e0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f9e0) {
            ctx->pc = 0x11F9E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9E0u;
            // 0x11f9e4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9E8u;
    // 0x11f9e8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x11f9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x11f9ec: 0x5602001e  bnel        $s0, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11F9ECu;
    {
        const bool branch_taken_0x11f9ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x11f9ec) {
            ctx->pc = 0x11F9F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9ECu;
            // 0x11f9f0: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F9F4u;
    // 0x11f9f4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9f8: 0xdc228cb8  ld          $v0, -0x7348($at)
    ctx->pc = 0x11f9f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937784)));
    // 0x11f9fc: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x11F9FCu;
    {
        const bool branch_taken_0x11f9fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9FCu;
            // 0x11fa00: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f9fc) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA04u;
    // 0x11fa04: 0x0  nop
    ctx->pc = 0x11fa04u;
    // NOP
label_11fa08:
    // 0x11fa08: 0x12020013  beq         $s0, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x11FA08u;
    {
        const bool branch_taken_0x11fa08 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x11FA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA08u;
            // 0x11fa0c: 0x3c030024  lui         $v1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa08) {
            ctx->pc = 0x11FA58u;
            goto label_11fa58;
        }
    }
    ctx->pc = 0x11FA10u;
    // 0x11fa10: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11fa10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11fa14: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FA14u;
    {
        const bool branch_taken_0x11fa14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA14u;
            // 0x11fa18: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa14) {
            ctx->pc = 0x11FA30u;
            goto label_11fa30;
        }
    }
    ctx->pc = 0x11FA1Cu;
    // 0x11fa1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11fa1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fa20: 0x52000061  beql        $s0, $zero, . + 4 + (0x61 << 2)
    ctx->pc = 0x11FA20u;
    {
        const bool branch_taken_0x11fa20 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fa20) {
            ctx->pc = 0x11FA24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA20u;
            // 0x11fa24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA28u;
    // 0x11fa28: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11FA28u;
    {
        const bool branch_taken_0x11fa28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA28u;
            // 0x11fa2c: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa28) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11FA30u;
label_11fa30:
    // 0x11fa30: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa34: 0xdc228cc0  ld          $v0, -0x7340($at)
    ctx->pc = 0x11fa34u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937792)));
    // 0x11fa38: 0x1203005a  beq         $s0, $v1, . + 4 + (0x5A << 2)
    ctx->pc = 0x11FA38u;
    {
        const bool branch_taken_0x11fa38 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x11FA3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA38u;
            // 0x11fa3c: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa38) {
            ctx->pc = 0x11FBA4u;
            goto label_11fba4;
        }
    }
    ctx->pc = 0x11FA40u;
    // 0x11fa40: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa44: 0xdc228cc8  ld          $v0, -0x7338($at)
    ctx->pc = 0x11fa44u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937800)));
    // 0x11fa48: 0x52030057  beql        $s0, $v1, . + 4 + (0x57 << 2)
    ctx->pc = 0x11FA48u;
    {
        const bool branch_taken_0x11fa48 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11fa48) {
            ctx->pc = 0x11FA4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA48u;
            // 0x11fa4c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA50u;
    // 0x11fa50: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11FA50u;
    {
        const bool branch_taken_0x11fa50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA50u;
            // 0x11fa54: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa50) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11FA58u;
label_11fa58:
    // 0x11fa58: 0xdc628c88  ld          $v0, -0x7378($v1)
    ctx->pc = 0x11fa58u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 4294937736)));
    // 0x11fa5c: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x11FA5Cu;
    {
        const bool branch_taken_0x11fa5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA5Cu;
            // 0x11fa60: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa5c) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA64u;
    // 0x11fa64: 0x0  nop
    ctx->pc = 0x11fa64u;
    // NOP
label_11fa68:
    // 0x11fa68: 0x15020009  bne         $t0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11FA68u;
    {
        const bool branch_taken_0x11fa68 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x11FA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA68u;
            // 0x11fa6c: 0x1091823  subu        $v1, $t0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa68) {
            ctx->pc = 0x11FA90u;
            goto label_11fa90;
        }
    }
    ctx->pc = 0x11FA70u;
label_11fa70:
    // 0x11fa70: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa74: 0xdc228cd0  ld          $v0, -0x7330($at)
    ctx->pc = 0x11fa74u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937808)));
    // 0x11fa78: 0x540004a  bltz        $t2, . + 4 + (0x4A << 2)
    ctx->pc = 0x11FA78u;
    {
        const bool branch_taken_0x11fa78 = (GPR_S64(ctx, 10) < 0);
        ctx->pc = 0x11FA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA78u;
            // 0x11fa7c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa78) {
            ctx->pc = 0x11FBA4u;
            goto label_11fba4;
        }
    }
    ctx->pc = 0x11FA80u;
    // 0x11fa80: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa84: 0xdc228cd8  ld          $v0, -0x7328($at)
    ctx->pc = 0x11fa84u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937816)));
    // 0x11fa88: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x11FA88u;
    {
        const bool branch_taken_0x11fa88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA88u;
            // 0x11fa8c: 0xdfbf0008  ld          $ra, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa88) {
            ctx->pc = 0x11FBACu;
            goto label_11fbac;
        }
    }
    ctx->pc = 0x11FA90u;
label_11fa90:
    // 0x11fa90: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa94: 0xdc248ce0  ld          $a0, -0x7320($at)
    ctx->pc = 0x11fa94u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 4294937824)));
    // 0x11fa98: 0x31d03  sra         $v1, $v1, 20
    ctx->pc = 0x11fa98u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 20));
    // 0x11fa9c: 0x2862003d  slti        $v0, $v1, 0x3D
    ctx->pc = 0x11fa9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)61) ? 1 : 0);
    // 0x11faa0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x11FAA0u;
    {
        const bool branch_taken_0x11faa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAA0u;
            // 0x11faa4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faa0) {
            ctx->pc = 0x11FAE8u;
            goto label_11fae8;
        }
    }
    ctx->pc = 0x11FAA8u;
    // 0x11faa8: 0x5610004  bgez        $t3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11FAA8u;
    {
        const bool branch_taken_0x11faa8 = (GPR_S64(ctx, 11) >= 0);
        ctx->pc = 0x11FAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAA8u;
            // 0x11faac: 0x2862ffc4  slti        $v0, $v1, -0x3C (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4294967236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faa8) {
            ctx->pc = 0x11FABCu;
            goto label_11fabc;
        }
    }
    ctx->pc = 0x11FAB0u;
    // 0x11fab0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x11fab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fab4: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11FAB4u;
    {
        const bool branch_taken_0x11fab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAB4u;
            // 0x11fab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fab4) {
            ctx->pc = 0x11FAE8u;
            goto label_11fae8;
        }
    }
    ctx->pc = 0x11FABCu;
label_11fabc:
    // 0x11fabc: 0x180202d  daddu       $a0, $t4, $zero
    ctx->pc = 0x11fabcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fac0: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FAC0u;
    SET_GPR_U32(ctx, 31, 0x11FAC8u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAC8u; }
        if (ctx->pc != 0x11FAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAC8u; }
        if (ctx->pc != 0x11FAC8u) { return; }
    }
    ctx->pc = 0x11FAC8u;
label_11fac8:
    // 0x11fac8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fac8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11facc: 0xc0487bc  jal         func_121EF0
    ctx->pc = 0x11FACCu;
    SET_GPR_U32(ctx, 31, 0x11FAD4u);
    ctx->pc = 0x121EF0u;
    if (runtime->hasFunction(0x121EF0u)) {
        auto targetFn = runtime->lookupFunction(0x121EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAD4u; }
        if (ctx->pc != 0x11FAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121EF0_0x121ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAD4u; }
        if (ctx->pc != 0x11FAD4u) { return; }
    }
    ctx->pc = 0x11FAD4u;
label_11fad4:
    // 0x11fad4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fad4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fad8: 0xc04868a  jal         func_121A28
    ctx->pc = 0x11FAD8u;
    SET_GPR_U32(ctx, 31, 0x11FAE0u);
    ctx->pc = 0x121A28u;
    if (runtime->hasFunction(0x121A28u)) {
        auto targetFn = runtime->lookupFunction(0x121A28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAE0u; }
        if (ctx->pc != 0x11FAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121A28_0x121a28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAE0u; }
        if (ctx->pc != 0x11FAE0u) { return; }
    }
    ctx->pc = 0x11FAE0u;
label_11fae0:
    // 0x11fae0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fae4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11fae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11fae8:
    // 0x11fae8: 0x1202000d  beq         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11FAE8u;
    {
        const bool branch_taken_0x11fae8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x11FAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAE8u;
            // 0x11faec: 0x3c038000  lui         $v1, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fae8) {
            ctx->pc = 0x11FB20u;
            goto label_11fb20;
        }
    }
    ctx->pc = 0x11FAF0u;
    // 0x11faf0: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11faf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11faf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FAF4u;
    {
        const bool branch_taken_0x11faf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAF4u;
            // 0x11faf8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faf4) {
            ctx->pc = 0x11FB10u;
            goto label_11fb10;
        }
    }
    ctx->pc = 0x11FAFCu;
    // 0x11fafc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fafcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb00: 0x12000029  beqz        $s0, . + 4 + (0x29 << 2)
    ctx->pc = 0x11FB00u;
    {
        const bool branch_taken_0x11fb00 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB00u;
            // 0x11fb04: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb00) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB08u;
    // 0x11fb08: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x11FB08u;
    {
        const bool branch_taken_0x11fb08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fb08) {
            ctx->pc = 0x11FB80u;
            goto label_11fb80;
        }
    }
    ctx->pc = 0x11FB10u;
label_11fb10:
    // 0x11fb10: 0x1202000f  beq         $s0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11FB10u;
    {
        const bool branch_taken_0x11fb10 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11fb10) {
            ctx->pc = 0x11FB50u;
            goto label_11fb50;
        }
    }
    ctx->pc = 0x11FB18u;
    // 0x11fb18: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x11FB18u;
    {
        const bool branch_taken_0x11fb18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fb18) {
            ctx->pc = 0x11FB80u;
            goto label_11fb80;
        }
    }
    ctx->pc = 0x11FB20u;
label_11fb20:
    // 0x11fb20: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fb20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb24: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x11fb24u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11fb28: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x11fb28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x11fb2c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x11fb2cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x11fb30: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x11fb30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x11fb34: 0x852024  and         $a0, $a0, $a1
    ctx->pc = 0x11fb34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11fb38: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11fb38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fb3c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x11fb3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x11fb40: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fb40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb44: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x11FB44u;
    {
        const bool branch_taken_0x11fb44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB44u;
            // 0x11fb48: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb44) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB4Cu;
    // 0x11fb4c: 0x0  nop
    ctx->pc = 0x11fb4cu;
    // NOP
label_11fb50:
    // 0x11fb50: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb54: 0xdc258ce8  ld          $a1, -0x7318($at)
    ctx->pc = 0x11fb54u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937832)));
    // 0x11fb58: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB58u;
    SET_GPR_U32(ctx, 31, 0x11FB60u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB60u; }
        if (ctx->pc != 0x11FB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB60u; }
        if (ctx->pc != 0x11FB60u) { return; }
    }
    ctx->pc = 0x11FB60u;
label_11fb60:
    // 0x11fb60: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb64: 0xdc248cf0  ld          $a0, -0x7310($at)
    ctx->pc = 0x11fb64u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 4294937840)));
    // 0x11fb68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fb68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb6c: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB6Cu;
    SET_GPR_U32(ctx, 31, 0x11FB74u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB74u; }
        if (ctx->pc != 0x11FB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB74u; }
        if (ctx->pc != 0x11FB74u) { return; }
    }
    ctx->pc = 0x11FB74u;
label_11fb74:
    // 0x11fb74: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11FB74u;
    {
        const bool branch_taken_0x11fb74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB74u;
            // 0x11fb78: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb74) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB7Cu;
    // 0x11fb7c: 0x0  nop
    ctx->pc = 0x11fb7cu;
    // NOP
label_11fb80:
    // 0x11fb80: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb84: 0xdc258cf8  ld          $a1, -0x7308($at)
    ctx->pc = 0x11fb84u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937848)));
    // 0x11fb88: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB88u;
    SET_GPR_U32(ctx, 31, 0x11FB90u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB90u; }
        if (ctx->pc != 0x11FB90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB90u; }
        if (ctx->pc != 0x11FB90u) { return; }
    }
    ctx->pc = 0x11FB90u;
label_11fb90:
    // 0x11fb90: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb94: 0xdc258d00  ld          $a1, -0x7300($at)
    ctx->pc = 0x11fb94u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937856)));
    // 0x11fb98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fb98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb9c: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB9Cu;
    SET_GPR_U32(ctx, 31, 0x11FBA4u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FBA4u; }
        if (ctx->pc != 0x11FBA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FBA4u; }
        if (ctx->pc != 0x11FBA4u) { return; }
    }
    ctx->pc = 0x11FBA4u;
label_11fba4:
    // 0x11fba4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11fba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11fba8:
    // 0x11fba8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x11fba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_11fbac:
    // 0x11fbac: 0x3e00008  jr          $ra
    ctx->pc = 0x11FBACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11FBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FBACu;
            // 0x11fbb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11FBB4u;
    // 0x11fbb4: 0x0  nop
    ctx->pc = 0x11fbb4u;
    // NOP
    // 0x11fbb8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11fbb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11fbbc: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x11fbbcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fbc0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11fbc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11fbc4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x11fbc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x11fbc8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x11fbc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x11fbcc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x11fbccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x11fbd0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x11fbd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x11fbd4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x11fbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x11fbd8: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x11fbd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x11fbdc: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x11fbdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x11fbe0: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x11fbe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x11fbe4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x11fbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x11fbe8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x11fbe8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fbec: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x11fbecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fbf0: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x11fbf0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x11fbf4: 0x2983f  dsra32      $s3, $v0, 0
    ctx->pc = 0x11fbf4u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11fbf8: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x11fbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x11fbfc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fbfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc00: 0x53102a  slt         $v0, $v0, $s3
    ctx->pc = 0x11fc00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x11fc04: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11FC04u;
    {
        const bool branch_taken_0x11fc04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC04u;
            // 0x11fc08: 0xf02d  daddu       $fp, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc04) {
            ctx->pc = 0x11FC80u;
            goto label_11fc80;
        }
    }
    ctx->pc = 0x11FC0Cu;
    // 0x11fc0c: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11fc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11fc10: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fc10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc14: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x11fc14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x11fc18: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x11fc18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x11fc1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FC1Cu;
    {
        const bool branch_taken_0x11fc1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC1Cu;
            // 0x11fc20: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc1c) {
            ctx->pc = 0x11FC38u;
            goto label_11fc38;
        }
    }
    ctx->pc = 0x11FC24u;
    // 0x11fc24: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x11fc24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x11fc28: 0xdc628d60  ld          $v0, -0x72A0($v1)
    ctx->pc = 0x11fc28u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 4294937952)));
    // 0x11fc2c: 0x1000015a  b           . + 4 + (0x15A << 2)
    ctx->pc = 0x11FC2Cu;
    {
        const bool branch_taken_0x11fc2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC2Cu;
            // 0x11fc30: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc2c) {
            ctx->pc = 0x120198u;
            goto label_120198;
        }
    }
    ctx->pc = 0x11FC34u;
    // 0x11fc34: 0x0  nop
    ctx->pc = 0x11fc34u;
    // NOP
label_11fc38:
    // 0x11fc38: 0x661000b  bgez        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x11FC38u;
    {
        const bool branch_taken_0x11fc38 = (GPR_S64(ctx, 19) >= 0);
        if (branch_taken_0x11fc38) {
            ctx->pc = 0x11FC68u;
            goto label_11fc68;
        }
    }
    ctx->pc = 0x11FC40u;
    // 0x11fc40: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x11fc40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc44: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FC44u;
    SET_GPR_U32(ctx, 31, 0x11FC4Cu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC4Cu; }
        if (ctx->pc != 0x11FC4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC4Cu; }
        if (ctx->pc != 0x11FC4Cu) { return; }
    }
    ctx->pc = 0x11FC4Cu;
label_11fc4c:
    // 0x11fc4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11fc4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc50: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fc50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc54: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FC54u;
    SET_GPR_U32(ctx, 31, 0x11FC5Cu);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC5Cu; }
        if (ctx->pc != 0x11FC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC5Cu; }
        if (ctx->pc != 0x11FC5Cu) { return; }
    }
    ctx->pc = 0x11FC5Cu;
label_11fc5c:
    // 0x11fc5c: 0x1000014d  b           . + 4 + (0x14D << 2)
    ctx->pc = 0x11FC5Cu;
    {
        const bool branch_taken_0x11fc5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC5Cu;
            // 0x11fc60: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc5c) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FC64u;
    // 0x11fc64: 0x0  nop
    ctx->pc = 0x11fc64u;
    // NOP
label_11fc68:
    // 0x11fc68: 0x340586a0  ori         $a1, $zero, 0x86A0
    ctx->pc = 0x11fc68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)34464);
    // 0x11fc6c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11fc6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x11fc70: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FC70u;
    SET_GPR_U32(ctx, 31, 0x11FC78u);
    ctx->pc = 0x11FC74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC70u;
            // 0x11fc74: 0x241effca  addiu       $fp, $zero, -0x36 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967242));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC78u; }
        if (ctx->pc != 0x11FC78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC78u; }
        if (ctx->pc != 0x11FC78u) { return; }
    }
    ctx->pc = 0x11FC78u;
label_11fc78:
    // 0x11fc78: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x11fc78u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc7c: 0x2983f  dsra32      $s3, $v0, 0
    ctx->pc = 0x11fc7cu;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 2) >> (32 + 0));
label_11fc80:
    // 0x11fc80: 0x3c027fef  lui         $v0, 0x7FEF
    ctx->pc = 0x11fc80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32751 << 16));
    // 0x11fc84: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fc84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc88: 0x53102a  slt         $v0, $v0, $s3
    ctx->pc = 0x11fc88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x11fc8c: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x11FC8Cu;
    {
        const bool branch_taken_0x11fc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fc8c) {
            ctx->pc = 0x11FC90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC8Cu;
            // 0x11fc90: 0x3c10000f  lui         $s0, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FCB0u;
            goto label_11fcb0;
        }
    }
    ctx->pc = 0x11FC94u;
    // 0x11fc94: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x11fc94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc98: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11fc98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc9c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FC9Cu;
    SET_GPR_U32(ctx, 31, 0x11FCA4u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FCA4u; }
        if (ctx->pc != 0x11FCA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FCA4u; }
        if (ctx->pc != 0x11FCA4u) { return; }
    }
    ctx->pc = 0x11FCA4u;
label_11fca4:
    // 0x11fca4: 0x1000013b  b           . + 4 + (0x13B << 2)
    ctx->pc = 0x11FCA4u;
    {
        const bool branch_taken_0x11fca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FCA4u;
            // 0x11fca8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fca4) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FCACu;
    // 0x11fcac: 0x0  nop
    ctx->pc = 0x11fcacu;
    // NOP
label_11fcb0:
    // 0x11fcb0: 0x131503  sra         $v0, $s3, 20
    ctx->pc = 0x11fcb0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 19), 20));
    // 0x11fcb4: 0x3610ffff  ori         $s0, $s0, 0xFFFF
    ctx->pc = 0x11fcb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)65535);
    // 0x11fcb8: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x11fcb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x11fcbc: 0x2709824  and         $s3, $s3, $s0
    ctx->pc = 0x11fcbcu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 16));
    // 0x11fcc0: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x11fcc0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x11fcc4: 0x3c040009  lui         $a0, 0x9
    ctx->pc = 0x11fcc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)9 << 16));
    // 0x11fcc8: 0x34845f64  ori         $a0, $a0, 0x5F64
    ctx->pc = 0x11fcc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)24420);
    // 0x11fccc: 0x932021  addu        $a0, $a0, $s3
    ctx->pc = 0x11fcccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x11fcd0: 0x245efc01  addiu       $fp, $v0, -0x3FF
    ctx->pc = 0x11fcd0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966273));
    // 0x11fcd4: 0x85b024  and         $s6, $a0, $a1
    ctx->pc = 0x11fcd4u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11fcd8: 0x3c023ff0  lui         $v0, 0x3FF0
    ctx->pc = 0x11fcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16368 << 16));
    // 0x11fcdc: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11fcdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11fce0: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x11fce0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x11fce4: 0x2c21026  xor         $v0, $s6, $v0
    ctx->pc = 0x11fce4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) ^ GPR_U64(ctx, 2));
    // 0x11fce8: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x11fce8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x11fcec: 0x531025  or          $v0, $v0, $s3
    ctx->pc = 0x11fcecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 19));
    // 0x11fcf0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11fcf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fcf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x11fcf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x11fcf8: 0x163503  sra         $a2, $s6, 20
    ctx->pc = 0x11fcf8u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 22), 20));
    // 0x11fcfc: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x11fcfcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x11fd00: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x11fd00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x11fd04: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x11fd04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd08: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FD08u;
    SET_GPR_U32(ctx, 31, 0x11FD10u);
    ctx->pc = 0x11FD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD08u;
            // 0x11fd0c: 0x3c6f021  addu        $fp, $fp, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD10u; }
        if (ctx->pc != 0x11FD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD10u; }
        if (ctx->pc != 0x11FD10u) { return; }
    }
    ctx->pc = 0x11FD10u;
label_11fd10:
    // 0x11fd10: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x11fd10u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd14: 0x26620002  addiu       $v0, $s3, 0x2
    ctx->pc = 0x11fd14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x11fd18: 0x501024  and         $v0, $v0, $s0
    ctx->pc = 0x11fd18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 16));
    // 0x11fd1c: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x11fd1cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x11fd20: 0x10400055  beqz        $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x11FD20u;
    {
        const bool branch_taken_0x11fd20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fd20) {
            ctx->pc = 0x11FE78u;
            goto label_11fe78;
        }
    }
    ctx->pc = 0x11FD28u;
    // 0x11fd28: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x11fd28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd2c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fd2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd30: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11fd30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd34: 0xc0448a6  jal         func_112298
    ctx->pc = 0x11FD34u;
    SET_GPR_U32(ctx, 31, 0x11FD3Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD3Cu; }
        if (ctx->pc != 0x11FD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD3Cu; }
        if (ctx->pc != 0x11FD3Cu) { return; }
    }
    ctx->pc = 0x11FD3Cu;
label_11fd3c:
    // 0x11fd3c: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x11FD3Cu;
    {
        const bool branch_taken_0x11fd3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11fd3c) {
            ctx->pc = 0x11FDA0u;
            goto label_11fda0;
        }
    }
    ctx->pc = 0x11FD44u;
    // 0x11fd44: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11fd44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd48: 0x53c00112  beql        $fp, $zero, . + 4 + (0x112 << 2)
    ctx->pc = 0x11FD48u;
    {
        const bool branch_taken_0x11fd48 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fd48) {
            ctx->pc = 0x11FD4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD48u;
            // 0x11fd4c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FD50u;
    // 0x11fd50: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FD50u;
    SET_GPR_U32(ctx, 31, 0x11FD58u);
    ctx->pc = 0x11FD54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD50u;
            // 0x11fd54: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD58u; }
        if (ctx->pc != 0x11FD58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD58u; }
        if (ctx->pc != 0x11FD58u) { return; }
    }
    ctx->pc = 0x11FD58u;
label_11fd58:
    // 0x11fd58: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fd58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fd5c: 0xdc258d68  ld          $a1, -0x7298($at)
    ctx->pc = 0x11fd5cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937960)));
    // 0x11fd60: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11fd60u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd64: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fd64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd68: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FD68u;
    SET_GPR_U32(ctx, 31, 0x11FD70u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD70u; }
        if (ctx->pc != 0x11FD70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD70u; }
        if (ctx->pc != 0x11FD70u) { return; }
    }
    ctx->pc = 0x11FD70u;
label_11fd70:
    // 0x11fd70: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fd70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd74: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fd74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fd78: 0xdc258d70  ld          $a1, -0x7290($at)
    ctx->pc = 0x11fd78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937968)));
    // 0x11fd7c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fd7cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd80: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FD80u;
    SET_GPR_U32(ctx, 31, 0x11FD88u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD88u; }
        if (ctx->pc != 0x11FD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD88u; }
        if (ctx->pc != 0x11FD88u) { return; }
    }
    ctx->pc = 0x11FD88u;
label_11fd88:
    // 0x11fd88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fd88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fd8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd90: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FD90u;
    SET_GPR_U32(ctx, 31, 0x11FD98u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD98u; }
        if (ctx->pc != 0x11FD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD98u; }
        if (ctx->pc != 0x11FD98u) { return; }
    }
    ctx->pc = 0x11FD98u;
label_11fd98:
    // 0x11fd98: 0x100000fe  b           . + 4 + (0xFE << 2)
    ctx->pc = 0x11FD98u;
    {
        const bool branch_taken_0x11fd98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD98u;
            // 0x11fd9c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fd98) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FDA0u;
label_11fda0:
    // 0x11fda0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11fda0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fda4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fda4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fda8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDA8u;
    SET_GPR_U32(ctx, 31, 0x11FDB0u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDB0u; }
        if (ctx->pc != 0x11FDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDB0u; }
        if (ctx->pc != 0x11FDB0u) { return; }
    }
    ctx->pc = 0x11FDB0u;
label_11fdb0:
    // 0x11fdb0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fdb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdb4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fdb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fdb8: 0xdc258d78  ld          $a1, -0x7288($at)
    ctx->pc = 0x11fdb8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937976)));
    // 0x11fdbc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fdbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdc0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDC0u;
    SET_GPR_U32(ctx, 31, 0x11FDC8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDC8u; }
        if (ctx->pc != 0x11FDC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDC8u; }
        if (ctx->pc != 0x11FDC8u) { return; }
    }
    ctx->pc = 0x11FDC8u;
label_11fdc8:
    // 0x11fdc8: 0x3404ff80  ori         $a0, $zero, 0xFF80
    ctx->pc = 0x11fdc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x11fdcc: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x11fdccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x11fdd0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fdd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdd4: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FDD4u;
    SET_GPR_U32(ctx, 31, 0x11FDDCu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDDCu; }
        if (ctx->pc != 0x11FDDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDDCu; }
        if (ctx->pc != 0x11FDDCu) { return; }
    }
    ctx->pc = 0x11FDDCu;
label_11fddc:
    // 0x11fddc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fddcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fde0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fde0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fde4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDE4u;
    SET_GPR_U32(ctx, 31, 0x11FDECu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDECu; }
        if (ctx->pc != 0x11FDECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDECu; }
        if (ctx->pc != 0x11FDECu) { return; }
    }
    ctx->pc = 0x11FDECu;
label_11fdec:
    // 0x11fdec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11fdecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdf0: 0x17c00007  bnez        $fp, . + 4 + (0x7 << 2)
    ctx->pc = 0x11FDF0u;
    {
        const bool branch_taken_0x11fdf0 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x11fdf0) {
            ctx->pc = 0x11FE10u;
            goto label_11fe10;
        }
    }
    ctx->pc = 0x11FDF8u;
    // 0x11fdf8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fdf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdfc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11fdfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe00: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE00u;
    SET_GPR_U32(ctx, 31, 0x11FE08u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE08u; }
        if (ctx->pc != 0x11FE08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE08u; }
        if (ctx->pc != 0x11FE08u) { return; }
    }
    ctx->pc = 0x11FE08u;
label_11fe08:
    // 0x11fe08: 0x100000e2  b           . + 4 + (0xE2 << 2)
    ctx->pc = 0x11FE08u;
    {
        const bool branch_taken_0x11fe08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE08u;
            // 0x11fe0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fe08) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FE10u;
label_11fe10:
    // 0x11fe10: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FE10u;
    SET_GPR_U32(ctx, 31, 0x11FE18u);
    ctx->pc = 0x11FE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE10u;
            // 0x11fe14: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE18u; }
        if (ctx->pc != 0x11FE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE18u; }
        if (ctx->pc != 0x11FE18u) { return; }
    }
    ctx->pc = 0x11FE18u;
label_11fe18:
    // 0x11fe18: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fe18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fe1c: 0xdc258d80  ld          $a1, -0x7280($at)
    ctx->pc = 0x11fe1cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937984)));
    // 0x11fe20: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11fe20u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe24: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fe24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe28: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FE28u;
    SET_GPR_U32(ctx, 31, 0x11FE30u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE30u; }
        if (ctx->pc != 0x11FE30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE30u; }
        if (ctx->pc != 0x11FE30u) { return; }
    }
    ctx->pc = 0x11FE30u;
label_11fe30:
    // 0x11fe30: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fe30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe34: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fe34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fe38: 0xdc258d88  ld          $a1, -0x7278($at)
    ctx->pc = 0x11fe38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937992)));
    // 0x11fe3c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fe3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe40: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FE40u;
    SET_GPR_U32(ctx, 31, 0x11FE48u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE48u; }
        if (ctx->pc != 0x11FE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE48u; }
        if (ctx->pc != 0x11FE48u) { return; }
    }
    ctx->pc = 0x11FE48u;
label_11fe48:
    // 0x11fe48: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11fe48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe4c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fe4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe50: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE50u;
    SET_GPR_U32(ctx, 31, 0x11FE58u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE58u; }
        if (ctx->pc != 0x11FE58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE58u; }
        if (ctx->pc != 0x11FE58u) { return; }
    }
    ctx->pc = 0x11FE58u;
label_11fe58:
    // 0x11fe58: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11fe58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe5c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fe5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe60: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE60u;
    SET_GPR_U32(ctx, 31, 0x11FE68u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE68u; }
        if (ctx->pc != 0x11FE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE68u; }
        if (ctx->pc != 0x11FE68u) { return; }
    }
    ctx->pc = 0x11FE68u;
label_11fe68:
    // 0x11fe68: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fe68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe6c: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x11FE6Cu;
    {
        const bool branch_taken_0x11fe6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fe6c) {
            ctx->pc = 0x1200FCu;
            goto label_1200fc;
        }
    }
    ctx->pc = 0x11FE74u;
    // 0x11fe74: 0x0  nop
    ctx->pc = 0x11fe74u;
    // NOP
label_11fe78:
    // 0x11fe78: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x11fe78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x11fe7c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11fe7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x11fe80: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fe80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe84: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FE84u;
    SET_GPR_U32(ctx, 31, 0x11FE8Cu);
    ctx->pc = 0x11FE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE84u;
            // 0x11fe88: 0x3c100006  lui         $s0, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)6 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE8Cu; }
        if (ctx->pc != 0x11FE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE8Cu; }
        if (ctx->pc != 0x11FE8Cu) { return; }
    }
    ctx->pc = 0x11FE8Cu;
label_11fe8c:
    // 0x11fe8c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fe8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe90: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fe90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe94: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FE94u;
    SET_GPR_U32(ctx, 31, 0x11FE9Cu);
    ctx->pc = 0x11FE98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE94u;
            // 0x11fe98: 0x3610b851  ori         $s0, $s0, 0xB851 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)47185);
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE9Cu; }
        if (ctx->pc != 0x11FE9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE9Cu; }
        if (ctx->pc != 0x11FE9Cu) { return; }
    }
    ctx->pc = 0x11FE9Cu;
label_11fe9c:
    // 0x11fe9c: 0x40b82d  daddu       $s7, $v0, $zero
    ctx->pc = 0x11fe9cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fea0: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FEA0u;
    SET_GPR_U32(ctx, 31, 0x11FEA8u);
    ctx->pc = 0x11FEA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEA0u;
            // 0x11fea4: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEA8u; }
        if (ctx->pc != 0x11FEA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEA8u; }
        if (ctx->pc != 0x11FEA8u) { return; }
    }
    ctx->pc = 0x11FEA8u;
label_11fea8:
    // 0x11fea8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x11fea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feac: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x11feacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feb0: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11feb0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feb4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FEB4u;
    SET_GPR_U32(ctx, 31, 0x11FEBCu);
    ctx->pc = 0x11FEB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEB4u;
            // 0x11feb8: 0x2138023  subu        $s0, $s0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEBCu; }
        if (ctx->pc != 0x11FEBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEBCu; }
        if (ctx->pc != 0x11FEBCu) { return; }
    }
    ctx->pc = 0x11FEBCu;
label_11febc:
    // 0x11febc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11febcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fec0: 0x3c02fff9  lui         $v0, 0xFFF9
    ctx->pc = 0x11fec0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65529 << 16));
    // 0x11fec4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11fec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fec8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11fec8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fecc: 0x3442eb86  ori         $v0, $v0, 0xEB86
    ctx->pc = 0x11feccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60294);
    // 0x11fed0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FED0u;
    SET_GPR_U32(ctx, 31, 0x11FED8u);
    ctx->pc = 0x11FED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FED0u;
            // 0x11fed4: 0x262b021  addu        $s6, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FED8u; }
        if (ctx->pc != 0x11FED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FED8u; }
        if (ctx->pc != 0x11FED8u) { return; }
    }
    ctx->pc = 0x11FED8u;
label_11fed8:
    // 0x11fed8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11fed8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fedc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fedcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fee0: 0xdc258d90  ld          $a1, -0x7270($at)
    ctx->pc = 0x11fee0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938000)));
    // 0x11fee4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11fee4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fee8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FEE8u;
    SET_GPR_U32(ctx, 31, 0x11FEF0u);
    ctx->pc = 0x11FEECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEE8u;
            // 0x11feec: 0x2d0b025  or          $s6, $s6, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEF0u; }
        if (ctx->pc != 0x11FEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEF0u; }
        if (ctx->pc != 0x11FEF0u) { return; }
    }
    ctx->pc = 0x11FEF0u;
label_11fef0:
    // 0x11fef0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fef0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fef4: 0xdc258d98  ld          $a1, -0x7268($at)
    ctx->pc = 0x11fef4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938008)));
    // 0x11fef8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fefc: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FEFCu;
    SET_GPR_U32(ctx, 31, 0x11FF04u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF04u; }
        if (ctx->pc != 0x11FF04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF04u; }
        if (ctx->pc != 0x11FF04u) { return; }
    }
    ctx->pc = 0x11FF04u;
label_11ff04:
    // 0x11ff04: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff08: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff0c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF0Cu;
    SET_GPR_U32(ctx, 31, 0x11FF14u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF14u; }
        if (ctx->pc != 0x11FF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF14u; }
        if (ctx->pc != 0x11FF14u) { return; }
    }
    ctx->pc = 0x11FF14u;
label_11ff14:
    // 0x11ff14: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff18: 0xdc258da0  ld          $a1, -0x7260($at)
    ctx->pc = 0x11ff18u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938016)));
    // 0x11ff1c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff20: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF20u;
    SET_GPR_U32(ctx, 31, 0x11FF28u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF28u; }
        if (ctx->pc != 0x11FF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF28u; }
        if (ctx->pc != 0x11FF28u) { return; }
    }
    ctx->pc = 0x11FF28u;
label_11ff28:
    // 0x11ff28: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff2c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff30: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF30u;
    SET_GPR_U32(ctx, 31, 0x11FF38u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF38u; }
        if (ctx->pc != 0x11FF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF38u; }
        if (ctx->pc != 0x11FF38u) { return; }
    }
    ctx->pc = 0x11FF38u;
label_11ff38:
    // 0x11ff38: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff3c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff40: 0xdc258da8  ld          $a1, -0x7258($at)
    ctx->pc = 0x11ff40u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938024)));
    // 0x11ff44: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11ff44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff48: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF48u;
    SET_GPR_U32(ctx, 31, 0x11FF50u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF50u; }
        if (ctx->pc != 0x11FF50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF50u; }
        if (ctx->pc != 0x11FF50u) { return; }
    }
    ctx->pc = 0x11FF50u;
label_11ff50:
    // 0x11ff50: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff54: 0xdc258db0  ld          $a1, -0x7250($at)
    ctx->pc = 0x11ff54u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938032)));
    // 0x11ff58: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff5c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF5Cu;
    SET_GPR_U32(ctx, 31, 0x11FF64u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF64u; }
        if (ctx->pc != 0x11FF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF64u; }
        if (ctx->pc != 0x11FF64u) { return; }
    }
    ctx->pc = 0x11FF64u;
label_11ff64:
    // 0x11ff64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff6c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF6Cu;
    SET_GPR_U32(ctx, 31, 0x11FF74u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF74u; }
        if (ctx->pc != 0x11FF74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF74u; }
        if (ctx->pc != 0x11FF74u) { return; }
    }
    ctx->pc = 0x11FF74u;
label_11ff74:
    // 0x11ff74: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff78: 0xdc258db8  ld          $a1, -0x7248($at)
    ctx->pc = 0x11ff78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938040)));
    // 0x11ff7c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff80: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF80u;
    SET_GPR_U32(ctx, 31, 0x11FF88u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF88u; }
        if (ctx->pc != 0x11FF88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF88u; }
        if (ctx->pc != 0x11FF88u) { return; }
    }
    ctx->pc = 0x11FF88u;
label_11ff88:
    // 0x11ff88: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff90: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF90u;
    SET_GPR_U32(ctx, 31, 0x11FF98u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF98u; }
        if (ctx->pc != 0x11FF98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF98u; }
        if (ctx->pc != 0x11FF98u) { return; }
    }
    ctx->pc = 0x11FF98u;
label_11ff98:
    // 0x11ff98: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff9c: 0xdc258dc0  ld          $a1, -0x7240($at)
    ctx->pc = 0x11ff9cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938048)));
    // 0x11ffa0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ffa0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffa4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FFA4u;
    SET_GPR_U32(ctx, 31, 0x11FFACu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFACu; }
        if (ctx->pc != 0x11FFACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFACu; }
        if (ctx->pc != 0x11FFACu) { return; }
    }
    ctx->pc = 0x11FFACu;
label_11ffac:
    // 0x11ffac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11ffacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffb0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ffb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffb4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFB4u;
    SET_GPR_U32(ctx, 31, 0x11FFBCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFBCu; }
        if (ctx->pc != 0x11FFBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFBCu; }
        if (ctx->pc != 0x11FFBCu) { return; }
    }
    ctx->pc = 0x11FFBCu;
label_11ffbc:
    // 0x11ffbc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11ffbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffc0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ffc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffc4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FFC4u;
    SET_GPR_U32(ctx, 31, 0x11FFCCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFCCu; }
        if (ctx->pc != 0x11FFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFCCu; }
        if (ctx->pc != 0x11FFCCu) { return; }
    }
    ctx->pc = 0x11FFCCu;
label_11ffcc:
    // 0x11ffcc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11ffccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffd0: 0x1ac0003f  blez        $s6, . + 4 + (0x3F << 2)
    ctx->pc = 0x11FFD0u;
    {
        const bool branch_taken_0x11ffd0 = (GPR_S64(ctx, 22) <= 0);
        if (branch_taken_0x11ffd0) {
            ctx->pc = 0x1200D0u;
            goto label_1200d0;
        }
    }
    ctx->pc = 0x11FFD8u;
    // 0x11ffd8: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x11ffd8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x11ffdc: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x11ffdcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x11ffe0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11ffe0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffe4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFE4u;
    SET_GPR_U32(ctx, 31, 0x11FFECu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFECu; }
        if (ctx->pc != 0x11FFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFECu; }
        if (ctx->pc != 0x11FFECu) { return; }
    }
    ctx->pc = 0x11FFECu;
label_11ffec:
    // 0x11ffec: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11ffecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fff0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fff4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFF4u;
    SET_GPR_U32(ctx, 31, 0x11FFFCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFFCu; }
        if (ctx->pc != 0x11FFFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFFCu; }
        if (ctx->pc != 0x11FFFCu) { return; }
    }
    ctx->pc = 0x11FFFCu;
label_11fffc:
    // 0x11fffc: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x11fffcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120000: 0x17c0000f  bnez        $fp, . + 4 + (0xF << 2)
    ctx->pc = 0x120000u;
    {
        const bool branch_taken_0x120000 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x120000) {
            ctx->pc = 0x120040u;
            goto label_120040;
        }
    }
    ctx->pc = 0x120008u;
    // 0x120008: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120008u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12000c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12000cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120010: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120010u;
    SET_GPR_U32(ctx, 31, 0x120018u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120018u; }
        if (ctx->pc != 0x120018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120018u; }
        if (ctx->pc != 0x120018u) { return; }
    }
    ctx->pc = 0x120018u;
label_120018:
    // 0x120018: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120018u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12001c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12001cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120020: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120020u;
    SET_GPR_U32(ctx, 31, 0x120028u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120028u; }
        if (ctx->pc != 0x120028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120028u; }
        if (ctx->pc != 0x120028u) { return; }
    }
    ctx->pc = 0x120028u;
label_120028:
    // 0x120028: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x120028u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12002c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12002cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120030: 0xc044752  jal         func_111D48
    ctx->pc = 0x120030u;
    SET_GPR_U32(ctx, 31, 0x120038u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120038u; }
        if (ctx->pc != 0x120038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120038u; }
        if (ctx->pc != 0x120038u) { return; }
    }
    ctx->pc = 0x120038u;
label_120038:
    // 0x120038: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x120038u;
    {
        const bool branch_taken_0x120038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120038) {
            ctx->pc = 0x1200F8u;
            goto label_1200f8;
        }
    }
    ctx->pc = 0x120040u;
label_120040:
    // 0x120040: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x120040u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120044: 0xdc258dc8  ld          $a1, -0x7238($at)
    ctx->pc = 0x120044u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x120048: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120048u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12004c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12004Cu;
    SET_GPR_U32(ctx, 31, 0x120054u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120054u; }
        if (ctx->pc != 0x120054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120054u; }
        if (ctx->pc != 0x120054u) { return; }
    }
    ctx->pc = 0x120054u;
label_120054:
    // 0x120054: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x120054u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120058: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120058u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12005c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12005cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120060: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120060u;
    SET_GPR_U32(ctx, 31, 0x120068u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120068u; }
        if (ctx->pc != 0x120068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120068u; }
        if (ctx->pc != 0x120068u) { return; }
    }
    ctx->pc = 0x120068u;
label_120068:
    // 0x120068: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12006c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12006cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120070: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120070u;
    SET_GPR_U32(ctx, 31, 0x120078u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120078u; }
        if (ctx->pc != 0x120078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120078u; }
        if (ctx->pc != 0x120078u) { return; }
    }
    ctx->pc = 0x120078u;
label_120078:
    // 0x120078: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120078u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12007c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12007cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120080: 0xdc258dd0  ld          $a1, -0x7230($at)
    ctx->pc = 0x120080u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938064)));
    // 0x120084: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x120084u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120088: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120088u;
    SET_GPR_U32(ctx, 31, 0x120090u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120090u; }
        if (ctx->pc != 0x120090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120090u; }
        if (ctx->pc != 0x120090u) { return; }
    }
    ctx->pc = 0x120090u;
label_120090:
    // 0x120090: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120090u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120094: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120094u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120098: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120098u;
    SET_GPR_U32(ctx, 31, 0x1200A0u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200A0u; }
        if (ctx->pc != 0x1200A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200A0u; }
        if (ctx->pc != 0x1200A0u) { return; }
    }
    ctx->pc = 0x1200A0u;
label_1200a0:
    // 0x1200a0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1200a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200a4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200a8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200A8u;
    SET_GPR_U32(ctx, 31, 0x1200B0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200B0u; }
        if (ctx->pc != 0x1200B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200B0u; }
        if (ctx->pc != 0x1200B0u) { return; }
    }
    ctx->pc = 0x1200B0u;
label_1200b0:
    // 0x1200b0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1200b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200b4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1200b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200b8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200B8u;
    SET_GPR_U32(ctx, 31, 0x1200C0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200C0u; }
        if (ctx->pc != 0x1200C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200C0u; }
        if (ctx->pc != 0x1200C0u) { return; }
    }
    ctx->pc = 0x1200C0u;
label_1200c0:
    // 0x1200c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1200c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200c4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1200C4u;
    {
        const bool branch_taken_0x1200c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1200c4) {
            ctx->pc = 0x1200FCu;
            goto label_1200fc;
        }
    }
    ctx->pc = 0x1200CCu;
    // 0x1200cc: 0x0  nop
    ctx->pc = 0x1200ccu;
    // NOP
label_1200d0:
    // 0x1200d0: 0x17c0000f  bnez        $fp, . + 4 + (0xF << 2)
    ctx->pc = 0x1200D0u;
    {
        const bool branch_taken_0x1200d0 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x1200d0) {
            ctx->pc = 0x120110u;
            goto label_120110;
        }
    }
    ctx->pc = 0x1200D8u;
    // 0x1200d8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1200d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200dc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1200dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200e0: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200E0u;
    SET_GPR_U32(ctx, 31, 0x1200E8u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200E8u; }
        if (ctx->pc != 0x1200E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200E8u; }
        if (ctx->pc != 0x1200E8u) { return; }
    }
    ctx->pc = 0x1200E8u;
label_1200e8:
    // 0x1200e8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1200e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200f0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1200F0u;
    SET_GPR_U32(ctx, 31, 0x1200F8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200F8u; }
        if (ctx->pc != 0x1200F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200F8u; }
        if (ctx->pc != 0x1200F8u) { return; }
    }
    ctx->pc = 0x1200F8u;
label_1200f8:
    // 0x1200f8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1200f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1200fc:
    // 0x1200fc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120100: 0xc044752  jal         func_111D48
    ctx->pc = 0x120100u;
    SET_GPR_U32(ctx, 31, 0x120108u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120108u; }
        if (ctx->pc != 0x120108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120108u; }
        if (ctx->pc != 0x120108u) { return; }
    }
    ctx->pc = 0x120108u;
label_120108:
    // 0x120108: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x120108u;
    {
        const bool branch_taken_0x120108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12010Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120108u;
            // 0x12010c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120108) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x120110u;
label_120110:
    // 0x120110: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x120110u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120114: 0xdc258dd8  ld          $a1, -0x7228($at)
    ctx->pc = 0x120114u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938072)));
    // 0x120118: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120118u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12011c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12011Cu;
    SET_GPR_U32(ctx, 31, 0x120124u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120124u; }
        if (ctx->pc != 0x120124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120124u; }
        if (ctx->pc != 0x120124u) { return; }
    }
    ctx->pc = 0x120124u;
label_120124:
    // 0x120124: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x120124u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120128: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120128u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12012c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12012cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120130: 0xc044752  jal         func_111D48
    ctx->pc = 0x120130u;
    SET_GPR_U32(ctx, 31, 0x120138u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120138u; }
        if (ctx->pc != 0x120138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120138u; }
        if (ctx->pc != 0x120138u) { return; }
    }
    ctx->pc = 0x120138u;
label_120138:
    // 0x120138: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12013c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12013cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120140: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120140u;
    SET_GPR_U32(ctx, 31, 0x120148u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120148u; }
        if (ctx->pc != 0x120148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120148u; }
        if (ctx->pc != 0x120148u) { return; }
    }
    ctx->pc = 0x120148u;
label_120148:
    // 0x120148: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120148u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12014c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12014cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120150: 0xdc258de0  ld          $a1, -0x7220($at)
    ctx->pc = 0x120150u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938080)));
    // 0x120154: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x120154u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120158: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120158u;
    SET_GPR_U32(ctx, 31, 0x120160u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120160u; }
        if (ctx->pc != 0x120160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120160u; }
        if (ctx->pc != 0x120160u) { return; }
    }
    ctx->pc = 0x120160u;
label_120160:
    // 0x120160: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120164: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120168: 0xc044752  jal         func_111D48
    ctx->pc = 0x120168u;
    SET_GPR_U32(ctx, 31, 0x120170u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120170u; }
        if (ctx->pc != 0x120170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120170u; }
        if (ctx->pc != 0x120170u) { return; }
    }
    ctx->pc = 0x120170u;
label_120170:
    // 0x120170: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x120170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120174: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120178: 0xc044752  jal         func_111D48
    ctx->pc = 0x120178u;
    SET_GPR_U32(ctx, 31, 0x120180u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120180u; }
        if (ctx->pc != 0x120180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120180u; }
        if (ctx->pc != 0x120180u) { return; }
    }
    ctx->pc = 0x120180u;
label_120180:
    // 0x120180: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x120180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120184: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120184u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120188: 0xc044752  jal         func_111D48
    ctx->pc = 0x120188u;
    SET_GPR_U32(ctx, 31, 0x120190u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120190u; }
        if (ctx->pc != 0x120190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120190u; }
        if (ctx->pc != 0x120190u) { return; }
    }
    ctx->pc = 0x120190u;
label_120190:
    // 0x120190: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x120190u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_120194:
    // 0x120194: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x120194u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_120198:
    // 0x120198: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x120198u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12019c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12019cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1201a0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1201a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1201a4: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1201a4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1201a8: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1201a8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1201ac: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1201acu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1201b0: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1201b0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1201b4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1201b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1201b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1201B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1201BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1201B8u;
            // 0x1201bc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1201C0u;
    // 0x1201c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1201c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1201c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1201c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1201c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1201c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1201cc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1201ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1201d0: 0x3c148000  lui         $s4, 0x8000
    ctx->pc = 0x1201d0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32768 << 16));
    // 0x1201d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1201d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1201d8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1201d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1201dc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1201dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1201e0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1201e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1201e4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1201e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1201e8: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x1201e8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1201ec: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x1201ecu;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x1201f0: 0x2283f  dsra32      $a1, $v0, 0
    ctx->pc = 0x1201f0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1201f4: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x1201f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x1201f8: 0xa31024  and         $v0, $a1, $v1
    ctx->pc = 0x1201f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1201fc: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1201FCu;
    {
        const bool branch_taken_0x1201fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x120200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1201FCu;
            // 0x120200: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1201fc) {
            ctx->pc = 0x120228u;
            goto label_120228;
        }
    }
    ctx->pc = 0x120204u;
    // 0x120204: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120208: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120208u;
    SET_GPR_U32(ctx, 31, 0x120210u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120210u; }
        if (ctx->pc != 0x120210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120210u; }
        if (ctx->pc != 0x120210u) { return; }
    }
    ctx->pc = 0x120210u;
label_120210:
    // 0x120210: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120214: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120214u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120218: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120218u;
    SET_GPR_U32(ctx, 31, 0x120220u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120220u; }
        if (ctx->pc != 0x120220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120220u; }
        if (ctx->pc != 0x120220u) { return; }
    }
    ctx->pc = 0x120220u;
label_120220:
    // 0x120220: 0x100000a6  b           . + 4 + (0xA6 << 2)
    ctx->pc = 0x120220u;
    {
        const bool branch_taken_0x120220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120220u;
            // 0x120224: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120220) {
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x120228u;
label_120228:
    // 0x120228: 0x1ca00013  bgtz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x120228u;
    {
        const bool branch_taken_0x120228 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x12022Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120228u;
            // 0x12022c: 0x58d03  sra         $s1, $a1, 20 (Delay Slot)
        SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 5), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120228) {
            ctx->pc = 0x120278u;
            goto label_120278;
        }
    }
    ctx->pc = 0x120230u;
    // 0x120230: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x120230u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x120234: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x120234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120238: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x120238u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x12023c: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x12023cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x120240: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x120240u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x120244: 0x5060009d  beql        $v1, $zero, . + 4 + (0x9D << 2)
    ctx->pc = 0x120244u;
    {
        const bool branch_taken_0x120244 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x120244) {
            ctx->pc = 0x120248u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120244u;
            // 0x120248: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x12024Cu;
    // 0x12024c: 0x4a1000a  bgez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x12024Cu;
    {
        const bool branch_taken_0x12024c = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x12024c) {
            ctx->pc = 0x120278u;
            goto label_120278;
        }
    }
    ctx->pc = 0x120254u;
    // 0x120254: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120254u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120258: 0xc044752  jal         func_111D48
    ctx->pc = 0x120258u;
    SET_GPR_U32(ctx, 31, 0x120260u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120260u; }
        if (ctx->pc != 0x120260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120260u; }
        if (ctx->pc != 0x120260u) { return; }
    }
    ctx->pc = 0x120260u;
label_120260:
    // 0x120260: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120264: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120264u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120268: 0xc04480e  jal         func_112038
    ctx->pc = 0x120268u;
    SET_GPR_U32(ctx, 31, 0x120270u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120270u; }
        if (ctx->pc != 0x120270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120270u; }
        if (ctx->pc != 0x120270u) { return; }
    }
    ctx->pc = 0x120270u;
label_120270:
    // 0x120270: 0x10000092  b           . + 4 + (0x92 << 2)
    ctx->pc = 0x120270u;
    {
        const bool branch_taken_0x120270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120270u;
            // 0x120274: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120270) {
            ctx->pc = 0x1204BCu;
            goto label_1204bc;
        }
    }
    ctx->pc = 0x120278u;
label_120278:
    // 0x120278: 0x1620001d  bnez        $s1, . + 4 + (0x1D << 2)
    ctx->pc = 0x120278u;
    {
        const bool branch_taken_0x120278 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x12027Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120278u;
            // 0x12027c: 0x3c02000f  lui         $v0, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120278) {
            ctx->pc = 0x1202F0u;
            goto label_1202f0;
        }
    }
    ctx->pc = 0x120280u;
    // 0x120280: 0x14a00009  bnez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x120280u;
    {
        const bool branch_taken_0x120280 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x120284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120280u;
            // 0x120284: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120280) {
            ctx->pc = 0x1202A8u;
            goto label_1202a8;
        }
    }
    ctx->pc = 0x120288u;
label_120288:
    // 0x120288: 0x712c2  srl         $v0, $a3, 11
    ctx->pc = 0x120288u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 11));
    // 0x12028c: 0x73d40  sll         $a3, $a3, 21
    ctx->pc = 0x12028cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 21));
    // 0x120290: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x120290u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x120294: 0x0  nop
    ctx->pc = 0x120294u;
    // NOP
    // 0x120298: 0x0  nop
    ctx->pc = 0x120298u;
    // NOP
    // 0x12029c: 0x10a0fffa  beqz        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12029Cu;
    {
        const bool branch_taken_0x12029c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1202A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12029Cu;
            // 0x1202a0: 0x2631ffeb  addiu       $s1, $s1, -0x15 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967275));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12029c) {
            ctx->pc = 0x120288u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120288;
        }
    }
    ctx->pc = 0x1202A4u;
    // 0x1202a4: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1202a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_1202a8:
    // 0x1202a8: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1202a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1202ac: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1202ACu;
    {
        const bool branch_taken_0x1202ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1202B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1202ACu;
            // 0x1202b0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1202ac) {
            ctx->pc = 0x1202D4u;
            goto label_1202d4;
        }
    }
    ctx->pc = 0x1202B4u;
    // 0x1202b4: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x1202b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
label_1202b8:
    // 0x1202b8: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1202b8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1202bc: 0xa31024  and         $v0, $a1, $v1
    ctx->pc = 0x1202bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1202c0: 0x0  nop
    ctx->pc = 0x1202c0u;
    // NOP
    // 0x1202c4: 0x0  nop
    ctx->pc = 0x1202c4u;
    // NOP
    // 0x1202c8: 0x0  nop
    ctx->pc = 0x1202c8u;
    // NOP
    // 0x1202cc: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1202CCu;
    {
        const bool branch_taken_0x1202cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1202D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1202CCu;
            // 0x1202d0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1202cc) {
            ctx->pc = 0x1202B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1202b8;
        }
    }
    ctx->pc = 0x1202D4u;
label_1202d4:
    // 0x1202d4: 0x41023  negu        $v0, $a0
    ctx->pc = 0x1202d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1202d8: 0x2241823  subu        $v1, $s1, $a0
    ctx->pc = 0x1202d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x1202dc: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1202dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1202e0: 0x873804  sllv        $a3, $a3, $a0
    ctx->pc = 0x1202e0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 4) & 0x1F));
    // 0x1202e4: 0x24710001  addiu       $s1, $v1, 0x1
    ctx->pc = 0x1202e4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1202e8: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1202e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1202ec: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x1202ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
label_1202f0:
    // 0x1202f0: 0x2631fc01  addiu       $s1, $s1, -0x3FF
    ctx->pc = 0x1202f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294966273));
    // 0x1202f4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1202f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1202f8: 0x3c040010  lui         $a0, 0x10
    ctx->pc = 0x1202f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16 << 16));
    // 0x1202fc: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1202fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x120300: 0x32230001  andi        $v1, $s1, 0x1
    ctx->pc = 0x120300u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x120304: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x120304u;
    {
        const bool branch_taken_0x120304 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x120308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120304u;
            // 0x120308: 0x442825  or          $a1, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120304) {
            ctx->pc = 0x120320u;
            goto label_120320;
        }
    }
    ctx->pc = 0x12030Cu;
    // 0x12030c: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x12030cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
    // 0x120310: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x120310u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120314: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120314u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x120318: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12031c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x12031cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_120320:
    // 0x120320: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x120320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
    // 0x120324: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x120324u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120328: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120328u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12032c: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x12032cu;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x120330: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x120334: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x120334u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120338: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x120338u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12033c: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x12033cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120340: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x120340u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120344: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x120344u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120348: 0x3c090020  lui         $t1, 0x20
    ctx->pc = 0x120348u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32 << 16));
    // 0x12034c: 0x0  nop
    ctx->pc = 0x12034cu;
    // NOP
label_120350:
    // 0x120350: 0x1691821  addu        $v1, $t3, $t1
    ctx->pc = 0x120350u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
    // 0x120354: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x120354u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120358: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x120358u;
    {
        const bool branch_taken_0x120358 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120358u;
            // 0x12035c: 0xf41024  and         $v0, $a3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120358) {
            ctx->pc = 0x12036Cu;
            goto label_12036c;
        }
    }
    ctx->pc = 0x120360u;
    // 0x120360: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x120360u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x120364: 0x695821  addu        $t3, $v1, $t1
    ctx->pc = 0x120364u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x120368: 0x2699821  addu        $s3, $s3, $t1
    ctx->pc = 0x120368u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 9)));
label_12036c:
    // 0x12036c: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x12036cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x120370: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x120370u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x120374: 0x94842  srl         $t1, $t1, 1
    ctx->pc = 0x120374u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
    // 0x120378: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x120378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12037c: 0x1520fff4  bnez        $t1, . + 4 + (-0xC << 2)
    ctx->pc = 0x12037Cu;
    {
        const bool branch_taken_0x12037c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x120380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12037Cu;
            // 0x120380: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12037c) {
            ctx->pc = 0x120350u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120350;
        }
    }
    ctx->pc = 0x120384u;
    // 0x120384: 0x3c098000  lui         $t1, 0x8000
    ctx->pc = 0x120384u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32768 << 16));
label_120388:
    // 0x120388: 0x160182d  daddu       $v1, $t3, $zero
    ctx->pc = 0x120388u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12038c: 0x1892021  addu        $a0, $t4, $t1
    ctx->pc = 0x12038cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 9)));
    // 0x120390: 0x65102a  slt         $v0, $v1, $a1
    ctx->pc = 0x120390u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x120394: 0x945024  and         $t2, $a0, $s4
    ctx->pc = 0x120394u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 4) & GPR_U64(ctx, 20));
    // 0x120398: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x120398u;
    {
        const bool branch_taken_0x120398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120398u;
            // 0x12039c: 0xe4402b  sltu        $t0, $a3, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120398) {
            ctx->pc = 0x1203B0u;
            goto label_1203b0;
        }
    }
    ctx->pc = 0x1203A0u;
    // 0x1203a0: 0x1465000d  bne         $v1, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1203A0u;
    {
        const bool branch_taken_0x1203a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1203A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203A0u;
            // 0x1203a4: 0xf41024  and         $v0, $a3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203a0) {
            ctx->pc = 0x1203D8u;
            goto label_1203d8;
        }
    }
    ctx->pc = 0x1203A8u;
    // 0x1203a8: 0x5500000c  bnel        $t0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1203A8u;
    {
        const bool branch_taken_0x1203a8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x1203a8) {
            ctx->pc = 0x1203ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1203A8u;
            // 0x1203ac: 0x73840  sll         $a3, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1203DCu;
            goto label_1203dc;
        }
    }
    ctx->pc = 0x1203B0u;
label_1203b0:
    // 0x1203b0: 0x896021  addu        $t4, $a0, $t1
    ctx->pc = 0x1203b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1203b4: 0x15540003  bne         $t2, $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1203B4u;
    {
        const bool branch_taken_0x1203b4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 20));
        ctx->pc = 0x1203B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203B4u;
            // 0x1203b8: 0x1943024  and         $a2, $t4, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203b4) {
            ctx->pc = 0x1203C4u;
            goto label_1203c4;
        }
    }
    ctx->pc = 0x1203BCu;
    // 0x1203bc: 0x25620001  addiu       $v0, $t3, 0x1
    ctx->pc = 0x1203bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1203c0: 0x46580a  movz        $t3, $v0, $a2
    ctx->pc = 0x1203c0u;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 11, GPR_VEC(ctx, 2));
label_1203c4:
    // 0x1203c4: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x1203c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1203c8: 0xe43823  subu        $a3, $a3, $a0
    ctx->pc = 0x1203c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x1203cc: 0x2499021  addu        $s2, $s2, $t1
    ctx->pc = 0x1203ccu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 9)));
    // 0x1203d0: 0xa82823  subu        $a1, $a1, $t0
    ctx->pc = 0x1203d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x1203d4: 0xf41024  and         $v0, $a3, $s4
    ctx->pc = 0x1203d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & GPR_U64(ctx, 20));
label_1203d8:
    // 0x1203d8: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1203d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_1203dc:
    // 0x1203dc: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x1203dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x1203e0: 0x94842  srl         $t1, $t1, 1
    ctx->pc = 0x1203e0u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
    // 0x1203e4: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1203e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1203e8: 0x1520ffe7  bnez        $t1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1203E8u;
    {
        const bool branch_taken_0x1203e8 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x1203ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203E8u;
            // 0x1203ec: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203e8) {
            ctx->pc = 0x120388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120388;
        }
    }
    ctx->pc = 0x1203F0u;
    // 0x1203f0: 0xa71025  or          $v0, $a1, $a3
    ctx->pc = 0x1203f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1203f4: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1203F4u;
    {
        const bool branch_taken_0x1203f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1203F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1203F4u;
            // 0x1203f8: 0x123842  srl         $a3, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1203f4) {
            ctx->pc = 0x120468u;
            goto label_120468;
        }
    }
    ctx->pc = 0x1203FCu;
    // 0x1203fc: 0x3410ffc0  ori         $s0, $zero, 0xFFC0
    ctx->pc = 0x1203fcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x120400: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x120400u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x120404: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120408: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120408u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12040c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x12040Cu;
    SET_GPR_U32(ctx, 31, 0x120414u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120414u; }
        if (ctx->pc != 0x120414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120414u; }
        if (ctx->pc != 0x120414u) { return; }
    }
    ctx->pc = 0x120414u;
label_120414:
    // 0x120414: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x120414u;
    {
        const bool branch_taken_0x120414 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x120418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120414u;
            // 0x120418: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120414) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x12041Cu;
    // 0x12041c: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12041Cu;
    {
        const bool branch_taken_0x12041c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x12041c) {
            ctx->pc = 0x120430u;
            goto label_120430;
        }
    }
    ctx->pc = 0x120424u;
    // 0x120424: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x120424u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120428: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x120428u;
    {
        const bool branch_taken_0x120428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12042Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120428u;
            // 0x12042c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120428) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x120430u;
label_120430:
    // 0x120430: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120430u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120434: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x120434u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120438: 0xc0448a6  jal         func_112298
    ctx->pc = 0x120438u;
    SET_GPR_U32(ctx, 31, 0x120440u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120440u; }
        if (ctx->pc != 0x120440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120440u; }
        if (ctx->pc != 0x120440u) { return; }
    }
    ctx->pc = 0x120440u;
label_120440:
    // 0x120440: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x120440u;
    {
        const bool branch_taken_0x120440 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x120444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120440u;
            // 0x120444: 0x32420001  andi        $v0, $s2, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120440) {
            ctx->pc = 0x120460u;
            goto label_120460;
        }
    }
    ctx->pc = 0x120448u;
    // 0x120448: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x120448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x12044c: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x12044cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x120450: 0x2421026  xor         $v0, $s2, $v0
    ctx->pc = 0x120450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ GPR_U64(ctx, 2));
    // 0x120454: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x120454u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x120458: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x120458u;
    {
        const bool branch_taken_0x120458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120458u;
            // 0x12045c: 0x62980a  movz        $s3, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120458) {
            ctx->pc = 0x120464u;
            goto label_120464;
        }
    }
    ctx->pc = 0x120460u;
label_120460:
    // 0x120460: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x120460u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_120464:
    // 0x120464: 0x123842  srl         $a3, $s2, 1
    ctx->pc = 0x120464u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
label_120468:
    // 0x120468: 0x131043  sra         $v0, $s3, 1
    ctx->pc = 0x120468u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 19), 1));
    // 0x12046c: 0x3c053fe0  lui         $a1, 0x3FE0
    ctx->pc = 0x12046cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16352 << 16));
    // 0x120470: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x120470u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x120474: 0xf41025  or          $v0, $a3, $s4
    ctx->pc = 0x120474u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 20));
    // 0x120478: 0x32640001  andi        $a0, $s3, 0x1
    ctx->pc = 0x120478u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x12047c: 0x111d00  sll         $v1, $s1, 20
    ctx->pc = 0x12047cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 20));
    // 0x120480: 0x44380b  movn        $a3, $v0, $a0
    ctx->pc = 0x120480u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 2));
    // 0x120484: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x120484u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x120488: 0x5203c  dsll32      $a0, $a1, 0
    ctx->pc = 0x120488u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) << (32 + 0));
    // 0x12048c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x12048cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x120490: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x120490u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x120494: 0x2a2a824  and         $s5, $s5, $v0
    ctx->pc = 0x120494u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x120498: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x120498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12049c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x12049cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1204a0: 0x7183c  dsll32      $v1, $a3, 0
    ctx->pc = 0x1204a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
    // 0x1204a4: 0x2a4a825  or          $s5, $s5, $a0
    ctx->pc = 0x1204a4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | GPR_U64(ctx, 4));
    // 0x1204a8: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1204a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1204ac: 0x2a2a824  and         $s5, $s5, $v0
    ctx->pc = 0x1204acu;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x1204b0: 0x2a38025  or          $s0, $s5, $v1
    ctx->pc = 0x1204b0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 21) | GPR_U64(ctx, 3));
    // 0x1204b4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1204b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1204b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1204b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1204bc:
    // 0x1204bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1204bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1204c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1204c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1204c4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1204c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1204c8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1204c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1204cc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1204ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1204d0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1204d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1204d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1204D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1204D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1204D4u;
            // 0x1204d8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1204DCu;
    // 0x1204dc: 0x0  nop
    ctx->pc = 0x1204dcu;
    // NOP
    // 0x1204e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1204e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1204e4: 0x460062c6  mov.s       $f11, $f12
    ctx->pc = 0x1204e4u;
    ctx->f[11] = FPU_MOV_S(ctx->f[12]);
    // 0x1204e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1204e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1204ec: 0xe7b60028  swc1        $f22, 0x28($sp)
    ctx->pc = 0x1204ecu;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x1204f0: 0xe7b50020  swc1        $f21, 0x20($sp)
    ctx->pc = 0x1204f0u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x1204f4: 0x44045800  mfc1        $a0, $f11
    ctx->pc = 0x1204f4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[11], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1204f8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1204f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1204fc: 0x3c053f80  lui         $a1, 0x3F80
    ctx->pc = 0x1204fcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16256 << 16));
    // 0x120500: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120500u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120504: 0x821824  and         $v1, $a0, $v0
    ctx->pc = 0x120504u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x120508: 0x14650009  bne         $v1, $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x120508u;
    {
        const bool branch_taken_0x120508 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x12050Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120508u;
            // 0x12050c: 0xe7b40018  swc1        $f20, 0x18($sp) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x120508) {
            ctx->pc = 0x120530u;
            goto label_120530;
        }
    }
    ctx->pc = 0x120510u;
    // 0x120510: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x120510u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120514: 0x1c8000f6  bgtz        $a0, . + 4 + (0xF6 << 2)
    ctx->pc = 0x120514u;
    {
        const bool branch_taken_0x120514 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x120518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120514u;
            // 0x120518: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120514) {
            ctx->pc = 0x1208F0u;
            goto label_1208f0;
        }
    }
    ctx->pc = 0x12051Cu;
    // 0x12051c: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x12051cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120520: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120520u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120524: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120524u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120528: 0x100000f2  b           . + 4 + (0xF2 << 2)
    ctx->pc = 0x120528u;
    {
        const bool branch_taken_0x120528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12052Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120528u;
            // 0x12052c: 0xc7b60028  lwc1        $f22, 0x28($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x120528) {
            ctx->pc = 0x1208F4u;
            goto label_1208f4;
        }
    }
    ctx->pc = 0x120530u;
label_120530:
    // 0x120530: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x120530u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120534: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x120534u;
    {
        const bool branch_taken_0x120534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x120538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120534u;
            // 0x120538: 0x3c023eff  lui         $v0, 0x3EFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120534) {
            ctx->pc = 0x120558u;
            goto label_120558;
        }
    }
    ctx->pc = 0x12053Cu;
    // 0x12053c: 0x460b5801  sub.s       $f0, $f11, $f11
    ctx->pc = 0x12053cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[11], ctx->f[11]);
    // 0x120540: 0x0  nop
    ctx->pc = 0x120540u;
    // NOP
    // 0x120544: 0x0  nop
    ctx->pc = 0x120544u;
    // NOP
    // 0x120548: 0x46000003  div.s       $f0, $f0, $f0
    ctx->pc = 0x120548u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[0];
    // 0x12054c: 0x100000e8  b           . + 4 + (0xE8 << 2)
    ctx->pc = 0x12054Cu;
    {
        const bool branch_taken_0x12054c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12054Cu;
            // 0x120550: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12054c) {
            ctx->pc = 0x1208F0u;
            goto label_1208f0;
        }
    }
    ctx->pc = 0x120554u;
    // 0x120554: 0x0  nop
    ctx->pc = 0x120554u;
    // NOP
label_120558:
    // 0x120558: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120558u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x12055c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x12055cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120560: 0x14400049  bnez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x120560u;
    {
        const bool branch_taken_0x120560 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120560u;
            // 0x120564: 0x3c022300  lui         $v0, 0x2300 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8960 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120560) {
            ctx->pc = 0x120688u;
            goto label_120688;
        }
    }
    ctx->pc = 0x120568u;
    // 0x120568: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x120568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x12056c: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x12056cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120570: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120570u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120574: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x120574u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120578: 0x104000dd  beqz        $v0, . + 4 + (0xDD << 2)
    ctx->pc = 0x120578u;
    {
        const bool branch_taken_0x120578 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12057Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120578u;
            // 0x12057c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120578) {
            ctx->pc = 0x1208F0u;
            goto label_1208f0;
        }
    }
    ctx->pc = 0x120580u;
    // 0x120580: 0x460b5d42  mul.s       $f21, $f11, $f11
    ctx->pc = 0x120580u;
    ctx->f[21] = FPU_MUL_S(ctx->f[11], ctx->f[11]);
    // 0x120584: 0x3c013811  lui         $at, 0x3811
    ctx->pc = 0x120584u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14353 << 16));
    // 0x120588: 0x3421ef08  ori         $at, $at, 0xEF08
    ctx->pc = 0x120588u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)61192);
    // 0x12058c: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x12058cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120590: 0x3c013a4f  lui         $at, 0x3A4F
    ctx->pc = 0x120590u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14927 << 16));
    // 0x120594: 0x34217f04  ori         $at, $at, 0x7F04
    ctx->pc = 0x120594u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)32516);
    // 0x120598: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x120598u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x12059c: 0x3c01bd24  lui         $at, 0xBD24
    ctx->pc = 0x12059cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48420 << 16));
    // 0x1205a0: 0x34211146  ori         $at, $at, 0x1146
    ctx->pc = 0x1205a0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4422);
    // 0x1205a4: 0x44813800  mtc1        $at, $f7
    ctx->pc = 0x1205a4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x1205a8: 0x3c013d9d  lui         $at, 0x3D9D
    ctx->pc = 0x1205a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15773 << 16));
    // 0x1205ac: 0x3421c62d  ori         $at, $at, 0xC62D
    ctx->pc = 0x1205acu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)50733);
    // 0x1205b0: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1205b0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1205b4: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x1205b4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x1205b8: 0x3c01bf30  lui         $at, 0xBF30
    ctx->pc = 0x1205b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48944 << 16));
    // 0x1205bc: 0x34213360  ori         $at, $at, 0x3360
    ctx->pc = 0x1205bcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)13152);
    // 0x1205c0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1205c0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1205c4: 0x4602a882  mul.s       $f2, $f21, $f2
    ctx->pc = 0x1205c4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[21], ctx->f[2]);
    // 0x1205c8: 0x3c013e4e  lui         $at, 0x3E4E
    ctx->pc = 0x1205c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15950 << 16));
    // 0x1205cc: 0x34210aa8  ori         $at, $at, 0xAA8
    ctx->pc = 0x1205ccu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)2728);
    // 0x1205d0: 0x44813000  mtc1        $at, $f6
    ctx->pc = 0x1205d0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[6], &bits, sizeof(bits)); }
    // 0x1205d4: 0x3c014001  lui         $at, 0x4001
    ctx->pc = 0x1205d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16385 << 16));
    // 0x1205d8: 0x3421572c  ori         $at, $at, 0x572C
    ctx->pc = 0x1205d8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)22316);
    // 0x1205dc: 0x44812000  mtc1        $at, $f4
    ctx->pc = 0x1205dcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x1205e0: 0x3c01bea6  lui         $at, 0xBEA6
    ctx->pc = 0x1205e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48806 << 16));
    // 0x1205e4: 0x3421b08f  ori         $at, $at, 0xB08F
    ctx->pc = 0x1205e4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)45199);
    // 0x1205e8: 0x44814800  mtc1        $at, $f9
    ctx->pc = 0x1205e8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x1205ec: 0x46030840  add.s       $f1, $f1, $f3
    ctx->pc = 0x1205ecu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x1205f0: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1205f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1205f4: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x1205f4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1205f8: 0x46001080  add.s       $f2, $f2, $f0
    ctx->pc = 0x1205f8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
    // 0x1205fc: 0x3c0133a2  lui         $at, 0x33A2
    ctx->pc = 0x1205fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13218 << 16));
    // 0x120600: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x120600u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120604: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120604u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120608: 0x3c01c019  lui         $at, 0xC019
    ctx->pc = 0x120608u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49177 << 16));
    // 0x12060c: 0x3421d138  ori         $at, $at, 0xD138
    ctx->pc = 0x12060cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)53560);
    // 0x120610: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x120610u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x120614: 0x3c013e2a  lui         $at, 0x3E2A
    ctx->pc = 0x120614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15914 << 16));
    // 0x120618: 0x3421aaaa  ori         $at, $at, 0xAAAA
    ctx->pc = 0x120618u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)43690);
    // 0x12061c: 0x44814000  mtc1        $at, $f8
    ctx->pc = 0x12061cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x120620: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120620u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x120624: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x120624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x120628: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120628u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x12062c: 0x44815000  mtc1        $at, $f10
    ctx->pc = 0x12062cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x120630: 0x4602a882  mul.s       $f2, $f21, $f2
    ctx->pc = 0x120630u;
    ctx->f[2] = FPU_MUL_S(ctx->f[21], ctx->f[2]);
    // 0x120634: 0x46070840  add.s       $f1, $f1, $f7
    ctx->pc = 0x120634u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[7]);
    // 0x120638: 0x46041080  add.s       $f2, $f2, $f4
    ctx->pc = 0x120638u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[4]);
    // 0x12063c: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x12063cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x120640: 0x4602a882  mul.s       $f2, $f21, $f2
    ctx->pc = 0x120640u;
    ctx->f[2] = FPU_MUL_S(ctx->f[21], ctx->f[2]);
    // 0x120644: 0x46060840  add.s       $f1, $f1, $f6
    ctx->pc = 0x120644u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[6]);
    // 0x120648: 0x46051080  add.s       $f2, $f2, $f5
    ctx->pc = 0x120648u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[5]);
    // 0x12064c: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x12064cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x120650: 0x4602a882  mul.s       $f2, $f21, $f2
    ctx->pc = 0x120650u;
    ctx->f[2] = FPU_MUL_S(ctx->f[21], ctx->f[2]);
    // 0x120654: 0x46090840  add.s       $f1, $f1, $f9
    ctx->pc = 0x120654u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[9]);
    // 0x120658: 0x46031580  add.s       $f22, $f2, $f3
    ctx->pc = 0x120658u;
    ctx->f[22] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x12065c: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x12065cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x120660: 0x46080840  add.s       $f1, $f1, $f8
    ctx->pc = 0x120660u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[8]);
    // 0x120664: 0x4601ad02  mul.s       $f20, $f21, $f1
    ctx->pc = 0x120664u;
    ctx->f[20] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x120668: 0x0  nop
    ctx->pc = 0x120668u;
    // NOP
    // 0x12066c: 0x0  nop
    ctx->pc = 0x12066cu;
    // NOP
    // 0x120670: 0x4616a303  div.s       $f12, $f20, $f22
    ctx->pc = 0x120670u;
    if (ctx->f[22] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[22])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[20] / ctx->f[22];
    // 0x120674: 0x460c5842  mul.s       $f1, $f11, $f12
    ctx->pc = 0x120674u;
    ctx->f[1] = FPU_MUL_S(ctx->f[11], ctx->f[12]);
    // 0x120678: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x120678u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x12067c: 0x46005801  sub.s       $f0, $f11, $f0
    ctx->pc = 0x12067cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[11], ctx->f[0]);
    // 0x120680: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x120680u;
    {
        const bool branch_taken_0x120680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120680u;
            // 0x120684: 0x46005001  sub.s       $f0, $f10, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[10], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120680) {
            ctx->pc = 0x1208F0u;
            goto label_1208f0;
        }
    }
    ctx->pc = 0x120688u;
label_120688:
    // 0x120688: 0x481004b  bgez        $a0, . + 4 + (0x4B << 2)
    ctx->pc = 0x120688u;
    {
        const bool branch_taken_0x120688 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x120688) {
            ctx->pc = 0x1207B8u;
            goto label_1207b8;
        }
    }
    ctx->pc = 0x120690u;
    // 0x120690: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x120690u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x120694: 0x44815000  mtc1        $at, $f10
    ctx->pc = 0x120694u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x120698: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x120698u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x12069c: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x12069cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1206a0: 0x460a5880  add.s       $f2, $f11, $f10
    ctx->pc = 0x1206a0u;
    ctx->f[2] = FPU_ADD_S(ctx->f[11], ctx->f[10]);
    // 0x1206a4: 0x3c013811  lui         $at, 0x3811
    ctx->pc = 0x1206a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14353 << 16));
    // 0x1206a8: 0x3421ef08  ori         $at, $at, 0xEF08
    ctx->pc = 0x1206a8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)61192);
    // 0x1206ac: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1206acu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1206b0: 0x3c013a4f  lui         $at, 0x3A4F
    ctx->pc = 0x1206b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14927 << 16));
    // 0x1206b4: 0x34217f04  ori         $at, $at, 0x7F04
    ctx->pc = 0x1206b4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)32516);
    // 0x1206b8: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x1206b8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x1206bc: 0x3c01bd24  lui         $at, 0xBD24
    ctx->pc = 0x1206bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48420 << 16));
    // 0x1206c0: 0x34211146  ori         $at, $at, 0x1146
    ctx->pc = 0x1206c0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4422);
    // 0x1206c4: 0x44813000  mtc1        $at, $f6
    ctx->pc = 0x1206c4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[6], &bits, sizeof(bits)); }
    // 0x1206c8: 0x3c013d9d  lui         $at, 0x3D9D
    ctx->pc = 0x1206c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15773 << 16));
    // 0x1206cc: 0x3421c62d  ori         $at, $at, 0xC62D
    ctx->pc = 0x1206ccu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)50733);
    // 0x1206d0: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1206d0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1206d4: 0x46031542  mul.s       $f21, $f2, $f3
    ctx->pc = 0x1206d4u;
    ctx->f[21] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x1206d8: 0x3c014001  lui         $at, 0x4001
    ctx->pc = 0x1206d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16385 << 16));
    // 0x1206dc: 0x3421572c  ori         $at, $at, 0x572C
    ctx->pc = 0x1206dcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)22316);
    // 0x1206e0: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1206e0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1206e4: 0x3c01bf30  lui         $at, 0xBF30
    ctx->pc = 0x1206e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48944 << 16));
    // 0x1206e8: 0x34213360  ori         $at, $at, 0x3360
    ctx->pc = 0x1206e8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)13152);
    // 0x1206ec: 0x44812000  mtc1        $at, $f4
    ctx->pc = 0x1206ecu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x1206f0: 0x3c013e4e  lui         $at, 0x3E4E
    ctx->pc = 0x1206f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15950 << 16));
    // 0x1206f4: 0x34210aa8  ori         $at, $at, 0xAA8
    ctx->pc = 0x1206f4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)2728);
    // 0x1206f8: 0x44813800  mtc1        $at, $f7
    ctx->pc = 0x1206f8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x1206fc: 0x3c01bea6  lui         $at, 0xBEA6
    ctx->pc = 0x1206fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48806 << 16));
    // 0x120700: 0x3421b08f  ori         $at, $at, 0xB08F
    ctx->pc = 0x120700u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)45199);
    // 0x120704: 0x44814800  mtc1        $at, $f9
    ctx->pc = 0x120704u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x120708: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120708u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x12070c: 0x3c01c019  lui         $at, 0xC019
    ctx->pc = 0x12070cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49177 << 16));
    // 0x120710: 0x3421d138  ori         $at, $at, 0xD138
    ctx->pc = 0x120710u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)53560);
    // 0x120714: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x120714u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x120718: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120718u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12071c: 0x3c013e2a  lui         $at, 0x3E2A
    ctx->pc = 0x12071cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15914 << 16));
    // 0x120720: 0x3421aaaa  ori         $at, $at, 0xAAAA
    ctx->pc = 0x120720u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)43690);
    // 0x120724: 0x44814000  mtc1        $at, $f8
    ctx->pc = 0x120724u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x120728: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x120728u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x12072c: 0x46050000  add.s       $f0, $f0, $f5
    ctx->pc = 0x12072cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[5]);
    // 0x120730: 0x46040840  add.s       $f1, $f1, $f4
    ctx->pc = 0x120730u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x120734: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120734u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x120738: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120738u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12073c: 0x46060000  add.s       $f0, $f0, $f6
    ctx->pc = 0x12073cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x120740: 0x46020840  add.s       $f1, $f1, $f2
    ctx->pc = 0x120740u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x120744: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120744u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x120748: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120748u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12074c: 0x46070000  add.s       $f0, $f0, $f7
    ctx->pc = 0x12074cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[7]);
    // 0x120750: 0x46030840  add.s       $f1, $f1, $f3
    ctx->pc = 0x120750u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x120754: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120754u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x120758: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120758u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12075c: 0x46090000  add.s       $f0, $f0, $f9
    ctx->pc = 0x12075cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[9]);
    // 0x120760: 0x460a0d80  add.s       $f22, $f1, $f10
    ctx->pc = 0x120760u;
    ctx->f[22] = FPU_ADD_S(ctx->f[1], ctx->f[10]);
    // 0x120764: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120764u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x120768: 0x46080000  add.s       $f0, $f0, $f8
    ctx->pc = 0x120768u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[8]);
    // 0x12076c: 0xc0483a6  jal         func_120E98
    ctx->pc = 0x12076Cu;
    SET_GPR_U32(ctx, 31, 0x120774u);
    ctx->pc = 0x120770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12076Cu;
            // 0x120770: 0x4600ad02  mul.s       $f20, $f21, $f0 (Delay Slot)
        ctx->f[20] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x120E98u;
    if (runtime->hasFunction(0x120E98u)) {
        auto targetFn = runtime->lookupFunction(0x120E98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120774u; }
        if (ctx->pc != 0x120774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120E98_0x120e98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120774u; }
        if (ctx->pc != 0x120774u) { return; }
    }
    ctx->pc = 0x120774u;
label_120774:
    // 0x120774: 0x46000346  mov.s       $f13, $f0
    ctx->pc = 0x120774u;
    ctx->f[13] = FPU_MOV_S(ctx->f[0]);
    // 0x120778: 0x3c0133a2  lui         $at, 0x33A2
    ctx->pc = 0x120778u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13218 << 16));
    // 0x12077c: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x12077cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120780: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120780u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120784: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x120784u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120788: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120788u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x12078c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x12078cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120790: 0x0  nop
    ctx->pc = 0x120790u;
    // NOP
    // 0x120794: 0x0  nop
    ctx->pc = 0x120794u;
    // NOP
    // 0x120798: 0x4616a303  div.s       $f12, $f20, $f22
    ctx->pc = 0x120798u;
    if (ctx->f[22] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[22])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[20] / ctx->f[22];
    // 0x12079c: 0x460d6002  mul.s       $f0, $f12, $f13
    ctx->pc = 0x12079cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[13]);
    // 0x1207a0: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x1207a0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1207a4: 0x46006800  add.s       $f0, $f13, $f0
    ctx->pc = 0x1207a4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[13], ctx->f[0]);
    // 0x1207a8: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x1207a8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
    // 0x1207ac: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1207ACu;
    {
        const bool branch_taken_0x1207ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1207B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1207ACu;
            // 0x1207b0: 0x46001001  sub.s       $f0, $f2, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1207ac) {
            ctx->pc = 0x1208ECu;
            goto label_1208ec;
        }
    }
    ctx->pc = 0x1207B4u;
    // 0x1207b4: 0x0  nop
    ctx->pc = 0x1207b4u;
    // NOP
label_1207b8:
    // 0x1207b8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1207b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1207bc: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x1207bcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x1207c0: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x1207c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x1207c4: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1207c4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1207c8: 0x460ba001  sub.s       $f0, $f20, $f11
    ctx->pc = 0x1207c8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[20], ctx->f[11]);
    // 0x1207cc: 0x46010542  mul.s       $f21, $f0, $f1
    ctx->pc = 0x1207ccu;
    ctx->f[21] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1207d0: 0xc0483a6  jal         func_120E98
    ctx->pc = 0x1207D0u;
    SET_GPR_U32(ctx, 31, 0x1207D8u);
    ctx->pc = 0x1207D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1207D0u;
            // 0x1207d4: 0x4600ab06  mov.s       $f12, $f21 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[21]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x120E98u;
    if (runtime->hasFunction(0x120E98u)) {
        auto targetFn = runtime->lookupFunction(0x120E98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1207D8u; }
        if (ctx->pc != 0x1207D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00120E98_0x120e98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1207D8u; }
        if (ctx->pc != 0x1207D8u) { return; }
    }
    ctx->pc = 0x1207D8u;
label_1207d8:
    // 0x1207d8: 0x460002c6  mov.s       $f11, $f0
    ctx->pc = 0x1207d8u;
    ctx->f[11] = FPU_MOV_S(ctx->f[0]);
    // 0x1207dc: 0x46005b46  mov.s       $f13, $f11
    ctx->pc = 0x1207dcu;
    ctx->f[13] = FPU_MOV_S(ctx->f[11]);
    // 0x1207e0: 0xe7a00000  swc1        $f0, 0x0($sp)
    ctx->pc = 0x1207e0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1207e4: 0x2402f000  addiu       $v0, $zero, -0x1000
    ctx->pc = 0x1207e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294963200));
    // 0x1207e8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1207e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1207ec: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1207ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1207f0: 0x44835800  mtc1        $v1, $f11
    ctx->pc = 0x1207f0u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[11], &bits, sizeof(bits)); }
    // 0x1207f4: 0x460b58c2  mul.s       $f3, $f11, $f11
    ctx->pc = 0x1207f4u;
    ctx->f[3] = FPU_MUL_S(ctx->f[11], ctx->f[11]);
    // 0x1207f8: 0x3c013811  lui         $at, 0x3811
    ctx->pc = 0x1207f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14353 << 16));
    // 0x1207fc: 0x3421ef08  ori         $at, $at, 0xEF08
    ctx->pc = 0x1207fcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)61192);
    // 0x120800: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120800u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120804: 0x3c013a4f  lui         $at, 0x3A4F
    ctx->pc = 0x120804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14927 << 16));
    // 0x120808: 0x34217f04  ori         $at, $at, 0x7F04
    ctx->pc = 0x120808u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)32516);
    // 0x12080c: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x12080cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x120810: 0x3c01bd24  lui         $at, 0xBD24
    ctx->pc = 0x120810u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48420 << 16));
    // 0x120814: 0x34211146  ori         $at, $at, 0x1146
    ctx->pc = 0x120814u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4422);
    // 0x120818: 0x44814800  mtc1        $at, $f9
    ctx->pc = 0x120818u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x12081c: 0x3c013d9d  lui         $at, 0x3D9D
    ctx->pc = 0x12081cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15773 << 16));
    // 0x120820: 0x3421c62d  ori         $at, $at, 0xC62D
    ctx->pc = 0x120820u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)50733);
    // 0x120824: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120824u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120828: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120828u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x12082c: 0x3c01bf30  lui         $at, 0xBF30
    ctx->pc = 0x12082cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48944 << 16));
    // 0x120830: 0x34213360  ori         $at, $at, 0x3360
    ctx->pc = 0x120830u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)13152);
    // 0x120834: 0x44812000  mtc1        $at, $f4
    ctx->pc = 0x120834u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x120838: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120838u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12083c: 0x3c013e4e  lui         $at, 0x3E4E
    ctx->pc = 0x12083cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15950 << 16));
    // 0x120840: 0x34210aa8  ori         $at, $at, 0xAA8
    ctx->pc = 0x120840u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)2728);
    // 0x120844: 0x44814000  mtc1        $at, $f8
    ctx->pc = 0x120844u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x120848: 0x3c014001  lui         $at, 0x4001
    ctx->pc = 0x120848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16385 << 16));
    // 0x12084c: 0x3421572c  ori         $at, $at, 0x572C
    ctx->pc = 0x12084cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)22316);
    // 0x120850: 0x44813800  mtc1        $at, $f7
    ctx->pc = 0x120850u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x120854: 0x4603a8c1  sub.s       $f3, $f21, $f3
    ctx->pc = 0x120854u;
    ctx->f[3] = FPU_SUB_S(ctx->f[21], ctx->f[3]);
    // 0x120858: 0x3c01bea6  lui         $at, 0xBEA6
    ctx->pc = 0x120858u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)48806 << 16));
    // 0x12085c: 0x3421b08f  ori         $at, $at, 0xB08F
    ctx->pc = 0x12085cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)45199);
    // 0x120860: 0x44815000  mtc1        $at, $f10
    ctx->pc = 0x120860u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x120864: 0x460b6880  add.s       $f2, $f13, $f11
    ctx->pc = 0x120864u;
    ctx->f[2] = FPU_ADD_S(ctx->f[13], ctx->f[11]);
    // 0x120868: 0x46050000  add.s       $f0, $f0, $f5
    ctx->pc = 0x120868u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[5]);
    // 0x12086c: 0x3c013e2a  lui         $at, 0x3E2A
    ctx->pc = 0x12086cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15914 << 16));
    // 0x120870: 0x3421aaaa  ori         $at, $at, 0xAAAA
    ctx->pc = 0x120870u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)43690);
    // 0x120874: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x120874u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x120878: 0x46040840  add.s       $f1, $f1, $f4
    ctx->pc = 0x120878u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x12087c: 0x3c01c019  lui         $at, 0xC019
    ctx->pc = 0x12087cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49177 << 16));
    // 0x120880: 0x3421d138  ori         $at, $at, 0xD138
    ctx->pc = 0x120880u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)53560);
    // 0x120884: 0x44813000  mtc1        $at, $f6
    ctx->pc = 0x120884u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[6], &bits, sizeof(bits)); }
    // 0x120888: 0x0  nop
    ctx->pc = 0x120888u;
    // NOP
    // 0x12088c: 0x0  nop
    ctx->pc = 0x12088cu;
    // NOP
    // 0x120890: 0x460218c3  div.s       $f3, $f3, $f2
    ctx->pc = 0x120890u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[3]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[3] = std::bit_cast<float>(__maxf); } else ctx->f[3] = ctx->f[3] / ctx->f[2];
    // 0x120894: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x120894u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x120898: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x120898u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x12089c: 0x46090000  add.s       $f0, $f0, $f9
    ctx->pc = 0x12089cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[9]);
    // 0x1208a0: 0x46070840  add.s       $f1, $f1, $f7
    ctx->pc = 0x1208a0u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[7]);
    // 0x1208a4: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x1208a4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x1208a8: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x1208a8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x1208ac: 0x46080000  add.s       $f0, $f0, $f8
    ctx->pc = 0x1208acu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[8]);
    // 0x1208b0: 0x46060840  add.s       $f1, $f1, $f6
    ctx->pc = 0x1208b0u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[6]);
    // 0x1208b4: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x1208b4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x1208b8: 0x4601a842  mul.s       $f1, $f21, $f1
    ctx->pc = 0x1208b8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[21], ctx->f[1]);
    // 0x1208bc: 0x460a0000  add.s       $f0, $f0, $f10
    ctx->pc = 0x1208bcu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[10]);
    // 0x1208c0: 0x46140d80  add.s       $f22, $f1, $f20
    ctx->pc = 0x1208c0u;
    ctx->f[22] = FPU_ADD_S(ctx->f[1], ctx->f[20]);
    // 0x1208c4: 0x4600a802  mul.s       $f0, $f21, $f0
    ctx->pc = 0x1208c4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x1208c8: 0x46050000  add.s       $f0, $f0, $f5
    ctx->pc = 0x1208c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[5]);
    // 0x1208cc: 0x4600ad02  mul.s       $f20, $f21, $f0
    ctx->pc = 0x1208ccu;
    ctx->f[20] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x1208d0: 0x0  nop
    ctx->pc = 0x1208d0u;
    // NOP
    // 0x1208d4: 0x0  nop
    ctx->pc = 0x1208d4u;
    // NOP
    // 0x1208d8: 0x4616a303  div.s       $f12, $f20, $f22
    ctx->pc = 0x1208d8u;
    if (ctx->f[22] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[22])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[20] / ctx->f[22];
    // 0x1208dc: 0x460d6002  mul.s       $f0, $f12, $f13
    ctx->pc = 0x1208dcu;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[13]);
    // 0x1208e0: 0x46030000  add.s       $f0, $f0, $f3
    ctx->pc = 0x1208e0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x1208e4: 0x46005800  add.s       $f0, $f11, $f0
    ctx->pc = 0x1208e4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[11], ctx->f[0]);
    // 0x1208e8: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x1208e8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_1208ec:
    // 0x1208ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1208ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1208f0:
    // 0x1208f0: 0xc7b60028  lwc1        $f22, 0x28($sp)
    ctx->pc = 0x1208f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
label_1208f4:
    // 0x1208f4: 0xc7b50020  lwc1        $f21, 0x20($sp)
    ctx->pc = 0x1208f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x1208f8: 0xc7b40018  lwc1        $f20, 0x18($sp)
    ctx->pc = 0x1208f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1208fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1208FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x120900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1208FCu;
            // 0x120900: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x120904u;
    // 0x120904: 0x0  nop
    ctx->pc = 0x120904u;
    // NOP
    // 0x120908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x120908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12090c: 0x46006046  mov.s       $f1, $f12
    ctx->pc = 0x12090cu;
    ctx->f[1] = FPU_MOV_S(ctx->f[12]);
    // 0x120910: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x120910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x120914: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x120914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x120918: 0x44066800  mfc1        $a2, $f13
    ctx->pc = 0x120918u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x12091c: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x12091cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x120920: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120924: 0xc24024  and         $t0, $a2, $v0
    ctx->pc = 0x120924u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x120928: 0x44050800  mfc1        $a1, $f1
    ctx->pc = 0x120928u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x12092c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x12092cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x120930: 0x14c30005  bne         $a2, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x120930u;
    {
        const bool branch_taken_0x120930 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        ctx->pc = 0x120934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120930u;
            // 0x120934: 0xa23824  and         $a3, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120930) {
            ctx->pc = 0x120948u;
            goto label_120948;
        }
    }
    ctx->pc = 0x120938u;
    // 0x120938: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x120938u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12093c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12093cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x120940: 0x8048850  j           func_122140
    ctx->pc = 0x120940u;
    ctx->pc = 0x120944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x120940u;
            // 0x120944: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122140u;
    if (runtime->hasFunction(0x122140u)) {
        auto targetFn = runtime->lookupFunction(0x122140u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122140_0x122140(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x120948u;
label_120948:
    // 0x120948: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x120948u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
    // 0x12094c: 0x62783  sra         $a0, $a2, 30
    ctx->pc = 0x12094cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 6), 30));
    // 0x120950: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120950u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120954: 0x30840002  andi        $a0, $a0, 0x2
    ctx->pc = 0x120954u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
    // 0x120958: 0x51fc2  srl         $v1, $a1, 31
    ctx->pc = 0x120958u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x12095c: 0x47102a  slt         $v0, $v0, $a3
    ctx->pc = 0x12095cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x120960: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x120960u;
    {
        const bool branch_taken_0x120960 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120960u;
            // 0x120964: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120960) {
            ctx->pc = 0x1209ACu;
            goto label_1209ac;
        }
    }
    ctx->pc = 0x120968u;
    // 0x120968: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x120968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12096c: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x12096cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120970: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120970u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120974: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120974u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120978: 0x12020057  beq         $s0, $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x120978u;
    {
        const bool branch_taken_0x120978 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x12097Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120978u;
            // 0x12097c: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120978) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120980u;
    // 0x120980: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x120980u;
    {
        const bool branch_taken_0x120980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x120980) {
            ctx->pc = 0x120984u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120980u;
            // 0x120984: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120998u;
            goto label_120998;
        }
    }
    ctx->pc = 0x120988u;
    // 0x120988: 0x6000009  bltz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x120988u;
    {
        const bool branch_taken_0x120988 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x12098Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120988u;
            // 0x12098c: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120988) {
            ctx->pc = 0x1209B0u;
            goto label_1209b0;
        }
    }
    ctx->pc = 0x120990u;
    // 0x120990: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x120990u;
    {
        const bool branch_taken_0x120990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120990u;
            // 0x120994: 0x46000806  mov.s       $f0, $f1 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120990) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120998u;
label_120998:
    // 0x120998: 0x3c01c049  lui         $at, 0xC049
    ctx->pc = 0x120998u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49225 << 16));
    // 0x12099c: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x12099cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209a0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209a0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209a4: 0x5202004d  beql        $s0, $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x1209A4u;
    {
        const bool branch_taken_0x1209a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1209a4) {
            ctx->pc = 0x1209A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1209A4u;
            // 0x1209a8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120ADCu;
            goto label_120adc;
        }
    }
    ctx->pc = 0x1209ACu;
label_1209ac:
    // 0x1209ac: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x1209acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
label_1209b0:
    // 0x1209b0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1209b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1209b4: 0x48102a  slt         $v0, $v0, $t0
    ctx->pc = 0x1209b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1209b8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1209B8u;
    {
        const bool branch_taken_0x1209b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1209BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209B8u;
            // 0x1209bc: 0xe81823  subu        $v1, $a3, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209b8) {
            ctx->pc = 0x1209E8u;
            goto label_1209e8;
        }
    }
    ctx->pc = 0x1209C0u;
    // 0x1209c0: 0x3c01bfc9  lui         $at, 0xBFC9
    ctx->pc = 0x1209c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49097 << 16));
    // 0x1209c4: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209c4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209c8: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209c8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209cc: 0x4a00042  bltz        $a1, . + 4 + (0x42 << 2)
    ctx->pc = 0x1209CCu;
    {
        const bool branch_taken_0x1209cc = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1209D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209CCu;
            // 0x1209d0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209cc) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x1209D4u;
    // 0x1209d4: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x1209d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x1209d8: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209d8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209dc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209dcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209e0: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x1209E0u;
    {
        const bool branch_taken_0x1209e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1209E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209E0u;
            // 0x1209e4: 0xdfbf0018  ld          $ra, 0x18($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209e0) {
            ctx->pc = 0x120AE0u;
            goto label_120ae0;
        }
    }
    ctx->pc = 0x1209E8u;
label_1209e8:
    // 0x1209e8: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x1209e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x1209ec: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209ecu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209f0: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1209f0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1209f4: 0x31dc3  sra         $v1, $v1, 23
    ctx->pc = 0x1209f4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 23));
    // 0x1209f8: 0x2862003d  slti        $v0, $v1, 0x3D
    ctx->pc = 0x1209f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)61) ? 1 : 0);
    // 0x1209fc: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1209FCu;
    {
        const bool branch_taken_0x1209fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209FCu;
            // 0x120a00: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209fc) {
            ctx->pc = 0x120A3Cu;
            goto label_120a3c;
        }
    }
    ctx->pc = 0x120A04u;
    // 0x120a04: 0x4c10004  bgez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x120A04u;
    {
        const bool branch_taken_0x120a04 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x120A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A04u;
            // 0x120a08: 0x2862ffc4  slti        $v0, $v1, -0x3C (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4294967236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a04) {
            ctx->pc = 0x120A18u;
            goto label_120a18;
        }
    }
    ctx->pc = 0x120A0Cu;
    // 0x120a0c: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x120a0cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120a10: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x120A10u;
    {
        const bool branch_taken_0x120a10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A10u;
            // 0x120a14: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a10) {
            ctx->pc = 0x120A3Cu;
            goto label_120a3c;
        }
    }
    ctx->pc = 0x120A18u;
label_120a18:
    // 0x120a18: 0x0  nop
    ctx->pc = 0x120a18u;
    // NOP
    // 0x120a1c: 0x0  nop
    ctx->pc = 0x120a1cu;
    // NOP
    // 0x120a20: 0x460d0b03  div.s       $f12, $f1, $f13
    ctx->pc = 0x120a20u;
    if (ctx->f[13] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[13])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[1] / ctx->f[13];
    // 0x120a24: 0xc04892a  jal         func_1224A8
    ctx->pc = 0x120A24u;
    SET_GPR_U32(ctx, 31, 0x120A2Cu);
    ctx->pc = 0x1224A8u;
    if (runtime->hasFunction(0x1224A8u)) {
        auto targetFn = runtime->lookupFunction(0x1224A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A2Cu; }
        if (ctx->pc != 0x120A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001224A8_0x1224a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A2Cu; }
        if (ctx->pc != 0x120A2Cu) { return; }
    }
    ctx->pc = 0x120A2Cu;
label_120a2c:
    // 0x120a2c: 0xc048850  jal         func_122140
    ctx->pc = 0x120A2Cu;
    SET_GPR_U32(ctx, 31, 0x120A34u);
    ctx->pc = 0x120A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x120A2Cu;
            // 0x120a30: 0x46000306  mov.s       $f12, $f0 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x122140u;
    if (runtime->hasFunction(0x122140u)) {
        auto targetFn = runtime->lookupFunction(0x122140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A34u; }
        if (ctx->pc != 0x120A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122140_0x122140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A34u; }
        if (ctx->pc != 0x120A34u) { return; }
    }
    ctx->pc = 0x120A34u;
label_120a34:
    // 0x120a34: 0x46000086  mov.s       $f2, $f0
    ctx->pc = 0x120a34u;
    ctx->f[2] = FPU_MOV_S(ctx->f[0]);
    // 0x120a38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x120a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_120a3c:
    // 0x120a3c: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x120A3Cu;
    {
        const bool branch_taken_0x120a3c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x120A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A3Cu;
            // 0x120a40: 0x2a020002  slti        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a3c) {
            ctx->pc = 0x120A70u;
            goto label_120a70;
        }
    }
    ctx->pc = 0x120A44u;
    // 0x120a44: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x120A44u;
    {
        const bool branch_taken_0x120a44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a44) {
            ctx->pc = 0x120A48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120A44u;
            // 0x120a48: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120A60u;
            goto label_120a60;
        }
    }
    ctx->pc = 0x120A4Cu;
    // 0x120a4c: 0x12000022  beqz        $s0, . + 4 + (0x22 << 2)
    ctx->pc = 0x120A4Cu;
    {
        const bool branch_taken_0x120a4c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A4Cu;
            // 0x120a50: 0x46001006  mov.s       $f0, $f2 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a4c) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120A54u;
    // 0x120a54: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x120A54u;
    {
        const bool branch_taken_0x120a54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a54) {
            ctx->pc = 0x120AB8u;
            goto label_120ab8;
        }
    }
    ctx->pc = 0x120A5Cu;
    // 0x120a5c: 0x0  nop
    ctx->pc = 0x120a5cu;
    // NOP
label_120a60:
    // 0x120a60: 0x1202000b  beq         $s0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x120A60u;
    {
        const bool branch_taken_0x120a60 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x120a60) {
            ctx->pc = 0x120A90u;
            goto label_120a90;
        }
    }
    ctx->pc = 0x120A68u;
    // 0x120a68: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x120A68u;
    {
        const bool branch_taken_0x120a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a68) {
            ctx->pc = 0x120AB8u;
            goto label_120ab8;
        }
    }
    ctx->pc = 0x120A70u;
label_120a70:
    // 0x120a70: 0xe7a20000  swc1        $f2, 0x0($sp)
    ctx->pc = 0x120a70u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x120a74: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x120a74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x120a78: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x120a78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x120a7c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x120a7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x120a80: 0x44831000  mtc1        $v1, $f2
    ctx->pc = 0x120a80u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120a84: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x120A84u;
    {
        const bool branch_taken_0x120a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A84u;
            // 0x120a88: 0x46001006  mov.s       $f0, $f2 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a84) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120A8Cu;
    // 0x120a8c: 0x0  nop
    ctx->pc = 0x120a8cu;
    // NOP
label_120a90:
    // 0x120a90: 0x3c013422  lui         $at, 0x3422
    ctx->pc = 0x120a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13346 << 16));
    // 0x120a94: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x120a94u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120a98: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120a98u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120a9c: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x120a9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120aa0: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120aa0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120aa4: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120aa4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120aa8: 0x46001001  sub.s       $f0, $f2, $f0
    ctx->pc = 0x120aa8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120aac: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x120AACu;
    {
        const bool branch_taken_0x120aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120AACu;
            // 0x120ab0: 0x46000801  sub.s       $f0, $f1, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120aac) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120AB4u;
    // 0x120ab4: 0x0  nop
    ctx->pc = 0x120ab4u;
    // NOP
label_120ab8:
    // 0x120ab8: 0x3c013422  lui         $at, 0x3422
    ctx->pc = 0x120ab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13346 << 16));
    // 0x120abc: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x120abcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120ac0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120ac0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120ac4: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x120ac4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120ac8: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120ac8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120acc: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120accu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120ad0: 0x46001001  sub.s       $f0, $f2, $f0
    ctx->pc = 0x120ad0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120ad4: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x120ad4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
label_120ad8:
    // 0x120ad8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x120ad8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_120adc:
    // 0x120adc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x120adcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_120ae0:
    // 0x120ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x120AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x120AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120AE0u;
            // 0x120ae4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F800u: goto label_11f800;
            case 0x11F810u: goto label_11f810;
            case 0x11F820u: goto label_11f820;
            case 0x11F848u: goto label_11f848;
            case 0x11F84Cu: goto label_11f84c;
            case 0x11F854u: goto label_11f854;
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            case 0x120210u: goto label_120210;
            case 0x120220u: goto label_120220;
            case 0x120228u: goto label_120228;
            case 0x120260u: goto label_120260;
            case 0x120270u: goto label_120270;
            case 0x120278u: goto label_120278;
            case 0x120288u: goto label_120288;
            case 0x1202A8u: goto label_1202a8;
            case 0x1202B8u: goto label_1202b8;
            case 0x1202D4u: goto label_1202d4;
            case 0x1202F0u: goto label_1202f0;
            case 0x120320u: goto label_120320;
            case 0x120350u: goto label_120350;
            case 0x12036Cu: goto label_12036c;
            case 0x120388u: goto label_120388;
            case 0x1203B0u: goto label_1203b0;
            case 0x1203C4u: goto label_1203c4;
            case 0x1203D8u: goto label_1203d8;
            case 0x1203DCu: goto label_1203dc;
            case 0x120414u: goto label_120414;
            case 0x120430u: goto label_120430;
            case 0x120440u: goto label_120440;
            case 0x120460u: goto label_120460;
            case 0x120464u: goto label_120464;
            case 0x120468u: goto label_120468;
            case 0x1204BCu: goto label_1204bc;
            case 0x120530u: goto label_120530;
            case 0x120558u: goto label_120558;
            case 0x120688u: goto label_120688;
            case 0x120774u: goto label_120774;
            case 0x1207B8u: goto label_1207b8;
            case 0x1207D8u: goto label_1207d8;
            case 0x1208ECu: goto label_1208ec;
            case 0x1208F0u: goto label_1208f0;
            case 0x1208F4u: goto label_1208f4;
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x120AE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
