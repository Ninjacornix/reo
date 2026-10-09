#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182688
// Address: 0x182688 - 0x182820
void sub_00182688_0x182688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182688_0x182688");
#endif

    switch (ctx->pc) {
        case 0x1826bcu: goto label_1826bc;
        case 0x1826e4u: goto label_1826e4;
        case 0x182710u: goto label_182710;
        case 0x182724u: goto label_182724;
        case 0x182740u: goto label_182740;
        case 0x182748u: goto label_182748;
        case 0x18275cu: goto label_18275c;
        case 0x182770u: goto label_182770;
        case 0x182784u: goto label_182784;
        case 0x1827a8u: goto label_1827a8;
        case 0x1827b4u: goto label_1827b4;
        case 0x1827c8u: goto label_1827c8;
        case 0x1827e0u: goto label_1827e0;
        case 0x1827f0u: goto label_1827f0;
        default: break;
    }

    ctx->pc = 0x182688u;

    // 0x182688: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x182688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18268c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x18268cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182690: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x182690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182694: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x182694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x182698: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x182698u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18269c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18269cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1826a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1826a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1826a4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1826a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1826a8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1826a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1826ac: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1826acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1826b0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1826b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1826b4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1826B4u;
    SET_GPR_U32(ctx, 31, 0x1826BCu);
    ctx->pc = 0x1826B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1826B4u;
            // 0x1826b8: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1826BCu; }
        if (ctx->pc != 0x1826BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1826BCu; }
        if (ctx->pc != 0x1826BCu) { return; }
    }
    ctx->pc = 0x1826BCu;
label_1826bc:
    // 0x1826bc: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x1826bcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1826c0: 0x1060004d  beqz        $v1, . + 4 + (0x4D << 2)
    ctx->pc = 0x1826C0u;
    {
        const bool branch_taken_0x1826c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1826C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1826C0u;
            // 0x1826c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1826c0) {
            ctx->pc = 0x1827F8u;
            goto label_1827f8;
        }
    }
    ctx->pc = 0x1826C8u;
    // 0x1826c8: 0x24050898  addiu       $a1, $zero, 0x898
    ctx->pc = 0x1826c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x1826cc: 0x2452818  mult        $a1, $s2, $a1
    ctx->pc = 0x1826ccu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1826d0: 0x3c010028  lui         $at, 0x28
    ctx->pc = 0x1826d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)40 << 16));
    // 0x1826d4: 0x24216350  addiu       $at, $at, 0x6350
    ctx->pc = 0x1826d4u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 25424));
    // 0x1826d8: 0x252821  addu        $a1, $at, $a1
    ctx->pc = 0x1826d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x1826dc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1826DCu;
    SET_GPR_U32(ctx, 31, 0x1826E4u);
    ctx->pc = 0x1826E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1826DCu;
            // 0x1826e0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1826E4u; }
        if (ctx->pc != 0x1826E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1826E4u; }
        if (ctx->pc != 0x1826E4u) { return; }
    }
    ctx->pc = 0x1826E4u;
label_1826e4:
    // 0x1826e4: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1826e4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1826e8: 0x2402002f  addiu       $v0, $zero, 0x2F
    ctx->pc = 0x1826e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1826ec: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1826ECu;
    {
        const bool branch_taken_0x1826ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1826F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1826ECu;
            // 0x1826f0: 0x3c130024  lui         $s3, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1826ec) {
            ctx->pc = 0x182718u;
            goto label_182718;
        }
    }
    ctx->pc = 0x1826F4u;
    // 0x1826f4: 0x26040001  addiu       $a0, $s0, 0x1
    ctx->pc = 0x1826f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1826f8: 0x266517c8  addiu       $a1, $s3, 0x17C8
    ctx->pc = 0x1826f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 6088));
    // 0x1826fc: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x1826fcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x182700: 0x80a30001  lb          $v1, 0x1($a1)
    ctx->pc = 0x182700u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x182704: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x182704u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x182708: 0xc060948  jal         func_182520
    ctx->pc = 0x182708u;
    SET_GPR_U32(ctx, 31, 0x182710u);
    ctx->pc = 0x18270Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182708u;
            // 0x18270c: 0xa2230001  sb          $v1, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182520u;
    if (runtime->hasFunction(0x182520u)) {
        auto targetFn = runtime->lookupFunction(0x182520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182710u; }
        if (ctx->pc != 0x182710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182520_0x182520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182710u; }
        if (ctx->pc != 0x182710u) { return; }
    }
    ctx->pc = 0x182710u;
label_182710:
    // 0x182710: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x182710u;
    {
        const bool branch_taken_0x182710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182710u;
            // 0x182714: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182710) {
            ctx->pc = 0x182728u;
            goto label_182728;
        }
    }
    ctx->pc = 0x182718u;
