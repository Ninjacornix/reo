#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E4B0
// Address: 0x16e4b0 - 0x16e668
void sub_0016E4B0_0x16e4b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E4B0_0x16e4b0");
#endif

    switch (ctx->pc) {
        case 0x16e5f0u: goto label_16e5f0;
        case 0x16e628u: goto label_16e628;
        case 0x16e658u: goto label_16e658;
        default: break;
    }

    ctx->pc = 0x16e4b0u;

    // 0x16e4b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16e4b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16e4b4: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x16e4b4u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e4b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16e4b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16e4bc: 0x8dac1b30  lw          $t4, 0x1B30($t5)
    ctx->pc = 0x16e4bcu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 6960)));
    // 0x16e4c0: 0x8ca70004  lw          $a3, 0x4($a1)
    ctx->pc = 0x16e4c0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x16e4c4: 0x258b0004  addiu       $t3, $t4, 0x4
    ctx->pc = 0x16e4c4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 12), 4));
    // 0x16e4c8: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x16e4c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x16e4cc: 0x8d620008  lw          $v0, 0x8($t3)
    ctx->pc = 0x16e4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x16e4d0: 0x8d63000c  lw          $v1, 0xC($t3)
    ctx->pc = 0x16e4d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x16e4d4: 0xc72818  mult        $a1, $a2, $a3
    ctx->pc = 0x16e4d4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x16e4d8: 0x8dae0038  lw          $t6, 0x38($t5)
    ctx->pc = 0x16e4d8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 56)));
    // 0x16e4dc: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x16e4dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16e4e0: 0x45102a  slt         $v0, $v0, $a1
    ctx->pc = 0x16e4e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x16e4e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16E4E4u;
    {
        const bool branch_taken_0x16e4e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E4E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E4E4u;
            // 0x16e4e8: 0x8d69001c  lw          $t1, 0x1C($t3) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e4e4) {
            ctx->pc = 0x16E500u;
            goto label_16e500;
        }
    }
    ctx->pc = 0x16E4ECu;
    // 0x16e4ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16e4ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16e4f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16e4f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e4f4: 0x34a50f17  ori         $a1, $a1, 0xF17
    ctx->pc = 0x16e4f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3863);
    // 0x16e4f8: 0x805a704  j           func_169C10
    ctx->pc = 0x16E4F8u;
    ctx->pc = 0x16E4FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E4F8u;
            // 0x16e4fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16E500u;
label_16e500:
    // 0x16e500: 0x24c5000f  addiu       $a1, $a2, 0xF
    ctx->pc = 0x16e500u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 15));
    // 0x16e504: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x16e504u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16e508: 0x28e20000  slti        $v0, $a3, 0x0
    ctx->pc = 0x16e508u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16e50c: 0x24e4000f  addiu       $a0, $a3, 0xF
    ctx->pc = 0x16e50cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 15));
    // 0x16e510: 0xa3300b  movn        $a2, $a1, $v1
    ctx->pc = 0x16e510u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 5));
    // 0x16e514: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x16e514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e518: 0x82380b  movn        $a3, $a0, $v0
    ctx->pc = 0x16e518u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 4));
    // 0x16e51c: 0x62903  sra         $a1, $a2, 4
    ctx->pc = 0x16e51cu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 4));
    // 0x16e520: 0x15c30005  bne         $t6, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x16E520u;
    {
        const bool branch_taken_0x16e520 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 3));
        ctx->pc = 0x16E524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E520u;
            // 0x16e524: 0x71103  sra         $v0, $a3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e520) {
            ctx->pc = 0x16E538u;
            goto label_16e538;
        }
    }
    ctx->pc = 0x16E528u;
    // 0x16e528: 0xa21018  mult        $v0, $a1, $v0
    ctx->pc = 0x16e528u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16e52c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16E52Cu;
    {
        const bool branch_taken_0x16e52c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E52Cu;
            // 0x16e530: 0x21280  sll         $v0, $v0, 10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e52c) {
            ctx->pc = 0x16E548u;
            goto label_16e548;
        }
    }
    ctx->pc = 0x16E534u;
    // 0x16e534: 0x0  nop
    ctx->pc = 0x16e534u;
    // NOP
label_16e538:
    // 0x16e538: 0xa21818  mult        $v1, $a1, $v0
    ctx->pc = 0x16e538u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x16e53c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x16e53cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x16e540: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16e540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16e544: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x16e544u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
