#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135200
// Address: 0x135200 - 0x1353f8
void sub_00135200_0x135200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135200_0x135200");
#endif

    switch (ctx->pc) {
        case 0x135260u: goto label_135260;
        case 0x135290u: goto label_135290;
        case 0x1352c4u: goto label_1352c4;
        case 0x135340u: goto label_135340;
        case 0x135360u: goto label_135360;
        case 0x135398u: goto label_135398;
        case 0x1353ccu: goto label_1353cc;
        default: break;
    }

    ctx->pc = 0x135200u;

    // 0x135200: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135204: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x135204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135208: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x135208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13520c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13520cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x135210: 0x2484bb80  addiu       $a0, $a0, -0x4480
    ctx->pc = 0x135210u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949760));
    // 0x135214: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x135214u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135218: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13521c: 0x804d474  j           func_1351D0
    ctx->pc = 0x13521Cu;
    ctx->pc = 0x135220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13521Cu;
            // 0x135220: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1351D0u;
    if (runtime->hasFunction(0x1351D0u)) {
        auto targetFn = runtime->lookupFunction(0x1351D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001351D0_0x1351d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135224u;
    // 0x135224: 0x0  nop
    ctx->pc = 0x135224u;
    // NOP
    // 0x135228: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13522c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13522cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x135230: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135234: 0x3c110022  lui         $s1, 0x22
    ctx->pc = 0x135234u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
    // 0x135238: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13523c: 0x2442bb78  addiu       $v0, $v0, -0x4488
    ctx->pc = 0x13523cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949752));
    // 0x135240: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x135240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x135244: 0x8e23bb84  lw          $v1, -0x447C($s1)
    ctx->pc = 0x135244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294949764)));
    // 0x135248: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x135248u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13524c: 0x1460001f  bnez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x13524Cu;
    {
        const bool branch_taken_0x13524c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x135250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13524Cu;
            // 0x135250: 0x2623bb84  addiu       $v1, $s1, -0x447C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949764));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13524c) {
            ctx->pc = 0x1352CCu;
            goto label_1352cc;
        }
    }
    ctx->pc = 0x135254u;
    // 0x135254: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135254u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135258: 0x24030027  addiu       $v1, $zero, 0x27
    ctx->pc = 0x135258u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x13525c: 0x24421f28  addiu       $v0, $v0, 0x1F28
    ctx->pc = 0x13525cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7976));
label_135260:
    // 0x135260: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x135260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x135264: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x135264u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x135268: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x135268u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x13526c: 0x0  nop
    ctx->pc = 0x13526cu;
    // NOP
    // 0x135270: 0x0  nop
    ctx->pc = 0x135270u;
    // NOP
    // 0x135274: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x135274u;
    {
        const bool branch_taken_0x135274 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x135278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135274u;
            // 0x135278: 0x24420008  addiu       $v0, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135274) {
            ctx->pc = 0x135260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135260;
        }
    }
    ctx->pc = 0x13527Cu;
    // 0x13527c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x13527cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135280: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x135280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x135284: 0x24422068  addiu       $v0, $v0, 0x2068
    ctx->pc = 0x135284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x135288: 0x244201f4  addiu       $v0, $v0, 0x1F4
    ctx->pc = 0x135288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 500));
    // 0x13528c: 0x0  nop
    ctx->pc = 0x13528cu;
    // NOP
label_135290:
    // 0x135290: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x135290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x135294: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x135294u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x135298: 0x0  nop
    ctx->pc = 0x135298u;
    // NOP
    // 0x13529c: 0x0  nop
    ctx->pc = 0x13529cu;
    // NOP
    // 0x1352a0: 0x0  nop
    ctx->pc = 0x1352a0u;
    // NOP
    // 0x1352a4: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1352A4u;
    {
        const bool branch_taken_0x1352a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1352A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1352A4u;
            // 0x1352a8: 0x2442fff0  addiu       $v0, $v0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1352a4) {
            ctx->pc = 0x135290u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135290;
        }
    }
    ctx->pc = 0x1352ACu;
    // 0x1352ac: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1352acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1352b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1352b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1352b4: 0x26102268  addiu       $s0, $s0, 0x2268
    ctx->pc = 0x1352b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8808));
    // 0x1352b8: 0x24060009  addiu       $a2, $zero, 0x9
    ctx->pc = 0x1352b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1352bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1352BCu;
    SET_GPR_U32(ctx, 31, 0x1352C4u);
    ctx->pc = 0x1352C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1352BCu;
            // 0x1352c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1352C4u; }
        if (ctx->pc != 0x1352C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1352C4u; }
        if (ctx->pc != 0x1352C4u) { return; }
    }
    ctx->pc = 0x1352C4u;
