#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E4C8
// Address: 0x11e4c8 - 0x11e7a0
void sub_0011E4C8_0x11e4c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E4C8_0x11e4c8");
#endif

    switch (ctx->pc) {
        case 0x11e560u: goto label_11e560;
        case 0x11e5b0u: goto label_11e5b0;
        case 0x11e5ecu: goto label_11e5ec;
        case 0x11e630u: goto label_11e630;
        case 0x11e690u: goto label_11e690;
        case 0x11e6f4u: goto label_11e6f4;
        case 0x11e720u: goto label_11e720;
        case 0x11e75cu: goto label_11e75c;
        default: break;
    }

    ctx->pc = 0x11e4c8u;

label_11e4c8:
    // 0x11e4c8: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x11e4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x11e4cc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11E4CCu;
    {
        const bool branch_taken_0x11e4cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4CCu;
            // 0x11e4d0: 0x8c830000  lw          $v1, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e4cc) {
            ctx->pc = 0x11E4DCu;
            goto label_11e4dc;
        }
    }
    ctx->pc = 0x11E4D4u;
    // 0x11e4d4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11E4D4u;
    {
        const bool branch_taken_0x11e4d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4D4u;
            // 0x11e4d8: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e4d4) {
            ctx->pc = 0x11E4E4u;
            goto label_11e4e4;
        }
    }
    ctx->pc = 0x11E4DCu;
label_11e4dc:
    // 0x11e4dc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11e4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11e4e0: 0xac43b400  sw          $v1, -0x4C00($v0)
    ctx->pc = 0x11e4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294947840), GPR_U32(ctx, 3));
label_11e4e4:
    // 0x11e4e4: 0x50600004  beql        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E4E4u;
    {
        const bool branch_taken_0x11e4e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e4e4) {
            ctx->pc = 0x11E4E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4E4u;
            // 0x11e4e8: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E4F8u;
            goto label_11e4f8;
        }
    }
    ctx->pc = 0x11E4ECu;
    // 0x11e4ec: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x11e4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x11e4f0: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x11e4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x11e4f4: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x11e4f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
label_11e4f8:
    // 0x11e4f8: 0x3e00008  jr          $ra
    ctx->pc = 0x11E4F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E4FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4F8u;
            // 0x11e4fc: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E560u: goto label_11e560;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E630u: goto label_11e630;
            case 0x11E654u: goto label_11e654;
            case 0x11E674u: goto label_11e674;
            case 0x11E690u: goto label_11e690;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E720u: goto label_11e720;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E764u: goto label_11e764;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E500u;
    // 0x11e500: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x11e500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x11e504: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11e504u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11e508: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x11e508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x11e50c: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e50cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e510: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x11e510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x11e514: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x11e514u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e518: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x11e518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x11e51c: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x11e51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11e520: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11e520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11e524: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11e524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11e528: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11e528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11e52c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11e52cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11e530: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e534: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x11e534u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11e538: 0x30420400  andi        $v0, $v0, 0x400
    ctx->pc = 0x11e538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
    // 0x11e53c: 0x10400059  beqz        $v0, . + 4 + (0x59 << 2)
    ctx->pc = 0x11E53Cu;
    {
        const bool branch_taken_0x11e53c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E53Cu;
            // 0x11e540: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e53c) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E544u;
    // 0x11e544: 0x26a2b3e8  addiu       $v0, $s5, -0x4C18
    ctx->pc = 0x11e544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 4294947816));
    // 0x11e548: 0x8c500018  lw          $s0, 0x18($v0)
    ctx->pc = 0x11e548u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x11e54c: 0x12000055  beqz        $s0, . + 4 + (0x55 << 2)
    ctx->pc = 0x11E54Cu;
    {
        const bool branch_taken_0x11e54c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E54Cu;
            // 0x11e550: 0x2a0a02d  daddu       $s4, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e54c) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E554u;
    // 0x11e554: 0x24173999  addiu       $s7, $zero, 0x3999
    ctx->pc = 0x11e554u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 14745));
    // 0x11e558: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e558u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e55c: 0x0  nop
    ctx->pc = 0x11e55cu;
    // NOP
