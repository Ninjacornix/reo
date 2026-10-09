#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197490
// Address: 0x197490 - 0x197780
void sub_00197490_0x197490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197490_0x197490");
#endif

    switch (ctx->pc) {
        case 0x197524u: goto label_197524;
        case 0x197538u: goto label_197538;
        case 0x197750u: goto label_197750;
        default: break;
    }

    ctx->pc = 0x197490u;

    // 0x197490: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x197490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x197494: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x197494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x197498: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x197498u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19749c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19749cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1974a0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1974a0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1974a4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1974a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1974a8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1974a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1974ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1974acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1974b0: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1974b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1974b4: 0x6810002  bgez        $s4, . + 4 + (0x2 << 2)
    ctx->pc = 0x1974B4u;
    {
        const bool branch_taken_0x1974b4 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x1974B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1974B4u;
            // 0x1974b8: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1974b4) {
            ctx->pc = 0x1974C0u;
            goto label_1974c0;
        }
    }
    ctx->pc = 0x1974BCu;
    // 0x1974bc: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1974bcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1974c0:
    // 0x1974c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1974c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1974c4: 0x2861021  addu        $v0, $s4, $a2
    ctx->pc = 0x1974c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
    // 0x1974c8: 0x8c23fed8  lw          $v1, -0x128($at)
    ctx->pc = 0x1974c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1974cc: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1974ccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1974d0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1974D0u;
    {
        const bool branch_taken_0x1974d0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1974D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1974D0u;
            // 0x1974d4: 0x2861021  addu        $v0, $s4, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1974d0) {
            ctx->pc = 0x1974E0u;
            goto label_1974e0;
        }
    }
    ctx->pc = 0x1974D8u;
    // 0x1974d8: 0x743023  subu        $a2, $v1, $s4
    ctx->pc = 0x1974d8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x1974dc: 0x2861021  addu        $v0, $s4, $a2
    ctx->pc = 0x1974dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
label_1974e0:
    // 0x1974e0: 0x6610002  bgez        $s3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1974E0u;
    {
        const bool branch_taken_0x1974e0 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x1974E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1974E0u;
            // 0x1974e4: 0x2451ffff  addiu       $s1, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1974e0) {
            ctx->pc = 0x1974ECu;
            goto label_1974ec;
        }
    }
    ctx->pc = 0x1974E8u;
    // 0x1974e8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1974e8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1974ec:
    // 0x1974ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1974ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1974f0: 0x2671021  addu        $v0, $s3, $a3
    ctx->pc = 0x1974f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 7)));
    // 0x1974f4: 0x8c23fed0  lw          $v1, -0x130($at)
    ctx->pc = 0x1974f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966992)));
    // 0x1974f8: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1974f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1974fc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1974FCu;
    {
        const bool branch_taken_0x1974fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1974fc) {
            ctx->pc = 0x197508u;
            goto label_197508;
        }
    }
    ctx->pc = 0x197504u;
    // 0x197504: 0x733823  subu        $a3, $v1, $s3
    ctx->pc = 0x197504u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
label_197508:
    // 0x197508: 0x2671821  addu        $v1, $s3, $a3
    ctx->pc = 0x197508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 7)));
    // 0x19750c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x19750cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197510: 0x12420006  beq         $s2, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x197510u;
    {
        const bool branch_taken_0x197510 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        ctx->pc = 0x197514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197510u;
            // 0x197514: 0x2470ffff  addiu       $s0, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197510) {
            ctx->pc = 0x19752Cu;
            goto label_19752c;
        }
    }
    ctx->pc = 0x197518u;
    // 0x197518: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x197518u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x19751c: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19751Cu;
    SET_GPR_U32(ctx, 31, 0x197524u);
    ctx->pc = 0x197520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19751Cu;
            // 0x197520: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197524u; }
        if (ctx->pc != 0x197524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197524u; }
        if (ctx->pc != 0x197524u) { return; }
    }
    ctx->pc = 0x197524u;
label_197524:
    // 0x197524: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197524u;
    {
        const bool branch_taken_0x197524 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197524u;
            // 0x197528: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197524) {
            ctx->pc = 0x19753Cu;
            goto label_19753c;
        }
    }
    ctx->pc = 0x19752Cu;