label_16e548:
    // 0x16e548: 0x244a0040  addiu       $t2, $v0, 0x40
    ctx->pc = 0x16e548u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x16e54c: 0x8d630014  lw          $v1, 0x14($t3)
    ctx->pc = 0x16e54cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 20)));
    // 0x16e550: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x16e550u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e554: 0x8d620018  lw          $v0, 0x18($t3)
    ctx->pc = 0x16e554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 24)));
    // 0x16e558: 0x2467000f  addiu       $a3, $v1, 0xF
    ctx->pc = 0x16e558u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x16e55c: 0x28650000  slti        $a1, $v1, 0x0
    ctx->pc = 0x16e55cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16e560: 0x2446000f  addiu       $a2, $v0, 0xF
    ctx->pc = 0x16e560u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x16e564: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x16e564u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16e568: 0xe5180b  movn        $v1, $a3, $a1
    ctx->pc = 0x16e568u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x16e56c: 0xc4100b  movn        $v0, $a2, $a0
    ctx->pc = 0x16e56cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x16e570: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x16e570u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x16e574: 0x15c8000a  bne         $t6, $t0, . + 4 + (0xA << 2)
    ctx->pc = 0x16E574u;
    {
        const bool branch_taken_0x16e574 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 8));
        ctx->pc = 0x16E578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E574u;
            // 0x16e578: 0x21103  sra         $v0, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e574) {
            ctx->pc = 0x16E5A0u;
            goto label_16e5a0;
        }
    }
    ctx->pc = 0x16E57Cu;
    // 0x16e57c: 0x621018  mult        $v0, $v1, $v0
    ctx->pc = 0x16e57cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16e580: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16e580u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16e584: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x16e584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x16e588: 0x4a102b  sltu        $v0, $v0, $t2
    ctx->pc = 0x16e588u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 10)) ? 1 : 0);
    // 0x16e58c: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x16E58Cu;
    {
        const bool branch_taken_0x16e58c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e58c) {
            ctx->pc = 0x16E5C0u;
            goto label_16e5c0;
        }
    }
    ctx->pc = 0x16E594u;
    // 0x16e594: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x16E594u;
    {
        const bool branch_taken_0x16e594 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E594u;
            // 0x16e598: 0x8d620020  lw          $v0, 0x20($t3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e594) {
            ctx->pc = 0x16E5D8u;
            goto label_16e5d8;
        }
    }
    ctx->pc = 0x16E59Cu;
    // 0x16e59c: 0x0  nop
    ctx->pc = 0x16e59cu;
    // NOP
label_16e5a0:
    // 0x16e5a0: 0x621818  mult        $v1, $v1, $v0
    ctx->pc = 0x16e5a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x16e5a4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x16e5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x16e5a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16e5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16e5ac: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x16e5acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x16e5b0: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x16e5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x16e5b4: 0x4a102b  sltu        $v0, $v0, $t2
    ctx->pc = 0x16e5b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 10)) ? 1 : 0);
    // 0x16e5b8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16E5B8u;
    {
        const bool branch_taken_0x16e5b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e5b8) {
            ctx->pc = 0x16E5BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E5B8u;
            // 0x16e5bc: 0x8d620020  lw          $v0, 0x20($t3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E5D8u;
            goto label_16e5d8;
        }
    }
    ctx->pc = 0x16E5C0u;
label_16e5c0:
    // 0x16e5c0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16e5c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16e5c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16e5c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e5c8: 0x1a0202d  daddu       $a0, $t5, $zero
    ctx->pc = 0x16e5c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e5cc: 0x34a50f18  ori         $a1, $a1, 0xF18
    ctx->pc = 0x16e5ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3864);
    // 0x16e5d0: 0x805a704  j           func_169C10
    ctx->pc = 0x16E5D0u;
    ctx->pc = 0x16E5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E5D0u;
            // 0x16e5d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16E5D8u;
label_16e5d8:
    // 0x16e5d8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x16E5D8u;
    {
        const bool branch_taken_0x16e5d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e5d8) {
            ctx->pc = 0x16E618u;
            goto label_16e618;
        }
    }
    ctx->pc = 0x16E5E0u;
    // 0x16e5e0: 0x19200018  blez        $t1, . + 4 + (0x18 << 2)
    ctx->pc = 0x16E5E0u;
    {
        const bool branch_taken_0x16e5e0 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x16E5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E5E0u;
            // 0x16e5e4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e5e0) {
            ctx->pc = 0x16E644u;
            goto label_16e644;
        }
    }
    ctx->pc = 0x16E5E8u;
    // 0x16e5e8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16e5e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e5ec: 0x25830030  addiu       $v1, $t4, 0x30
    ctx->pc = 0x16e5ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 12), 48));
