#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001033F8
// Address: 0x1033f8 - 0x103530
void sub_001033F8_0x1033f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001033F8_0x1033f8");
#endif

    switch (ctx->pc) {
        case 0x10341cu: goto label_10341c;
        case 0x103428u: goto label_103428;
        case 0x103494u: goto label_103494;
        case 0x1034a0u: goto label_1034a0;
        case 0x1034fcu: goto label_1034fc;
        default: break;
    }

    ctx->pc = 0x1033f8u;

    // 0x1033f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1033f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1033fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1033fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103400: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x103400u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103404: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x103404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x103408: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x103408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x10340c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x10340cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103410: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x103410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x103414: 0xc040c00  jal         func_103000
    ctx->pc = 0x103414u;
    SET_GPR_U32(ctx, 31, 0x10341Cu);
    ctx->pc = 0x103418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103414u;
            // 0x103418: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103000u;
    if (runtime->hasFunction(0x103000u)) {
        auto targetFn = runtime->lookupFunction(0x103000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10341Cu; }
        if (ctx->pc != 0x10341Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103000_0x103000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10341Cu; }
        if (ctx->pc != 0x10341Cu) { return; }
    }
    ctx->pc = 0x10341Cu;
label_10341c:
    // 0x10341c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10341cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103420: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x103420u;
    SET_GPR_U32(ctx, 31, 0x103428u);
    ctx->pc = 0x103424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103420u;
            // 0x103424: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103428u; }
        if (ctx->pc != 0x103428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103428u; }
        if (ctx->pc != 0x103428u) { return; }
    }
    ctx->pc = 0x103428u;
label_103428:
    // 0x103428: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x103428u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10342c: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x10342cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x103430: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x103430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x103434: 0x54620001  bnel        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x103434u;
    {
        const bool branch_taken_0x103434 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x103434) {
            ctx->pc = 0x103438u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103434u;
            // 0x103438: 0xae110010  sw          $s1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10343Cu;
            goto label_10343c;
        }
    }
    ctx->pc = 0x10343Cu;
label_10343c:
    // 0x10343c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x10343cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103440: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x103440u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x103444: 0xae120020  sw          $s2, 0x20($s0)
    ctx->pc = 0x103444u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x103448: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x103448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10344c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x10344cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x103450: 0x34420101  ori         $v0, $v0, 0x101
    ctx->pc = 0x103450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)257);
    // 0x103454: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x103454u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x103458: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x103458u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x10345c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x10345cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103460: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103460u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103464: 0x3e00008  jr          $ra
    ctx->pc = 0x103464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103464u;
            // 0x103468: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10341Cu: goto label_10341c;
            case 0x103428u: goto label_103428;
            case 0x10343Cu: goto label_10343c;
            case 0x103494u: goto label_103494;
            case 0x1034A0u: goto label_1034a0;
            case 0x1034B4u: goto label_1034b4;
            case 0x1034FCu: goto label_1034fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10346Cu;
    // 0x10346c: 0x0  nop
    ctx->pc = 0x10346cu;
    // NOP
    // 0x103470: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x103470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x103474: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x103474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103478: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x103478u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10347c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10347cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x103480: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x103480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x103484: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x103484u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103488: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x103488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x10348c: 0xc040c00  jal         func_103000
    ctx->pc = 0x10348Cu;
    SET_GPR_U32(ctx, 31, 0x103494u);
    ctx->pc = 0x103490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10348Cu;
            // 0x103490: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103000u;
    if (runtime->hasFunction(0x103000u)) {
        auto targetFn = runtime->lookupFunction(0x103000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103494u; }
        if (ctx->pc != 0x103494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103000_0x103000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103494u; }
        if (ctx->pc != 0x103494u) { return; }
    }
    ctx->pc = 0x103494u;
label_103494:
    // 0x103494: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x103494u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103498: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x103498u;
    SET_GPR_U32(ctx, 31, 0x1034A0u);
    ctx->pc = 0x10349Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103498u;
            // 0x10349c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034A0u; }
        if (ctx->pc != 0x1034A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034A0u; }
        if (ctx->pc != 0x1034A0u) { return; }
    }
    ctx->pc = 0x1034A0u;
label_1034a0:
    // 0x1034a0: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1034a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1034a4: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1034a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1034a8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1034a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1034ac: 0x54620001  bnel        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x1034ACu;
    {
        const bool branch_taken_0x1034ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1034ac) {
            ctx->pc = 0x1034B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1034ACu;
            // 0x1034b0: 0xae110010  sw          $s1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1034B4u;
            goto label_1034b4;
        }
    }
    ctx->pc = 0x1034B4u;
label_1034b4:
    // 0x1034b4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1034b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1034b8: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x1034b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x1034bc: 0xae120020  sw          $s2, 0x20($s0)
    ctx->pc = 0x1034bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x1034c0: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1034c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1034c4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1034c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1034c8: 0x34420109  ori         $v0, $v0, 0x109
    ctx->pc = 0x1034c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)265);
    // 0x1034cc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1034ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1034d0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1034d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1034d4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1034d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1034d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1034d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1034dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1034DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1034E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1034DCu;
            // 0x1034e0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10341Cu: goto label_10341c;
            case 0x103428u: goto label_103428;
            case 0x10343Cu: goto label_10343c;
            case 0x103494u: goto label_103494;
            case 0x1034A0u: goto label_1034a0;
            case 0x1034B4u: goto label_1034b4;
            case 0x1034FCu: goto label_1034fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1034E4u;
    // 0x1034e4: 0x0  nop
    ctx->pc = 0x1034e4u;
    // NOP
    // 0x1034e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1034e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1034ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1034ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1034f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1034f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1034f4: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x1034F4u;
    SET_GPR_U32(ctx, 31, 0x1034FCu);
    ctx->pc = 0x1034F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1034F4u;
            // 0x1034f8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034FCu; }
        if (ctx->pc != 0x1034FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1034FCu; }
        if (ctx->pc != 0x1034FCu) { return; }
    }
    ctx->pc = 0x1034FCu;
label_1034fc:
    // 0x1034fc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1034fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103500: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x103500u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x103504: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x103504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x103508: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x103508u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x10350c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10350cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x103510: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x103510u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103514: 0x34420004  ori         $v0, $v0, 0x4
    ctx->pc = 0x103514u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4);
    // 0x103518: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x103518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x10351c: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x10351cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x103520: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x103520u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x103524: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103524u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103528: 0x3e00008  jr          $ra
    ctx->pc = 0x103528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10352Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103528u;
            // 0x10352c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10341Cu: goto label_10341c;
            case 0x103428u: goto label_103428;
            case 0x10343Cu: goto label_10343c;
            case 0x103494u: goto label_103494;
            case 0x1034A0u: goto label_1034a0;
            case 0x1034B4u: goto label_1034b4;
            case 0x1034FCu: goto label_1034fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