label_19752c:
    // 0x19752c: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x19752cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197530: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x197530u;
    SET_GPR_U32(ctx, 31, 0x197538u);
    ctx->pc = 0x197534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197530u;
            // 0x197534: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197538u; }
        if (ctx->pc != 0x197538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197538u; }
        if (ctx->pc != 0x197538u) { return; }
    }
    ctx->pc = 0x197538u;
label_197538:
    // 0x197538: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x197538u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_19753c:
    // 0x19753c: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x19753cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x197540: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x197540u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x197544: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x197544u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197548: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x197548u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19754c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x19754cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x197550: 0x4303c  dsll32      $a2, $a0, 0
    ctx->pc = 0x197550u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197554: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x197554u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x197558: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x197558u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x19755c: 0xe32025  or          $a0, $a3, $v1
    ctx->pc = 0x19755cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x197560: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x197560u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197564: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x197564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197568: 0xac450008  sw          $a1, 0x8($v0)
    ctx->pc = 0x197568u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x19756c: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x19756cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197570: 0xac44000c  sw          $a0, 0xC($v0)
    ctx->pc = 0x197570u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197574: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x197574u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x197578: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x197578u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x19757c: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x19757cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197580: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x197580u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197584: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x197584u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x197588: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x197588u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x19758c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x19758cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x197590: 0xfc450010  sd          $a1, 0x10($v0)
    ctx->pc = 0x197590u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 5));
    // 0x197594: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x197594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197598: 0x1243003e  beq         $s2, $v1, . + 4 + (0x3E << 2)
    ctx->pc = 0x197598u;
    {
        const bool branch_taken_0x197598 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 3));
        ctx->pc = 0x19759Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197598u;
            // 0x19759c: 0xfc440018  sd          $a0, 0x18($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197598) {
            ctx->pc = 0x197694u;
            goto label_197694;
        }
    }
    ctx->pc = 0x1975A0u;
    // 0x1975a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1975a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1975a4: 0x12430020  beq         $s2, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1975A4u;
    {
        const bool branch_taken_0x1975a4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 3));
        ctx->pc = 0x1975A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1975A4u;
            // 0x1975a8: 0x13183c  dsll32      $v1, $s3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1975a4) {
            ctx->pc = 0x197628u;
            goto label_197628;
        }
    }
    ctx->pc = 0x1975ACu;
    // 0x1975ac: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1975ACu;
    {
        const bool branch_taken_0x1975ac = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1975B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1975ACu;
            // 0x1975b0: 0x13183c  dsll32      $v1, $s3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1975ac) {
            ctx->pc = 0x1975BCu;
            goto label_1975bc;
        }
    }
    ctx->pc = 0x1975B4u;
    // 0x1975b4: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1975B4u;
    {
        const bool branch_taken_0x1975b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1975B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1975B4u;
            // 0x1975b8: 0x2293c  dsll32      $a1, $v0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1975b4) {
            ctx->pc = 0x197738u;
            goto label_197738;
        }
    }
    ctx->pc = 0x1975BCu;
