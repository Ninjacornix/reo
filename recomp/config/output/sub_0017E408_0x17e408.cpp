#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E408
// Address: 0x17e408 - 0x17e4c8
void sub_0017E408_0x17e408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E408_0x17e408");
#endif

    switch (ctx->pc) {
        case 0x17e460u: goto label_17e460;
        case 0x17e474u: goto label_17e474;
        case 0x17e484u: goto label_17e484;
        case 0x17e498u: goto label_17e498;
        case 0x17e4a4u: goto label_17e4a4;
        case 0x17e4b4u: goto label_17e4b4;
        default: break;
    }

    ctx->pc = 0x17e408u;

    // 0x17e408: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x17e408u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x17e40c: 0x3e00008  jr          $ra
    ctx->pc = 0x17E40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E40Cu;
            // 0x17e410: 0x244214c8  addiu       $v0, $v0, 0x14C8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            case 0x17E460u: goto label_17e460;
            case 0x17E474u: goto label_17e474;
            case 0x17E484u: goto label_17e484;
            case 0x17E498u: goto label_17e498;
            case 0x17E4A4u: goto label_17e4a4;
            case 0x17E4B4u: goto label_17e4b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E414u;
    // 0x17e414: 0x0  nop
    ctx->pc = 0x17e414u;
    // NOP
    // 0x17e418: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17e418u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17e41c: 0x2442f978  addiu       $v0, $v0, -0x688
    ctx->pc = 0x17e41cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965624));
    // 0x17e420: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x17e420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17e424: 0x18600002  blez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17E424u;
    {
        const bool branch_taken_0x17e424 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x17E428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E424u;
            // 0x17e428: 0x2464ffff  addiu       $a0, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e424) {
            ctx->pc = 0x17E430u;
            goto label_17e430;
        }
    }
    ctx->pc = 0x17E42Cu;
    // 0x17e42c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x17e42cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
label_17e430:
    // 0x17e430: 0x3e00008  jr          $ra
    ctx->pc = 0x17E430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            case 0x17E460u: goto label_17e460;
            case 0x17E474u: goto label_17e474;
            case 0x17E484u: goto label_17e484;
            case 0x17E498u: goto label_17e498;
            case 0x17E4A4u: goto label_17e4a4;
            case 0x17E4B4u: goto label_17e4b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E438u;
    // 0x17e438: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17e438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17e43c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e43cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e440: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17e440u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17e444: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17e444u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e448: 0x24a51500  addiu       $a1, $a1, 0x1500
    ctx->pc = 0x17e448u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5376));
    // 0x17e44c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x17e44cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17e450: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17e450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e454: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17e454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17e458: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x17E458u;
    SET_GPR_U32(ctx, 31, 0x17E460u);
    ctx->pc = 0x17E45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E458u;
            // 0x17e45c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E460u; }
        if (ctx->pc != 0x17E460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E460u; }
        if (ctx->pc != 0x17E460u) { return; }
    }
    ctx->pc = 0x17E460u;
label_17e460:
    // 0x17e460: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e460u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e464: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17e464u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e468: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x17e468u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x17e46c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x17E46Cu;
    SET_GPR_U32(ctx, 31, 0x17E474u);
    ctx->pc = 0x17E470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E46Cu;
            // 0x17e470: 0x24a51510  addiu       $a1, $a1, 0x1510 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E474u; }
        if (ctx->pc != 0x17E474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E474u; }
        if (ctx->pc != 0x17E474u) { return; }
    }
    ctx->pc = 0x17E474u;
label_17e474:
    // 0x17e474: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e478: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17e478u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e47c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x17E47Cu;
    SET_GPR_U32(ctx, 31, 0x17E484u);
    ctx->pc = 0x17E480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E47Cu;
            // 0x17e480: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E484u; }
        if (ctx->pc != 0x17E484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E484u; }
        if (ctx->pc != 0x17E484u) { return; }
    }
    ctx->pc = 0x17E484u;
label_17e484:
    // 0x17e484: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e484u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e488: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x17e488u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17e48c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e48cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e490: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x17E490u;
    SET_GPR_U32(ctx, 31, 0x17E498u);
    ctx->pc = 0x17E494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E490u;
            // 0x17e494: 0x24a51518  addiu       $a1, $a1, 0x1518 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E498u; }
        if (ctx->pc != 0x17E498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E498u; }
        if (ctx->pc != 0x17E498u) { return; }
    }
    ctx->pc = 0x17E498u;
label_17e498:
    // 0x17e498: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e49c: 0xc05f932  jal         func_17E4C8
    ctx->pc = 0x17E49Cu;
    SET_GPR_U32(ctx, 31, 0x17E4A4u);
    ctx->pc = 0x17E4A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E49Cu;
            // 0x17e4a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E4C8u;
    if (runtime->hasFunction(0x17E4C8u)) {
        auto targetFn = runtime->lookupFunction(0x17E4C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4A4u; }
        if (ctx->pc != 0x17E4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E4C8_0x17e4c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4A4u; }
        if (ctx->pc != 0x17E4A4u) { return; }
    }
    ctx->pc = 0x17E4A4u;
label_17e4a4:
    // 0x17e4a4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17e4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17e4a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e4a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e4ac: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x17E4ACu;
    SET_GPR_U32(ctx, 31, 0x17E4B4u);
    ctx->pc = 0x17E4B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E4ACu;
            // 0x17e4b0: 0x24a51520  addiu       $a1, $a1, 0x1520 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4B4u; }
        if (ctx->pc != 0x17E4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E4B4u; }
        if (ctx->pc != 0x17E4B4u) { return; }
    }
    ctx->pc = 0x17E4B4u;
label_17e4b4:
    // 0x17e4b4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17e4b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e4b8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17e4b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e4bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17e4bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e4c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17E4C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E4C0u;
            // 0x17e4c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            case 0x17E460u: goto label_17e460;
            case 0x17E474u: goto label_17e474;
            case 0x17E484u: goto label_17e484;
            case 0x17E498u: goto label_17e498;
            case 0x17E4A4u: goto label_17e4a4;
            case 0x17E4B4u: goto label_17e4b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E4C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
