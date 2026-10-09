#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A22D0
// Address: 0x1a22d0 - 0x1a2490
void sub_001A22D0_0x1a22d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A22D0_0x1a22d0");
#endif

    switch (ctx->pc) {
        case 0x1a2318u: goto label_1a2318;
        case 0x1a232cu: goto label_1a232c;
        case 0x1a2354u: goto label_1a2354;
        case 0x1a237cu: goto label_1a237c;
        default: break;
    }

    ctx->pc = 0x1a22d0u;

    // 0x1a22d0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1a22d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1a22d4: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a22d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a22d8: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1a22d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1a22dc: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a22dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a22e0: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1a22e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1a22e4: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1a22e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1a22e8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a22e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a22ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a22ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a22f0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a22f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a22f4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a22f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a22f8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a22f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a22fc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1a22fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2300: 0x8cd40004  lw          $s4, 0x4($a2)
    ctx->pc = 0x1a2300u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1a2304: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1a2304u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2308: 0xa4b40002  sh          $s4, 0x2($a1)
    ctx->pc = 0x1a2308u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 20));
    // 0x1a230c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a230cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2310: 0xc06267c  jal         func_1899F0
    ctx->pc = 0x1A2310u;
    SET_GPR_U32(ctx, 31, 0x1A2318u);
    ctx->pc = 0x1A2314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2310u;
            // 0x1a2314: 0x1428c0  sll         $a1, $s4, 3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2318u; }
        if (ctx->pc != 0x1A2318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001899F0_0x1899f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2318u; }
        if (ctx->pc != 0x1A2318u) { return; }
    }
    ctx->pc = 0x1A2318u;
label_1a2318:
    // 0x1a2318: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x1a2318u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a231c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a231cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2320: 0xae160004  sw          $s6, 0x4($s0)
    ctx->pc = 0x1a2320u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 22));
    // 0x1a2324: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A2324u;
    {
        const bool branch_taken_0x1a2324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2324u;
            // 0x1a2328: 0x24040020  addiu       $a0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2324) {
            ctx->pc = 0x1A233Cu;
            goto label_1a233c;
        }
    }
    ctx->pc = 0x1A232Cu;
label_1a232c:
    // 0x1a232c: 0x2c31821  addu        $v1, $s6, $v1
    ctx->pc = 0x1a232cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x1a2330: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1a2330u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1a2334: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a2334u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a2338: 0xa4600002  sh          $zero, 0x2($v1)
    ctx->pc = 0x1a2338u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 0));
label_1a233c:
    // 0x1a233c: 0xb4182a  slt         $v1, $a1, $s4
    ctx->pc = 0x1a233cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1a2340: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A2340u;
    {
        const bool branch_taken_0x1a2340 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2340u;
            // 0x1a2344: 0x518c0  sll         $v1, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2340) {
            ctx->pc = 0x1A232Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a232c;
        }
    }
    ctx->pc = 0x1A2348u;
    // 0x1a2348: 0x2635000c  addiu       $s5, $s1, 0xC
    ctx->pc = 0x1a2348u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1a234c: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1A234Cu;
    {
        const bool branch_taken_0x1a234c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A234Cu;
            // 0x1a2350: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a234c) {
            ctx->pc = 0x1A2444u;
            goto label_1a2444;
        }
    }
    ctx->pc = 0x1A2354u;
label_1a2354:
    // 0x1a2354: 0x8eb30000  lw          $s3, 0x0($s5)
    ctx->pc = 0x1a2354u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1a2358: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a2358u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a235c: 0x2631824  and         $v1, $s3, $v1
    ctx->pc = 0x1a235cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & GPR_U64(ctx, 3));
    // 0x1a2360: 0x10600035  beqz        $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x1A2360u;
    {
        const bool branch_taken_0x1a2360 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2360) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A2368u;
    // 0x1a2368: 0x1110c0  sll         $v0, $s1, 3
    ctx->pc = 0x1a2368u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1a236c: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1a236cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2370: 0x2c29021  addu        $s2, $s6, $v0
    ctx->pc = 0x1a2370u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
    // 0x1a2374: 0xc068924  jal         func_1A2490
    ctx->pc = 0x1A2374u;
    SET_GPR_U32(ctx, 31, 0x1A237Cu);
    ctx->pc = 0x1A2378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2374u;
            // 0x1a2378: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2490u;
    if (runtime->hasFunction(0x1A2490u)) {
        auto targetFn = runtime->lookupFunction(0x1A2490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A237Cu; }
        if (ctx->pc != 0x1A237Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2490_0x1a2490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A237Cu; }
        if (ctx->pc != 0x1A237Cu) { return; }
    }
    ctx->pc = 0x1A237Cu;