label_1975bc:
    // 0x1975bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1975bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1975c0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1975c0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1975c4: 0xac34fdf8  sw          $s4, -0x208($at)
    ctx->pc = 0x1975c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966776), GPR_U32(ctx, 20));
    // 0x1975c8: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x1975c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1975cc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1975ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1975d0: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x1975d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x1975d4: 0xac33fdfc  sw          $s3, -0x204($at)
    ctx->pc = 0x1975d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966780), GPR_U32(ctx, 19));
    // 0x1975d8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1975d8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1975dc: 0x14303c  dsll32      $a2, $s4, 0
    ctx->pc = 0x1975dcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1975e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1975e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1975e4: 0x32438  dsll        $a0, $v1, 16
    ctx->pc = 0x1975e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 16);
    // 0x1975e8: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x1975e8u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1975ec: 0xac31fe00  sw          $s1, -0x200($at)
    ctx->pc = 0x1975ecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966784), GPR_U32(ctx, 17));
    // 0x1975f0: 0x10183c  dsll32      $v1, $s0, 0
    ctx->pc = 0x1975f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
    // 0x1975f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1975f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1975f8: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x1975f8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1975fc: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1975fcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x197600: 0xac30fe04  sw          $s0, -0x1FC($at)
    ctx->pc = 0x197600u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966788), GPR_U32(ctx, 16));
    // 0x197604: 0x3243c  dsll32      $a0, $v1, 16
    ctx->pc = 0x197604u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 16));
    // 0x197608: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x197608u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x19760c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19760cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197610: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x197610u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x197614: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x197614u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197618: 0xfc24fdf0  sd          $a0, -0x210($at)
    ctx->pc = 0x197618u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966768), GPR_U64(ctx, 4));
    // 0x19761c: 0xfc440020  sd          $a0, 0x20($v0)
    ctx->pc = 0x19761cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 4));
    // 0x197620: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x197620u;
    {
        const bool branch_taken_0x197620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197620u;
            // 0x197624: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197620) {
            ctx->pc = 0x197734u;
            goto label_197734;
        }
    }
    ctx->pc = 0x197628u;
label_197628:
    // 0x197628: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19762c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x19762cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x197630: 0xac34fe10  sw          $s4, -0x1F0($at)
    ctx->pc = 0x197630u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966800), GPR_U32(ctx, 20));
    // 0x197634: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x197634u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197638: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19763c: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x19763cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x197640: 0xac33fe14  sw          $s3, -0x1EC($at)
    ctx->pc = 0x197640u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966804), GPR_U32(ctx, 19));
    // 0x197644: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x197644u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x197648: 0x14303c  dsll32      $a2, $s4, 0
    ctx->pc = 0x197648u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) << (32 + 0));
    // 0x19764c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19764cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197650: 0x32438  dsll        $a0, $v1, 16
    ctx->pc = 0x197650u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 16);
    // 0x197654: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x197654u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x197658: 0xac31fe18  sw          $s1, -0x1E8($at)
    ctx->pc = 0x197658u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966808), GPR_U32(ctx, 17));
    // 0x19765c: 0x10183c  dsll32      $v1, $s0, 0
    ctx->pc = 0x19765cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
    // 0x197660: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197660u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197664: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x197664u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x197668: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x197668u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x19766c: 0xac30fe1c  sw          $s0, -0x1E4($at)
    ctx->pc = 0x19766cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966812), GPR_U32(ctx, 16));
    // 0x197670: 0x3243c  dsll32      $a0, $v1, 16
    ctx->pc = 0x197670u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 16));
    // 0x197674: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x197674u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x197678: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197678u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19767c: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x19767cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x197680: 0x24030041  addiu       $v1, $zero, 0x41
    ctx->pc = 0x197680u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x197684: 0xfc24fe08  sd          $a0, -0x1F8($at)
    ctx->pc = 0x197684u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966792), GPR_U64(ctx, 4));
    // 0x197688: 0xfc440020  sd          $a0, 0x20($v0)
    ctx->pc = 0x197688u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 4));
    // 0x19768c: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x19768Cu;
    {
        const bool branch_taken_0x19768c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19768Cu;
            // 0x197690: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19768c) {
            ctx->pc = 0x197734u;
            goto label_197734;
        }
    }
    ctx->pc = 0x197694u;