label_16e5f0:
    // 0x16e5f0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x16e5f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x16e5f4: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x16e5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x16e5f8: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x16e5f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x16e5fc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x16e5fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x16e600: 0x0  nop
    ctx->pc = 0x16e600u;
    // NOP
    // 0x16e604: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x16E604u;
    {
        const bool branch_taken_0x16e604 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E604u;
            // 0x16e608: 0x8a2021  addu        $a0, $a0, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e604) {
            ctx->pc = 0x16E5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16e5f0;
        }
    }
    ctx->pc = 0x16E60Cu;
    // 0x16e60c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x16E60Cu;
    {
        const bool branch_taken_0x16e60c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E60Cu;
            // 0x16e610: 0xad890138  sw          $t1, 0x138($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 312), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e60c) {
            ctx->pc = 0x16E648u;
            goto label_16e648;
        }
    }
    ctx->pc = 0x16E614u;
    // 0x16e614: 0x0  nop
    ctx->pc = 0x16e614u;
    // NOP
label_16e618:
    // 0x16e618: 0x5920000b  blezl       $t1, . + 4 + (0xB << 2)
    ctx->pc = 0x16E618u;
    {
        const bool branch_taken_0x16e618 = (GPR_S64(ctx, 9) <= 0);
        if (branch_taken_0x16e618) {
            ctx->pc = 0x16E61Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E618u;
            // 0x16e61c: 0xad890138  sw          $t1, 0x138($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 312), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E648u;
            goto label_16e648;
        }
    }
    ctx->pc = 0x16E620u;
    // 0x16e620: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x16e620u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e624: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x16e624u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
label_16e628:
    // 0x16e628: 0x0  nop
    ctx->pc = 0x16e628u;
    // NOP
    // 0x16e62c: 0x0  nop
    ctx->pc = 0x16e62cu;
    // NOP
    // 0x16e630: 0x0  nop
    ctx->pc = 0x16e630u;
    // NOP
    // 0x16e634: 0x0  nop
    ctx->pc = 0x16e634u;
    // NOP
    // 0x16e638: 0x0  nop
    ctx->pc = 0x16e638u;
    // NOP
    // 0x16e63c: 0x14a0fffa  bnez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x16E63Cu;
    {
        const bool branch_taken_0x16e63c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E63Cu;
            // 0x16e640: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e63c) {
            ctx->pc = 0x16E628u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16e628;
        }
    }
    ctx->pc = 0x16E644u;
label_16e644:
    // 0x16e644: 0xad890138  sw          $t1, 0x138($t4)
    ctx->pc = 0x16e644u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 312), GPR_U32(ctx, 9));
label_16e648:
    // 0x16e648: 0x25850030  addiu       $a1, $t4, 0x30
    ctx->pc = 0x16e648u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 12), 48));
    // 0x16e64c: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x16e64cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e650: 0xc05befc  jal         func_16FBF0
    ctx->pc = 0x16E650u;
    SET_GPR_U32(ctx, 31, 0x16E658u);
    ctx->pc = 0x16E654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E650u;
            // 0x16e654: 0x2584013c  addiu       $a0, $t4, 0x13C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 316));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FBF0u;
    if (runtime->hasFunction(0x16FBF0u)) {
        auto targetFn = runtime->lookupFunction(0x16FBF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E658u; }
        if (ctx->pc != 0x16E658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FBF0_0x16fbf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E658u; }
        if (ctx->pc != 0x16E658u) { return; }
    }
    ctx->pc = 0x16E658u;
label_16e658:
    // 0x16e658: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16e658u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e65c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16e65cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e660: 0x3e00008  jr          $ra
    ctx->pc = 0x16E660u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E660u;
            // 0x16e664: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E500u: goto label_16e500;
            case 0x16E538u: goto label_16e538;
            case 0x16E548u: goto label_16e548;
            case 0x16E5A0u: goto label_16e5a0;
            case 0x16E5C0u: goto label_16e5c0;
            case 0x16E5D8u: goto label_16e5d8;
            case 0x16E5F0u: goto label_16e5f0;
            case 0x16E618u: goto label_16e618;
            case 0x16E628u: goto label_16e628;
            case 0x16E644u: goto label_16e644;
            case 0x16E648u: goto label_16e648;
            case 0x16E658u: goto label_16e658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E668u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