label_1a237c:
    // 0x1a237c: 0x326401ff  andi        $a0, $s3, 0x1FF
    ctx->pc = 0x1a237cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)511);
    // 0x1a2380: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x1a2380u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1a2384: 0x1083002b  beq         $a0, $v1, . + 4 + (0x2B << 2)
    ctx->pc = 0x1A2384u;
    {
        const bool branch_taken_0x1a2384 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2384u;
            // 0x1a2388: 0x24030008  addiu       $v1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2384) {
            ctx->pc = 0x1A2434u;
            goto label_1a2434;
        }
    }
    ctx->pc = 0x1A238Cu;
    // 0x1a238c: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x1a238cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1a2390: 0x10830026  beq         $a0, $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x1A2390u;
    {
        const bool branch_taken_0x1a2390 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2390u;
            // 0x1a2394: 0x24030007  addiu       $v1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2390) {
            ctx->pc = 0x1A242Cu;
            goto label_1a242c;
        }
    }
    ctx->pc = 0x1A2398u;
    // 0x1a2398: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x1a2398u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1a239c: 0x10830021  beq         $a0, $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x1A239Cu;
    {
        const bool branch_taken_0x1a239c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A239Cu;
            // 0x1a23a0: 0x24030006  addiu       $v1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a239c) {
            ctx->pc = 0x1A2424u;
            goto label_1a2424;
        }
    }
    ctx->pc = 0x1A23A4u;
    // 0x1a23a4: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1a23a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a23a8: 0x1083001c  beq         $a0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1A23A8u;
    {
        const bool branch_taken_0x1a23a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23A8u;
            // 0x1a23ac: 0x24030005  addiu       $v1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23a8) {
            ctx->pc = 0x1A241Cu;
            goto label_1a241c;
        }
    }
    ctx->pc = 0x1A23B0u;
    // 0x1a23b0: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1a23b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a23b4: 0x10830017  beq         $a0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A23B4u;
    {
        const bool branch_taken_0x1a23b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23B4u;
            // 0x1a23b8: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23b4) {
            ctx->pc = 0x1A2414u;
            goto label_1a2414;
        }
    }
    ctx->pc = 0x1A23BCu;
    // 0x1a23bc: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1a23bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a23c0: 0x10830012  beq         $a0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1A23C0u;
    {
        const bool branch_taken_0x1a23c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23C0u;
            // 0x1a23c4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23c0) {
            ctx->pc = 0x1A240Cu;
            goto label_1a240c;
        }
    }
    ctx->pc = 0x1A23C8u;
    // 0x1a23c8: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1a23c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a23cc: 0x1083000d  beq         $a0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1A23CCu;
    {
        const bool branch_taken_0x1a23cc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23CCu;
            // 0x1a23d0: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23cc) {
            ctx->pc = 0x1A2404u;
            goto label_1a2404;
        }
    }
    ctx->pc = 0x1A23D4u;
    // 0x1a23d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a23d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a23d8: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A23D8u;
    {
        const bool branch_taken_0x1a23d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A23DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23D8u;
            // 0x1a23dc: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23d8) {
            ctx->pc = 0x1A23FCu;
            goto label_1a23fc;
        }
    }
    ctx->pc = 0x1A23E0u;
    // 0x1a23e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a23e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a23e4: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A23E4u;
    {
        const bool branch_taken_0x1a23e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a23e4) {
            ctx->pc = 0x1A23F4u;
            goto label_1a23f4;
        }
    }
    ctx->pc = 0x1A23ECu;
    // 0x1a23ec: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1A23ECu;
    {
        const bool branch_taken_0x1a23ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A23F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23ECu;
            // 0x1a23f0: 0x8ea30008  lw          $v1, 0x8($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23ec) {
            ctx->pc = 0x1A243Cu;
            goto label_1a243c;
        }
    }
    ctx->pc = 0x1A23F4u;