label_11e560:
    // 0x11e560: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11e560u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11e564: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x11e564u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x11e568: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e568u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e56c: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x11e56cu;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e570: 0x8c710000  lw          $s1, 0x0($v1)
    ctx->pc = 0x11e570u;
    SET_GPR_S32(ctx, 17, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11e574: 0xde040020  ld          $a0, 0x20($s0)
    ctx->pc = 0x11e574u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x11e578: 0xde020010  ld          $v0, 0x10($s0)
    ctx->pc = 0x11e578u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11e57c: 0x32250800  andi        $a1, $s1, 0x800
    ctx->pc = 0x11e57cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)2048);
    // 0x11e580: 0xde030018  ld          $v1, 0x18($s0)
    ctx->pc = 0x11e580u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x11e584: 0x82202d  daddu       $a0, $a0, $v0
    ctx->pc = 0x11e584u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 2));
    // 0x11e588: 0x10a0000b  beqz        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x11E588u;
    {
        const bool branch_taken_0x11e588 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E588u;
            // 0x11e58c: 0x83902f  dsubu       $s2, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 4) - GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e588) {
            ctx->pc = 0x11E5B8u;
            goto label_11e5b8;
        }
    }
    ctx->pc = 0x11E590u;
    // 0x11e590: 0xde82b3e8  ld          $v0, -0x4C18($s4)
    ctx->pc = 0x11e590u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 4294947816)));
    // 0x11e594: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e594u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e598: 0x3484fbff  ori         $a0, $a0, 0xFBFF
    ctx->pc = 0x11e598u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)64511);
    // 0x11e59c: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x11e59cu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x11e5a0: 0x2242024  and         $a0, $s1, $a0
    ctx->pc = 0x11e5a0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x11e5a4: 0xfe82b3e8  sd          $v0, -0x4C18($s4)
    ctx->pc = 0x11e5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 4294947816), GPR_U64(ctx, 2));
    // 0x11e5a8: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E5A8u;
    SET_GPR_U32(ctx, 31, 0x11E5B0u);
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E5B0u; }
        if (ctx->pc != 0x11E5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E5B0u; }
        if (ctx->pc != 0x11E5B0u) { return; }
    }
    ctx->pc = 0x11E5B0u;
label_11e5b0:
    // 0x11e5b0: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x11e5b0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x11e5b4: 0x8cc61000  lw          $a2, 0x1000($a2)
    ctx->pc = 0x11e5b4u;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 4096))); // MMIO: 0x10001000
