#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E490
// Address: 0x19e490 - 0x19e5d0
void sub_0019E490_0x19e490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E490_0x19e490");
#endif

    switch (ctx->pc) {
        case 0x19e504u: goto label_19e504;
        case 0x19e520u: goto label_19e520;
        case 0x19e534u: goto label_19e534;
        case 0x19e544u: goto label_19e544;
        case 0x19e574u: goto label_19e574;
        default: break;
    }

    ctx->pc = 0x19e490u;

    // 0x19e490: 0x27bddf30  addiu       $sp, $sp, -0x20D0
    ctx->pc = 0x19e490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294958896));
    // 0x19e494: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x19e494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19e498: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x19e498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x19e49c: 0x419c3  sra         $v1, $a0, 7
    ctx->pc = 0x19e49cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 7));
    // 0x19e4a0: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x19e4a0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x19e4a4: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x19e4a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x19e4a8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19e4a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19e4ac: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x19e4acu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e4b0: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19e4b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19e4b4: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x19e4b4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e4b8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19e4b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19e4bc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19e4bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19e4c0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19e4c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19e4c4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19e4c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19e4c8: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E4C8u;
    {
        const bool branch_taken_0x19e4c8 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x19E4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E4C8u;
            // 0x19e4cc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e4c8) {
            ctx->pc = 0x19E4D8u;
            goto label_19e4d8;
        }
    }
    ctx->pc = 0x19E4D0u;
    // 0x19e4d0: 0x2483007f  addiu       $v1, $a0, 0x7F
    ctx->pc = 0x19e4d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 127));
    // 0x19e4d4: 0x319c3  sra         $v1, $v1, 7
    ctx->pc = 0x19e4d4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 7));
label_19e4d8:
    // 0x19e4d8: 0x24720001  addiu       $s2, $v1, 0x1
    ctx->pc = 0x19e4d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19e4dc: 0x24a4ffff  addiu       $a0, $a1, -0x1
    ctx->pc = 0x19e4dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19e4e0: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E4E0u;
    {
        const bool branch_taken_0x19e4e0 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x19E4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E4E0u;
            // 0x19e4e4: 0x419c3  sra         $v1, $a0, 7 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e4e0) {
            ctx->pc = 0x19E4F0u;
            goto label_19e4f0;
        }
    }
    ctx->pc = 0x19E4E8u;
    // 0x19e4e8: 0x2483007f  addiu       $v1, $a0, 0x7F
    ctx->pc = 0x19e4e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 127));
    // 0x19e4ec: 0x319c3  sra         $v1, $v1, 7
    ctx->pc = 0x19e4ecu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 7));
label_19e4f0:
    // 0x19e4f0: 0x247e0001  addiu       $fp, $v1, 0x1
    ctx->pc = 0x19e4f0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19e4f4: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x19e4f4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e4f8: 0x121980  sll         $v1, $s2, 6
    ctx->pc = 0x19e4f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
    // 0x19e4fc: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x19E4FCu;
    {
        const bool branch_taken_0x19e4fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E4FCu;
            // 0x19e500: 0xafa300c0  sw          $v1, 0xC0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e4fc) {
            ctx->pc = 0x19E588u;
            goto label_19e588;
        }
    }
    ctx->pc = 0x19E504u;
label_19e504:
    // 0x19e504: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x19e504u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e508: 0x2432018  mult        $a0, $s2, $v1
    ctx->pc = 0x19e508u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x19e50c: 0x2c41821  addu        $v1, $s6, $a0
    ctx->pc = 0x19e50cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 4)));
    // 0x19e510: 0xafa300b0  sw          $v1, 0xB0($sp)
    ctx->pc = 0x19e510u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 3));
    // 0x19e514: 0x2e41821  addu        $v1, $s7, $a0
    ctx->pc = 0x19e514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 4)));
    // 0x19e518: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x19E518u;
    {
        const bool branch_taken_0x19e518 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E518u;
            // 0x19e51c: 0xafa300a0  sw          $v1, 0xA0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e518) {
            ctx->pc = 0x19E578u;
            goto label_19e578;
        }
    }
    ctx->pc = 0x19E520u;