label_1352c4:
    // 0x1352c4: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1352c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1352c8: 0x2623bb84  addiu       $v1, $s1, -0x447C
    ctx->pc = 0x1352c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949764));
label_1352cc:
    // 0x1352cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1352ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1352d0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1352d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1352d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1352d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1352d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1352d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1352dc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1352dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1352e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1352e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1352e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1352E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1352E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1352E4u;
            // 0x1352e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135260u: goto label_135260;
            case 0x135290u: goto label_135290;
            case 0x1352C4u: goto label_1352c4;
            case 0x1352CCu: goto label_1352cc;
            case 0x135340u: goto label_135340;
            case 0x135360u: goto label_135360;
            case 0x135368u: goto label_135368;
            case 0x135370u: goto label_135370;
            case 0x135398u: goto label_135398;
            case 0x1353CCu: goto label_1353cc;
            case 0x1353D0u: goto label_1353d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1352ECu;
    // 0x1352ec: 0x0  nop
    ctx->pc = 0x1352ecu;
    // NOP
    // 0x1352f0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1352f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1352f4: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1352f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1352f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1352f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1352fc: 0x2463bb84  addiu       $v1, $v1, -0x447C
    ctx->pc = 0x1352fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949764));
    // 0x135300: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135304: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x135304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135308: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x135308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13530c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13530cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x135310: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x135310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x135314: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x135314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x135318: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x135318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13531c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13531cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x135320: 0x1440002b  bnez        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x135320u;
    {
        const bool branch_taken_0x135320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135320u;
            // 0x135324: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135320) {
            ctx->pc = 0x1353D0u;
            goto label_1353d0;
        }
    }
    ctx->pc = 0x135328u;
    // 0x135328: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x13532c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13532cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135330: 0x24541f28  addiu       $s4, $v0, 0x1F28
    ctx->pc = 0x135330u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 7976));
    // 0x135334: 0x26950004  addiu       $s5, $s4, 0x4
    ctx->pc = 0x135334u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
    // 0x135338: 0x280902d  daddu       $s2, $s4, $zero
    ctx->pc = 0x135338u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13533c: 0x0  nop
    ctx->pc = 0x13533cu;
    // NOP
label_135340:
    // 0x135340: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x135340u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x135344: 0x1198c0  sll         $s3, $s1, 3
    ctx->pc = 0x135344u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x135348: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135348u;
    {
        const bool branch_taken_0x135348 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13534Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135348u;
            // 0x13534c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135348) {
            ctx->pc = 0x135368u;
            goto label_135368;
        }
    }
    ctx->pc = 0x135350u;
    // 0x135350: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x135350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x135354: 0x2a0802d  daddu       $s0, $s5, $zero
    ctx->pc = 0x135354u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135358: 0x40f809  jalr        $v0
    ctx->pc = 0x135358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135360u);
        ctx->pc = 0x13535Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135358u;
            // 0x13535c: 0x8e440004  lw          $a0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135360u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135260u: goto label_135260;
            case 0x135290u: goto label_135290;
            case 0x1352C4u: goto label_1352c4;
            case 0x1352CCu: goto label_1352cc;
            case 0x135340u: goto label_135340;
            case 0x135360u: goto label_135360;
            case 0x135368u: goto label_135368;
            case 0x135370u: goto label_135370;
            case 0x135398u: goto label_135398;
            case 0x1353CCu: goto label_1353cc;
            case 0x1353D0u: goto label_1353d0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135360u; }
            if (ctx->pc != 0x135360u) { return; }
        }
        }
    }
    ctx->pc = 0x135360u;