label_197694:
    // 0x197694: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197698: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x197698u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x19769c: 0xac34fdf8  sw          $s4, -0x208($at)
    ctx->pc = 0x19769cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966776), GPR_U32(ctx, 20));
    // 0x1976a0: 0x14203c  dsll32      $a0, $s4, 0
    ctx->pc = 0x1976a0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1976a4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976a8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1976a8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1976ac: 0xac34fe10  sw          $s4, -0x1F0($at)
    ctx->pc = 0x1976acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966800), GPR_U32(ctx, 20));
    // 0x1976b0: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1976b0u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1976b4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976b8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1976b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1976bc: 0xac33fdfc  sw          $s3, -0x204($at)
    ctx->pc = 0x1976bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966780), GPR_U32(ctx, 19));
    // 0x1976c0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1976c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1976c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976c8: 0x13183c  dsll32      $v1, $s3, 0
    ctx->pc = 0x1976c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) << (32 + 0));
    // 0x1976cc: 0xac31fe00  sw          $s1, -0x200($at)
    ctx->pc = 0x1976ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966784), GPR_U32(ctx, 17));
    // 0x1976d0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1976d0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1976d4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976d8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1976d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1976dc: 0xac31fe18  sw          $s1, -0x1E8($at)
    ctx->pc = 0x1976dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966808), GPR_U32(ctx, 17));
    // 0x1976e0: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1976e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1976e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976e8: 0x10183c  dsll32      $v1, $s0, 0
    ctx->pc = 0x1976e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
    // 0x1976ec: 0xac33fe14  sw          $s3, -0x1EC($at)
    ctx->pc = 0x1976ecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966804), GPR_U32(ctx, 19));
    // 0x1976f0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1976f0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1976f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1976f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1976f8: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1976f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1976fc: 0xac30fe04  sw          $s0, -0x1FC($at)
    ctx->pc = 0x1976fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966788), GPR_U32(ctx, 16));
    // 0x197700: 0x652825  or          $a1, $v1, $a1
    ctx->pc = 0x197700u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x197704: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197704u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197708: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x197708u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x19770c: 0xac30fe1c  sw          $s0, -0x1E4($at)
    ctx->pc = 0x19770cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966812), GPR_U32(ctx, 16));
    // 0x197710: 0x24030041  addiu       $v1, $zero, 0x41
    ctx->pc = 0x197710u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x197714: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197714u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197718: 0xfc25fdf0  sd          $a1, -0x210($at)
    ctx->pc = 0x197718u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966768), GPR_U64(ctx, 5));
    // 0x19771c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19771cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197720: 0xfc25fe08  sd          $a1, -0x1F8($at)
    ctx->pc = 0x197720u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966792), GPR_U64(ctx, 5));
    // 0x197724: 0xfc450020  sd          $a1, 0x20($v0)
    ctx->pc = 0x197724u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 5));
    // 0x197728: 0xfc440028  sd          $a0, 0x28($v0)
    ctx->pc = 0x197728u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 4));
    // 0x19772c: 0xfc450030  sd          $a1, 0x30($v0)
    ctx->pc = 0x19772cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 5));
    // 0x197730: 0xfc430038  sd          $v1, 0x38($v0)
    ctx->pc = 0x197730u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_197734:
    // 0x197734: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x197734u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_197738:
    // 0x197738: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x197738u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x19773c: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x19773cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x197740: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x197740u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197744: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x197744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197748: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x197748u;
    SET_GPR_U32(ctx, 31, 0x197750u);
    ctx->pc = 0x19774Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197748u;
            // 0x19774c: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197750u; }
        if (ctx->pc != 0x197750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197750u; }
        if (ctx->pc != 0x197750u) { return; }
    }
    ctx->pc = 0x197750u;
label_197750:
    // 0x197750: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x197750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x197754: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x197754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x197758: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x197758u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19775c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19775cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x197760: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x197760u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x197764: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x197764u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x197768: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x197768u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19776c: 0x3e00008  jr          $ra
    ctx->pc = 0x19776Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19776Cu;
            // 0x197770: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1974C0u: goto label_1974c0;
            case 0x1974E0u: goto label_1974e0;
            case 0x1974ECu: goto label_1974ec;
            case 0x197508u: goto label_197508;
            case 0x197524u: goto label_197524;
            case 0x19752Cu: goto label_19752c;
            case 0x197538u: goto label_197538;
            case 0x19753Cu: goto label_19753c;
            case 0x1975BCu: goto label_1975bc;
            case 0x197628u: goto label_197628;
            case 0x197694u: goto label_197694;
            case 0x197734u: goto label_197734;
            case 0x197738u: goto label_197738;
            case 0x197750u: goto label_197750;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197774u;
    // 0x197774: 0x0  nop
    ctx->pc = 0x197774u;
    // NOP
    // 0x197778: 0x0  nop
    ctx->pc = 0x197778u;
    // NOP
    // 0x19777c: 0x0  nop
    ctx->pc = 0x19777cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