label_19e520:
    // 0x19e520: 0x8fa200b0  lw          $v0, 0xB0($sp)
    ctx->pc = 0x19e520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x19e524: 0x141980  sll         $v1, $s4, 6
    ctx->pc = 0x19e524u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 6));
    // 0x19e528: 0x27b000d0  addiu       $s0, $sp, 0xD0
    ctx->pc = 0x19e528u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x19e52c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x19e52cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e530: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x19e530u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_19e534:
    // 0x19e534: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19e534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e538: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x19e538u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e53c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x19E53Cu;
    SET_GPR_U32(ctx, 31, 0x19E544u);
    ctx->pc = 0x19E540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E53Cu;
            // 0x19e540: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E544u; }
        if (ctx->pc != 0x19E544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E544u; }
        if (ctx->pc != 0x19E544u) { return; }
    }
    ctx->pc = 0x19E544u;
label_19e544:
    // 0x19e544: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x19e544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x19e548: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x19e548u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x19e54c: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x19e54cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x19e550: 0x2a620080  slti        $v0, $s3, 0x80
    ctx->pc = 0x19e550u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x19e554: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x19E554u;
    {
        const bool branch_taken_0x19e554 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E554u;
            // 0x19e558: 0x26100040  addiu       $s0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e554) {
            ctx->pc = 0x19E534u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e534;
        }
    }
    ctx->pc = 0x19E55Cu;
    // 0x19e55c: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x19e55cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x19e560: 0x141a00  sll         $v1, $s4, 8
    ctx->pc = 0x19e560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 8));
    // 0x19e564: 0x27a400d0  addiu       $a0, $sp, 0xD0
    ctx->pc = 0x19e564u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x19e568: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x19e568u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e56c: 0xc067974  jal         func_19E5D0
    ctx->pc = 0x19E56Cu;
    SET_GPR_U32(ctx, 31, 0x19E574u);
    ctx->pc = 0x19E570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E56Cu;
            // 0x19e570: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19E5D0u;
    if (runtime->hasFunction(0x19E5D0u)) {
        auto targetFn = runtime->lookupFunction(0x19E5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E574u; }
        if (ctx->pc != 0x19E574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E5D0_0x19e5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E574u; }
        if (ctx->pc != 0x19E574u) { return; }
    }
    ctx->pc = 0x19E574u;
label_19e574:
    // 0x19e574: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x19e574u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_19e578:
    // 0x19e578: 0x292182a  slt         $v1, $s4, $s2
    ctx->pc = 0x19e578u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x19e57c: 0x1460ffe8  bnez        $v1, . + 4 + (-0x18 << 2)
    ctx->pc = 0x19E57Cu;
    {
        const bool branch_taken_0x19e57c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e57c) {
            ctx->pc = 0x19E520u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e520;
        }
    }
    ctx->pc = 0x19E584u;
    // 0x19e584: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x19e584u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
label_19e588:
    // 0x19e588: 0x2be182a  slt         $v1, $s5, $fp
    ctx->pc = 0x19e588u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 30)) ? 1 : 0);
    // 0x19e58c: 0x1460ffdd  bnez        $v1, . + 4 + (-0x23 << 2)
    ctx->pc = 0x19E58Cu;
    {
        const bool branch_taken_0x19e58c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E58Cu;
            // 0x19e590: 0x151b40  sll         $v1, $s5, 13 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e58c) {
            ctx->pc = 0x19E504u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e504;
        }
    }
    ctx->pc = 0x19E594u;
    // 0x19e594: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x19e594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x19e598: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x19e598u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19e59c: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x19e59cu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19e5a0: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19e5a0u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19e5a4: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19e5a4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19e5a8: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19e5a8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19e5ac: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19e5acu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19e5b0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19e5b0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19e5b4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19e5b4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19e5b8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19e5b8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e5bc: 0x3e00008  jr          $ra
    ctx->pc = 0x19E5BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E5BCu;
            // 0x19e5c0: 0x27bd20d0  addiu       $sp, $sp, 0x20D0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8400));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E4D8u: goto label_19e4d8;
            case 0x19E4F0u: goto label_19e4f0;
            case 0x19E504u: goto label_19e504;
            case 0x19E520u: goto label_19e520;
            case 0x19E534u: goto label_19e534;
            case 0x19E544u: goto label_19e544;
            case 0x19E574u: goto label_19e574;
            case 0x19E578u: goto label_19e578;
            case 0x19E588u: goto label_19e588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E5C4u;
    // 0x19e5c4: 0x0  nop
    ctx->pc = 0x19e5c4u;
    // NOP
    // 0x19e5c8: 0x0  nop
    ctx->pc = 0x19e5c8u;
    // NOP
    // 0x19e5cc: 0x0  nop
    ctx->pc = 0x19e5ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