label_11e5b8:
    // 0x11e5b8: 0xde84b3e8  ld          $a0, -0x4C18($s4)
    ctx->pc = 0x11e5b8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 20), 4294947816)));
    // 0x11e5bc: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x11e5bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x11e5c0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x11e5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x11e5c4: 0x32230003  andi        $v1, $s1, 0x3
    ctx->pc = 0x11e5c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)3);
    // 0x11e5c8: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x11e5c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x11e5cc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x11e5ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x11e5d0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x11e5d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x11e5d4: 0x648814  dsllv       $s1, $a0, $v1
    ctx->pc = 0x11e5d4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 4) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x11e5d8: 0x232102b  sltu        $v0, $s1, $s2
    ctx->pc = 0x11e5d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x11e5dc: 0x14400031  bnez        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x11E5DCu;
    {
        const bool branch_taken_0x11e5dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E5DCu;
            // 0x11e5e0: 0x2693b3e8  addiu       $s3, $s4, -0x4C18 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 20), 4294947816));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e5dc) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E5E4u;
    // 0x11e5e4: 0xc047932  jal         func_11E4C8
    ctx->pc = 0x11E5E4u;
    SET_GPR_U32(ctx, 31, 0x11E5ECu);
    ctx->pc = 0x11E5E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E5E4u;
            // 0x11e5e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E4C8u;
    goto label_11e4c8;
    ctx->pc = 0x11E5ECu;
label_11e5ec:
    // 0x11e5ec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11e5ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e5f0: 0xde060018  ld          $a2, 0x18($s0)
    ctx->pc = 0x11e5f0u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x11e5f4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11e5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e5f8: 0x103900  sll         $a3, $s0, 4
    ctx->pc = 0x11e5f8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11e5fc: 0xde030010  ld          $v1, 0x10($s0)
    ctx->pc = 0x11e5fcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11e600: 0x226302d  daddu       $a2, $s1, $a2
    ctx->pc = 0x11e600u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 6));
    // 0x11e604: 0xe21025  or          $v0, $a3, $v0
    ctx->pc = 0x11e604u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x11e608: 0xae62001c  sw          $v0, 0x1C($s3)
    ctx->pc = 0x11e608u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
    // 0x11e60c: 0xc3302f  dsubu       $a2, $a2, $v1
    ctx->pc = 0x11e60cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) - GPR_U64(ctx, 3));
    // 0x11e610: 0x8e1c002c  lw          $gp, 0x2C($s0)
    ctx->pc = 0x11e610u;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x11e614: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x11e614u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e618: 0x2c0402d  daddu       $t0, $s6, $zero
    ctx->pc = 0x11e618u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e61c: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x11e61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x11e620: 0xe42025  or          $a0, $a3, $a0
    ctx->pc = 0x11e620u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x11e624: 0xde050020  ld          $a1, 0x20($s0)
    ctx->pc = 0x11e624u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x11e628: 0x40f809  jalr        $v0
    ctx->pc = 0x11E628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11E630u);
        ctx->pc = 0x11E62Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E628u;
            // 0x11e62c: 0x8e070030  lw          $a3, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11E630u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E560u: goto label_11e560;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E630u: goto label_11e630;
            case 0x11E654u: goto label_11e654;
            case 0x11E674u: goto label_11e674;
            case 0x11E690u: goto label_11e690;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E720u: goto label_11e720;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E764u: goto label_11e764;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11E630u; }
            if (ctx->pc != 0x11E630u) { return; }
        }
        }
    }
    ctx->pc = 0x11E630u;
label_11e630:
    // 0x11e630: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11e630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e634: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11E634u;
    {
        const bool branch_taken_0x11e634 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E634u;
            // 0x11e638: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e634) {
            ctx->pc = 0x11E654u;
            goto label_11e654;
        }
    }
    ctx->pc = 0x11E63Cu;
    // 0x11e63c: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x11e63cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11e640: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11e640u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11e644: 0x3442fffd  ori         $v0, $v0, 0xFFFD
    ctx->pc = 0x11e644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65533);
    // 0x11e648: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x11e648u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x11e64c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x11E64Cu;
    {
        const bool branch_taken_0x11e64c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E64Cu;
            // 0x11e650: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e64c) {
            ctx->pc = 0x11E690u;
            goto label_11e690;
        }
    }
    ctx->pc = 0x11E654u;
label_11e654:
    // 0x11e654: 0x14a20007  bne         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11E654u;
    {
        const bool branch_taken_0x11e654 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x11E658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E654u;
            // 0x11e658: 0x24023998  addiu       $v0, $zero, 0x3998 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14744));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e654) {
            ctx->pc = 0x11E674u;
            goto label_11e674;
        }
    }
    ctx->pc = 0x11E65Cu;
    // 0x11e65c: 0x8e620014  lw          $v0, 0x14($s3)
    ctx->pc = 0x11e65cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x11e660: 0xae700014  sw          $s0, 0x14($s3)
    ctx->pc = 0x11e660u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 16));
    // 0x11e664: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x11e664u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x11e668: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x11e668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x11e66c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x11E66Cu;
    {
        const bool branch_taken_0x11e66c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E66Cu;
            // 0x11e670: 0xae00000c  sw          $zero, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e66c) {
            ctx->pc = 0x11E690u;
            goto label_11e690;
        }
    }
    ctx->pc = 0x11E674u;