label_182718:
    // 0x182718: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x182718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18271c: 0xc060948  jal         func_182520
    ctx->pc = 0x18271Cu;
    SET_GPR_U32(ctx, 31, 0x182724u);
    ctx->pc = 0x182720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18271Cu;
            // 0x182720: 0x266517c8  addiu       $a1, $s3, 0x17C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 6088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182520u;
    if (runtime->hasFunction(0x182520u)) {
        auto targetFn = runtime->lookupFunction(0x182520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182724u; }
        if (ctx->pc != 0x182724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182520_0x182520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182724u; }
        if (ctx->pc != 0x182724u) { return; }
    }
    ctx->pc = 0x182724u;
label_182724:
    // 0x182724: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x182724u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_182728:
    // 0x182728: 0x1200002a  beqz        $s0, . + 4 + (0x2A << 2)
    ctx->pc = 0x182728u;
    {
        const bool branch_taken_0x182728 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x18272Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182728u;
            // 0x18272c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182728) {
            ctx->pc = 0x1827D4u;
            goto label_1827d4;
        }
    }
    ctx->pc = 0x182730u;
    // 0x182730: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x182730u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x182734: 0x245217c8  addiu       $s2, $v0, 0x17C8
    ctx->pc = 0x182734u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 6088));
    // 0x182738: 0x3c140024  lui         $s4, 0x24
    ctx->pc = 0x182738u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)36 << 16));
    // 0x18273c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18273cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_182740:
    // 0x182740: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x182740u;
    SET_GPR_U32(ctx, 31, 0x182748u);
    ctx->pc = 0x182744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182740u;
            // 0x182744: 0x26a517b0  addiu       $a1, $s5, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182748u; }
        if (ctx->pc != 0x182748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182748u; }
        if (ctx->pc != 0x182748u) { return; }
    }
    ctx->pc = 0x182748u;
label_182748:
    // 0x182748: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182748u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18274c: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x18274Cu;
    {
        const bool branch_taken_0x18274c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18274Cu;
            // 0x182750: 0x268517b8  addiu       $a1, $s4, 0x17B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 6072));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18274c) {
            ctx->pc = 0x1827B8u;
            goto label_1827b8;
        }
    }
    ctx->pc = 0x182754u;
    // 0x182754: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x182754u;
    SET_GPR_U32(ctx, 31, 0x18275Cu);
    ctx->pc = 0x182758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182754u;
            // 0x182758: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18275Cu; }
        if (ctx->pc != 0x18275Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18275Cu; }
        if (ctx->pc != 0x18275Cu) { return; }
    }
    ctx->pc = 0x18275Cu;
label_18275c:
    // 0x18275c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18275cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182760: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x182760u;
    {
        const bool branch_taken_0x182760 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182760u;
            // 0x182764: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182760) {
            ctx->pc = 0x1827A0u;
            goto label_1827a0;
        }
    }
    ctx->pc = 0x182768u;
    // 0x182768: 0xc042c56  jal         func_10B158
    ctx->pc = 0x182768u;
    SET_GPR_U32(ctx, 31, 0x182770u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182770u; }
        if (ctx->pc != 0x182770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182770u; }
        if (ctx->pc != 0x182770u) { return; }
    }
    ctx->pc = 0x182770u;
label_182770:
    // 0x182770: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x182770u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182774: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x182774u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x182778: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x182778u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x18277c: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x18277Cu;
    SET_GPR_U32(ctx, 31, 0x182784u);
    ctx->pc = 0x182780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18277Cu;
            // 0x182780: 0xa040ffff  sb          $zero, -0x1($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 4294967295), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182784u; }
        if (ctx->pc != 0x182784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182784u; }
        if (ctx->pc != 0x182784u) { return; }
    }
    ctx->pc = 0x182784u;
label_182784:
    // 0x182784: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182784u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182788: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x182788u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18278c: 0x1060001a  beqz        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x18278Cu;
    {
        const bool branch_taken_0x18278c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x182790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18278Cu;
            // 0x182790: 0x266517c8  addiu       $a1, $s3, 0x17C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 6088));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18278c) {
            ctx->pc = 0x1827F8u;
            goto label_1827f8;
        }
    }
    ctx->pc = 0x182794u;
    // 0x182794: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x182794u;
    {
        const bool branch_taken_0x182794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182794u;
            // 0x182798: 0xa0600001  sb          $zero, 0x1($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182794) {
            ctx->pc = 0x1827C0u;
            goto label_1827c0;
        }
    }
    ctx->pc = 0x18279Cu;
    // 0x18279c: 0x0  nop
    ctx->pc = 0x18279cu;
    // NOP