label_135360:
    // 0x135360: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x135360u;
    {
        const bool branch_taken_0x135360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135360u;
            // 0x135364: 0x2701021  addu        $v0, $s3, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135360) {
            ctx->pc = 0x135370u;
            goto label_135370;
        }
    }
    ctx->pc = 0x135368u;
label_135368:
    // 0x135368: 0x26900004  addiu       $s0, $s4, 0x4
    ctx->pc = 0x135368u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
    // 0x13536c: 0x2701021  addu        $v0, $s3, $s0
    ctx->pc = 0x13536cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
label_135370:
    // 0x135370: 0x2a230028  slti        $v1, $s1, 0x28
    ctx->pc = 0x135370u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)40) ? 1 : 0);
    // 0x135374: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x135374u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x135378: 0x26520008  addiu       $s2, $s2, 0x8
    ctx->pc = 0x135378u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x13537c: 0x1460fff0  bnez        $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x13537Cu;
    {
        const bool branch_taken_0x13537c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x135380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13537Cu;
            // 0x135380: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13537c) {
            ctx->pc = 0x135340u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135340;
        }
    }
    ctx->pc = 0x135384u;
    // 0x135384: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135388: 0x2411001f  addiu       $s1, $zero, 0x1F
    ctx->pc = 0x135388u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x13538c: 0x24422068  addiu       $v0, $v0, 0x2068
    ctx->pc = 0x13538cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x135390: 0x244201f4  addiu       $v0, $v0, 0x1F4
    ctx->pc = 0x135390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 500));
    // 0x135394: 0x0  nop
    ctx->pc = 0x135394u;
    // NOP
label_135398:
    // 0x135398: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x135398u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x13539c: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x13539cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1353a0: 0x0  nop
    ctx->pc = 0x1353a0u;
    // NOP
    // 0x1353a4: 0x0  nop
    ctx->pc = 0x1353a4u;
    // NOP
    // 0x1353a8: 0x0  nop
    ctx->pc = 0x1353a8u;
    // NOP
    // 0x1353ac: 0x621fffa  bgez        $s1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1353ACu;
    {
        const bool branch_taken_0x1353ac = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1353B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1353ACu;
            // 0x1353b0: 0x2442fff0  addiu       $v0, $v0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1353ac) {
            ctx->pc = 0x135398u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135398;
        }
    }
    ctx->pc = 0x1353B4u;
    // 0x1353b4: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1353b4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1353b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1353b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1353bc: 0x26102268  addiu       $s0, $s0, 0x2268
    ctx->pc = 0x1353bcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8808));
    // 0x1353c0: 0x24060009  addiu       $a2, $zero, 0x9
    ctx->pc = 0x1353c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1353c4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1353C4u;
    SET_GPR_U32(ctx, 31, 0x1353CCu);
    ctx->pc = 0x1353C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1353C4u;
            // 0x1353c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1353CCu; }
        if (ctx->pc != 0x1353CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1353CCu; }
        if (ctx->pc != 0x1353CCu) { return; }
    }
    ctx->pc = 0x1353CCu;
label_1353cc:
    // 0x1353cc: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1353ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1353d0:
    // 0x1353d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1353d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1353d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1353d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1353d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1353d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1353dc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1353dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1353e0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1353e0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1353e4: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1353e4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1353e8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1353e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1353ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1353ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1353F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1353ECu;
            // 0x1353f0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135260u: goto label_135260;
            case 0x135290u: goto label_135290;
            case 0x1352C4u: goto label_1352c4;
            case 0x1352CCu: goto label_1352cc;
            case 0x135340u: goto label_135340;
            case 0x135360u: goto label_135360;
            case 0x135368u: goto label_135368;
            case 0x135370u: goto label_135370;
            case 0x135398u: goto label_135398;
            case 0x1353CCu: goto label_1353cc;
            case 0x1353D0u: goto label_1353d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1353F4u;
    // 0x1353f4: 0x0  nop
    ctx->pc = 0x1353f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