label_11e674:
    // 0x11e674: 0xde030020  ld          $v1, 0x20($s0)
    ctx->pc = 0x11e674u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x11e678: 0x45102b  sltu        $v0, $v0, $a1
    ctx->pc = 0x11e678u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x11e67c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11e67cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e680: 0x2e2280a  movz        $a1, $s7, $v0
    ctx->pc = 0x11e680u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 23));
    // 0x11e684: 0x65182d  daddu       $v1, $v1, $a1
    ctx->pc = 0x11e684u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 5));
    // 0x11e688: 0xc047910  jal         func_11E440
    ctx->pc = 0x11E688u;
    SET_GPR_U32(ctx, 31, 0x11E690u);
    ctx->pc = 0x11E68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E688u;
            // 0x11e68c: 0xfe030020  sd          $v1, 0x20($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E440u;
    if (runtime->hasFunction(0x11E440u)) {
        auto targetFn = runtime->lookupFunction(0x11E440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E690u; }
        if (ctx->pc != 0x11E690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E440_0x11e440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E690u; }
        if (ctx->pc != 0x11E690u) { return; }
    }
    ctx->pc = 0x11E690u;
label_11e690:
    // 0x11e690: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x11e690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e694: 0x1600ffb2  bnez        $s0, . + 4 + (-0x4E << 2)
    ctx->pc = 0x11E694u;
    {
        const bool branch_taken_0x11e694 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E694u;
            // 0x11e698: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e694) {
            ctx->pc = 0x11E560u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11e560;
        }
    }
    ctx->pc = 0x11E69Cu;
    // 0x11e69c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11E69Cu;
    {
        const bool branch_taken_0x11e69c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E69Cu;
            // 0x11e6a0: 0x26a4b3e8  addiu       $a0, $s5, -0x4C18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294947816));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e69c) {
            ctx->pc = 0x11E6A8u;
            goto label_11e6a8;
        }
    }
    ctx->pc = 0x11E6A4u;
label_11e6a4:
    // 0x11e6a4: 0x26a4b3e8  addiu       $a0, $s5, -0x4C18
    ctx->pc = 0x11e6a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294947816));
label_11e6a8:
    // 0x11e6a8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11e6a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11e6ac: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x11e6acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x11e6b0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e6b4: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x11e6b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x11e6b8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11e6b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11e6bc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x11e6bcu;
    SET_GPR_S32(ctx, 4, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e6c0: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e6c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e6c4: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x11e6c4u;
    SET_GPR_S32(ctx, 16, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11e6c8: 0x32020800  andi        $v0, $s0, 0x800
    ctx->pc = 0x11e6c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)2048);
    // 0x11e6cc: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11E6CCu;
    {
        const bool branch_taken_0x11e6cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e6cc) {
            ctx->pc = 0x11E6FCu;
            goto label_11e6fc;
        }
    }
    ctx->pc = 0x11E6D4u;
    // 0x11e6d4: 0xdea2b3e8  ld          $v0, -0x4C18($s5)
    ctx->pc = 0x11e6d4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
    // 0x11e6d8: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e6d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e6dc: 0x3484fbff  ori         $a0, $a0, 0xFBFF
    ctx->pc = 0x11e6dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)64511);
    // 0x11e6e0: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x11e6e0u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x11e6e4: 0x2042024  and         $a0, $s0, $a0
    ctx->pc = 0x11e6e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & GPR_U64(ctx, 4));
    // 0x11e6e8: 0xfea2b3e8  sd          $v0, -0x4C18($s5)
    ctx->pc = 0x11e6e8u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 4294947816), GPR_U64(ctx, 2));
    // 0x11e6ec: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E6ECu;
    SET_GPR_U32(ctx, 31, 0x11E6F4u);
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E6F4u; }
        if (ctx->pc != 0x11E6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E6F4u; }
        if (ctx->pc != 0x11E6F4u) { return; }
    }
    ctx->pc = 0x11E6F4u;
label_11e6f4:
    // 0x11e6f4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x11e6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x11e6f8: 0x8c841000  lw          $a0, 0x1000($a0)
    ctx->pc = 0x11e6f8u;
    SET_GPR_S32(ctx, 4, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 4096))); // MMIO: 0x10001000