label_1827a0:
    // 0x1827a0: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1827A0u;
    SET_GPR_U32(ctx, 31, 0x1827A8u);
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827A8u; }
        if (ctx->pc != 0x1827A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827A8u; }
        if (ctx->pc != 0x1827A8u) { return; }
    }
    ctx->pc = 0x1827A8u;
label_1827a8:
    // 0x1827a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1827a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1827ac: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1827ACu;
    SET_GPR_U32(ctx, 31, 0x1827B4u);
    ctx->pc = 0x1827B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1827ACu;
            // 0x1827b0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827B4u; }
        if (ctx->pc != 0x1827B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827B4u; }
        if (ctx->pc != 0x1827B4u) { return; }
    }
    ctx->pc = 0x1827B4u;
label_1827b4:
    // 0x1827b4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1827b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1827b8:
    // 0x1827b8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1827b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1827bc: 0x24a517c8  addiu       $a1, $a1, 0x17C8
    ctx->pc = 0x1827bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6088));
label_1827c0:
    // 0x1827c0: 0xc060948  jal         func_182520
    ctx->pc = 0x1827C0u;
    SET_GPR_U32(ctx, 31, 0x1827C8u);
    ctx->pc = 0x182520u;
    if (runtime->hasFunction(0x182520u)) {
        auto targetFn = runtime->lookupFunction(0x182520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827C8u; }
        if (ctx->pc != 0x1827C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182520_0x182520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827C8u; }
        if (ctx->pc != 0x1827C8u) { return; }
    }
    ctx->pc = 0x1827C8u;
label_1827c8:
    // 0x1827c8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1827c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1827cc: 0x5600ffdc  bnel        $s0, $zero, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1827CCu;
    {
        const bool branch_taken_0x1827cc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1827cc) {
            ctx->pc = 0x1827D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1827CCu;
            // 0x1827d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182740u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182740;
        }
    }
    ctx->pc = 0x1827D4u;
label_1827d4:
    // 0x1827d4: 0x266517c8  addiu       $a1, $s3, 0x17C8
    ctx->pc = 0x1827d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 6088));
    // 0x1827d8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1827D8u;
    SET_GPR_U32(ctx, 31, 0x1827E0u);
    ctx->pc = 0x1827DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1827D8u;
            // 0x1827dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827E0u; }
        if (ctx->pc != 0x1827E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827E0u; }
        if (ctx->pc != 0x1827E0u) { return; }
    }
    ctx->pc = 0x1827E0u;
label_1827e0:
    // 0x1827e0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1827E0u;
    {
        const bool branch_taken_0x1827e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1827E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1827E0u;
            // 0x1827e4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1827e0) {
            ctx->pc = 0x1827F4u;
            goto label_1827f4;
        }
    }
    ctx->pc = 0x1827E8u;
    // 0x1827e8: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1827E8u;
    SET_GPR_U32(ctx, 31, 0x1827F0u);
    ctx->pc = 0x1827ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1827E8u;
            // 0x1827ec: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827F0u; }
        if (ctx->pc != 0x1827F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1827F0u; }
        if (ctx->pc != 0x1827F0u) { return; }
    }
    ctx->pc = 0x1827F0u;
label_1827f0:
    // 0x1827f0: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1827f0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1827f4:
    // 0x1827f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1827f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1827f8:
    // 0x1827f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1827f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1827fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1827fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182800: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x182800u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182804: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x182804u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182808: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x182808u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18280c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x18280cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182810: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x182810u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x182814: 0x3e00008  jr          $ra
    ctx->pc = 0x182814u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182814u;
            // 0x182818: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1826BCu: goto label_1826bc;
            case 0x1826E4u: goto label_1826e4;
            case 0x182710u: goto label_182710;
            case 0x182718u: goto label_182718;
            case 0x182724u: goto label_182724;
            case 0x182728u: goto label_182728;
            case 0x182740u: goto label_182740;
            case 0x182748u: goto label_182748;
            case 0x18275Cu: goto label_18275c;
            case 0x182770u: goto label_182770;
            case 0x182784u: goto label_182784;
            case 0x1827A0u: goto label_1827a0;
            case 0x1827A8u: goto label_1827a8;
            case 0x1827B4u: goto label_1827b4;
            case 0x1827B8u: goto label_1827b8;
            case 0x1827C0u: goto label_1827c0;
            case 0x1827C8u: goto label_1827c8;
            case 0x1827D4u: goto label_1827d4;
            case 0x1827E0u: goto label_1827e0;
            case 0x1827F0u: goto label_1827f0;
            case 0x1827F4u: goto label_1827f4;
            case 0x1827F8u: goto label_1827f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18281Cu;
    // 0x18281c: 0x0  nop
    ctx->pc = 0x18281cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