label_1a23f4:
    // 0x1a23f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1A23F4u;
    {
        const bool branch_taken_0x1a23f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A23F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23F4u;
            // 0x1a23f8: 0xa2400001  sb          $zero, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23f4) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A23FCu;
label_1a23fc:
    // 0x1a23fc: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A23FCu;
    {
        const bool branch_taken_0x1a23fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A23FCu;
            // 0x1a2400: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a23fc) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A2404u;
label_1a2404:
    // 0x1a2404: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A2404u;
    {
        const bool branch_taken_0x1a2404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2404u;
            // 0x1a2408: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2404) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A240Cu;
label_1a240c:
    // 0x1a240c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A240Cu;
    {
        const bool branch_taken_0x1a240c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A240Cu;
            // 0x1a2410: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a240c) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A2414u;
label_1a2414:
    // 0x1a2414: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A2414u;
    {
        const bool branch_taken_0x1a2414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2414u;
            // 0x1a2418: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2414) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A241Cu;
label_1a241c:
    // 0x1a241c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A241Cu;
    {
        const bool branch_taken_0x1a241c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A241Cu;
            // 0x1a2420: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a241c) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A2424u;
label_1a2424:
    // 0x1a2424: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A2424u;
    {
        const bool branch_taken_0x1a2424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2424u;
            // 0x1a2428: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2424) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A242Cu;
label_1a242c:
    // 0x1a242c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A242Cu;
    {
        const bool branch_taken_0x1a242c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A242Cu;
            // 0x1a2430: 0xa2430001  sb          $v1, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a242c) {
            ctx->pc = 0x1A2438u;
            goto label_1a2438;
        }
    }
    ctx->pc = 0x1A2434u;
label_1a2434:
    // 0x1a2434: 0xa2430001  sb          $v1, 0x1($s2)
    ctx->pc = 0x1a2434u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
label_1a2438:
    // 0x1a2438: 0x8ea30008  lw          $v1, 0x8($s5)
    ctx->pc = 0x1a2438u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
label_1a243c:
    // 0x1a243c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1a243cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1a2440: 0x2a3a821  addu        $s5, $s5, $v1
    ctx->pc = 0x1a2440u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
label_1a2444:
    // 0x1a2444: 0x234182a  slt         $v1, $s1, $s4
    ctx->pc = 0x1a2444u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1a2448: 0x1460ffc2  bnez        $v1, . + 4 + (-0x3E << 2)
    ctx->pc = 0x1A2448u;
    {
        const bool branch_taken_0x1a2448 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A244Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2448u;
            // 0x1a244c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2448) {
            ctx->pc = 0x1A2354u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2354;
        }
    }
    ctx->pc = 0x1A2450u;
    // 0x1a2450: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1a2450u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a2454: 0x8c23ffb0  lw          $v1, -0x50($at)
    ctx->pc = 0x1a2454u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a2458: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1a2458u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a245c: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1a245cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1a2460: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1a2460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a2464: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1a2464u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a2468: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1a2468u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a246c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a246cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a2470: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a2470u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a2474: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a2474u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2478: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a2478u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a247c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a247cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2480: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2480u;
            // 0x1a2484: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2318u: goto label_1a2318;
            case 0x1A232Cu: goto label_1a232c;
            case 0x1A233Cu: goto label_1a233c;
            case 0x1A2354u: goto label_1a2354;
            case 0x1A237Cu: goto label_1a237c;
            case 0x1A23F4u: goto label_1a23f4;
            case 0x1A23FCu: goto label_1a23fc;
            case 0x1A2404u: goto label_1a2404;
            case 0x1A240Cu: goto label_1a240c;
            case 0x1A2414u: goto label_1a2414;
            case 0x1A241Cu: goto label_1a241c;
            case 0x1A2424u: goto label_1a2424;
            case 0x1A242Cu: goto label_1a242c;
            case 0x1A2434u: goto label_1a2434;
            case 0x1A2438u: goto label_1a2438;
            case 0x1A243Cu: goto label_1a243c;
            case 0x1A2444u: goto label_1a2444;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2488u;
    // 0x1a2488: 0x0  nop
    ctx->pc = 0x1a2488u;
    // NOP
    // 0x1a248c: 0x0  nop
    ctx->pc = 0x1a248cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