label_11e6fc:
    // 0x11e6fc: 0xdea2b3e8  ld          $v0, -0x4C18($s5)
    ctx->pc = 0x11e6fcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
    // 0x11e700: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x11e700u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11e704: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x11e704u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x11e708: 0x32040003  andi        $a0, $s0, 0x3
    ctx->pc = 0x11e708u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)3);
    // 0x11e70c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x11e70cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x11e710: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x11e710u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x11e714: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11e714u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11e718: 0xc0478ac  jal         func_11E2B0
    ctx->pc = 0x11E718u;
    SET_GPR_U32(ctx, 31, 0x11E720u);
    ctx->pc = 0x11E71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E718u;
            // 0x11e71c: 0x822014  dsllv       $a0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (GPR_U32(ctx, 4) & 0x3F));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E2B0u;
    if (runtime->hasFunction(0x11E2B0u)) {
        auto targetFn = runtime->lookupFunction(0x11E2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E720u; }
        if (ctx->pc != 0x11E720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E2B0_0x11e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E720u; }
        if (ctx->pc != 0x11E720u) { return; }
    }
    ctx->pc = 0x11E720u;
label_11e720:
    // 0x11e720: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e720u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e724: 0x8c421000  lw          $v0, 0x1000($v0)
    ctx->pc = 0x11e724u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4096))); // MMIO: 0x10001000
    // 0x11e728: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11e728u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11e72c: 0x8c631010  lw          $v1, 0x1010($v1)
    ctx->pc = 0x11e72cu;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 4112))); // MMIO: 0x10001010
    // 0x11e730: 0x30620800  andi        $v0, $v1, 0x800
    ctx->pc = 0x11e730u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2048);
    // 0x11e734: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11E734u;
    {
        const bool branch_taken_0x11e734 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e734) {
            ctx->pc = 0x11E764u;
            goto label_11e764;
        }
    }
    ctx->pc = 0x11E73Cu;
    // 0x11e73c: 0xdea2b3e8  ld          $v0, -0x4C18($s5)
    ctx->pc = 0x11e73cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
    // 0x11e740: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e740u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e744: 0x3484fbff  ori         $a0, $a0, 0xFBFF
    ctx->pc = 0x11e744u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)64511);
    // 0x11e748: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x11e748u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x11e74c: 0x642024  and         $a0, $v1, $a0
    ctx->pc = 0x11e74cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x11e750: 0xfea2b3e8  sd          $v0, -0x4C18($s5)
    ctx->pc = 0x11e750u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 4294947816), GPR_U64(ctx, 2));
    // 0x11e754: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E754u;
    SET_GPR_U32(ctx, 31, 0x11E75Cu);
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E75Cu; }
        if (ctx->pc != 0x11E75Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E75Cu; }
        if (ctx->pc != 0x11E75Cu) { return; }
    }
    ctx->pc = 0x11E75Cu;
label_11e75c:
    // 0x11e75c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e75cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e760: 0x8c421000  lw          $v0, 0x1000($v0)
    ctx->pc = 0x11e760u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4096))); // MMIO: 0x10001000
label_11e764:
    // 0x11e764: 0xdea2b3e8  ld          $v0, -0x4C18($s5)
    ctx->pc = 0x11e764u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
    // 0x11e768: 0xf  sync
    ctx->pc = 0x11e768u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11e76c: 0x42000038  ei
    ctx->pc = 0x11e76cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x11e770: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x11e770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11e774: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e774u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e778: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x11e778u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11e77c: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x11e77cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11e780: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x11e780u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11e784: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11e784u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11e788: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11e788u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e78c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e78cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e790: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e790u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e794: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e794u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e798: 0x3e00008  jr          $ra
    ctx->pc = 0x11E798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E79Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E798u;
            // 0x11e79c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E560u: goto label_11e560;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E630u: goto label_11e630;
            case 0x11E654u: goto label_11e654;
            case 0x11E674u: goto label_11e674;
            case 0x11E690u: goto label_11e690;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E720u: goto label_11e720;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E764u: goto label_11e764;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E7A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
