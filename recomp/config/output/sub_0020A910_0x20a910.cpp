#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A910
// Address: 0x20a910 - 0x20aaf4
void sub_0020A910_0x20a910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A910_0x20a910");
#endif

    switch (ctx->pc) {
        case 0x20a980u: goto label_20a980;
        case 0x20a994u: goto label_20a994;
        case 0x20a998u: goto label_20a998;
        case 0x20a9c8u: goto label_20a9c8;
        case 0x20a9d8u: goto label_20a9d8;
        case 0x20a9e4u: goto label_20a9e4;
        case 0x20aa04u: goto label_20aa04;
        case 0x20aa14u: goto label_20aa14;
        case 0x20aa24u: goto label_20aa24;
        case 0x20aa38u: goto label_20aa38;
        case 0x20aa50u: goto label_20aa50;
        case 0x20aab0u: goto label_20aab0;
        case 0x20aac0u: goto label_20aac0;
        default: break;
    }

    ctx->pc = 0x20a910u;

    // 0x20a910: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x20a910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x20a914: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20a914u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20a918: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x20a918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x20a91c: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20a91cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20a920: 0xffb70080  sd          $s7, 0x80($sp)
    ctx->pc = 0x20a920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x20a924: 0x241e0010  addiu       $fp, $zero, 0x10
    ctx->pc = 0x20a924u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x20a928: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x20a928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x20a92c: 0x3c178007  lui         $s7, 0x8007
    ctx->pc = 0x20a92cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32775 << 16));
    // 0x20a930: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x20a930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x20a934: 0x3c168007  lui         $s6, 0x8007
    ctx->pc = 0x20a934u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)32775 << 16));
    // 0x20a938: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x20a938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x20a93c: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x20a93cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a940: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x20a940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x20a944: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x20a944u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a948: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x20a948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x20a94c: 0x3c128007  lui         $s2, 0x8007
    ctx->pc = 0x20a94cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32775 << 16));
    // 0x20a950: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x20a950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x20a954: 0x2411004c  addiu       $s1, $zero, 0x4C
    ctx->pc = 0x20a954u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x20a958: 0x8c484728  lw          $t0, 0x4728($v0)
    ctx->pc = 0x20a958u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18216)));
    // 0x20a95c: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x20a95cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x20a960: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x20a960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x20a964: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x20a964u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x20a968: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x20a968u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x20a96c: 0x8d130000  lw          $s3, 0x0($t0)
    ctx->pc = 0x20a96cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x20a970: 0x8c624730  lw          $v0, 0x4730($v1)
    ctx->pc = 0x20a970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18224)));
    // 0x20a974: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x20a974u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x20a978: 0x40f809  jalr        $v0
    ctx->pc = 0x20A978u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A980u);
        ctx->pc = 0x20A97Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A978u;
            // 0x20a97c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A980u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A980u; }
            if (ctx->pc != 0x20A980u) { return; }
        }
        }
    }
    ctx->pc = 0x20A980u;
label_20a980:
    // 0x20a980: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20a980u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20a984: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x20a984u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a988: 0x8c624734  lw          $v0, 0x4734($v1)
    ctx->pc = 0x20a988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18228)));
    // 0x20a98c: 0x40f809  jalr        $v0
    ctx->pc = 0x20A98Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A994u);
        ctx->pc = 0x20A990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A98Cu;
            // 0x20a990: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A994u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A994u; }
            if (ctx->pc != 0x20A994u) { return; }
        }
        }
    }
    ctx->pc = 0x20A994u;
label_20a994:
    // 0x20a994: 0x0  nop
    ctx->pc = 0x20a994u;
    // NOP
label_20a998:
    // 0x20a998: 0x8ec24748  lw          $v0, 0x4748($s6)
    ctx->pc = 0x20a998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 18248)));
    // 0x20a99c: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x20a99cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x20a9a0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x20a9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x20a9a4: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x20A9A4u;
    {
        const bool branch_taken_0x20a9a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x20a9a4) {
            ctx->pc = 0x20A9A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9A4u;
            // 0x20a9a8: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x20A9E8u;
            goto label_20a9e8;
        }
    }
    ctx->pc = 0x20A9ACu;
    // 0x20a9ac: 0x5213000e  beql        $s0, $s3, . + 4 + (0xE << 2)
    ctx->pc = 0x20A9ACu;
    {
        const bool branch_taken_0x20a9ac = (GPR_U64(ctx, 16) == GPR_U64(ctx, 19));
        if (branch_taken_0x20a9ac) {
            ctx->pc = 0x20A9B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9ACu;
            // 0x20a9b0: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x20A9E8u;
            goto label_20a9e8;
        }
    }
    ctx->pc = 0x20A9B4u;
    // 0x20a9b4: 0x145e0006  bne         $v0, $fp, . + 4 + (0x6 << 2)
    ctx->pc = 0x20A9B4u;
    {
        const bool branch_taken_0x20a9b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 30));
        ctx->pc = 0x20A9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9B4u;
            // 0x20a9b8: 0x8ee24744  lw          $v0, 0x4744($s7) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 18244)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a9b4) {
            ctx->pc = 0x20A9D0u;
            goto label_20a9d0;
        }
    }
    ctx->pc = 0x20A9BCu;
    // 0x20a9bc: 0x8e424740  lw          $v0, 0x4740($s2)
    ctx->pc = 0x20a9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 18240)));
    // 0x20a9c0: 0x40f809  jalr        $v0
    ctx->pc = 0x20A9C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A9C8u);
        ctx->pc = 0x20A9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9C0u;
            // 0x20a9c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A9C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A9C8u; }
            if (ctx->pc != 0x20A9C8u) { return; }
        }
        }
    }
    ctx->pc = 0x20A9C8u;
label_20a9c8:
    // 0x20a9c8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x20A9C8u;
    {
        const bool branch_taken_0x20a9c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A9CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9C8u;
            // 0x20a9cc: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a9c8) {
            ctx->pc = 0x20A9E8u;
            goto label_20a9e8;
        }
    }
    ctx->pc = 0x20A9D0u;
label_20a9d0:
    // 0x20a9d0: 0x40f809  jalr        $v0
    ctx->pc = 0x20A9D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A9D8u);
        ctx->pc = 0x20A9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9D0u;
            // 0x20a9d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A9D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A9D8u; }
            if (ctx->pc != 0x20A9D8u) { return; }
        }
        }
    }
    ctx->pc = 0x20A9D8u;
label_20a9d8:
    // 0x20a9d8: 0x8e424740  lw          $v0, 0x4740($s2)
    ctx->pc = 0x20a9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 18240)));
    // 0x20a9dc: 0x40f809  jalr        $v0
    ctx->pc = 0x20A9DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20A9E4u);
        ctx->pc = 0x20A9E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9DCu;
            // 0x20a9e0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20A9E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20A9E4u; }
            if (ctx->pc != 0x20A9E4u) { return; }
        }
        }
    }
    ctx->pc = 0x20A9E4u;
label_20a9e4:
    // 0x20a9e4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x20a9e4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_20a9e8:
    // 0x20a9e8: 0x2a020100  slti        $v0, $s0, 0x100
    ctx->pc = 0x20a9e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x20a9ec: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x20A9ECu;
    {
        const bool branch_taken_0x20a9ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A9F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9ECu;
            // 0x20a9f0: 0x2631004c  addiu       $s1, $s1, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 76));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a9ec) {
            ctx->pc = 0x20A998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20a998;
        }
    }
    ctx->pc = 0x20A9F4u;
    // 0x20a9f4: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20a9f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20a9f8: 0x8c62473c  lw          $v0, 0x473C($v1)
    ctx->pc = 0x20a9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18236)));
    // 0x20a9fc: 0x40f809  jalr        $v0
    ctx->pc = 0x20A9FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20AA04u);
        ctx->pc = 0x20AA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A9FCu;
            // 0x20aa00: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20AA04u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20AA04u; }
            if (ctx->pc != 0x20AA04u) { return; }
        }
        }
    }
    ctx->pc = 0x20AA04u;
label_20aa04:
    // 0x20aa04: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20aa04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa08: 0x8c624738  lw          $v0, 0x4738($v1)
    ctx->pc = 0x20aa08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18232)));
    // 0x20aa0c: 0x40f809  jalr        $v0
    ctx->pc = 0x20AA0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20AA14u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20AA14u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20AA14u; }
            if (ctx->pc != 0x20AA14u) { return; }
        }
        }
    }
    ctx->pc = 0x20AA14u;
label_20aa14:
    // 0x20aa14: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20aa14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa18: 0x8c62472c  lw          $v0, 0x472C($v1)
    ctx->pc = 0x20aa18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18220)));
    // 0x20aa1c: 0xc01d0f2  jal         func_0743C8
    ctx->pc = 0x20AA1Cu;
    SET_GPR_U32(ctx, 31, 0x20AA24u);
    ctx->pc = 0x20AA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20AA1Cu;
            // 0x20aa20: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x743C8u;
    {
        auto targetFn = runtime->lookupFunction(0x743C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20AA24u; }
        if (ctx->pc != 0x20AA24u) { return; }
    }
    ctx->pc = 0x20AA24u;
label_20aa24:
    // 0x20aa24: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20aa24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa28: 0x1a80000d  blez        $s4, . + 4 + (0xD << 2)
    ctx->pc = 0x20AA28u;
    {
        const bool branch_taken_0x20aa28 = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x20AA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AA28u;
            // 0x20aa2c: 0x8c444778  lw          $a0, 0x4778($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18296)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20aa28) {
            ctx->pc = 0x20AA60u;
            goto label_20aa60;
        }
    }
    ctx->pc = 0x20AA30u;
    // 0x20aa30: 0x3c118007  lui         $s1, 0x8007
    ctx->pc = 0x20aa30u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa34: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x20aa34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_20aa38:
    // 0x20aa38: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x20aa38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x20aa3c: 0x8e224770  lw          $v0, 0x4770($s1)
    ctx->pc = 0x20aa3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 18288)));
    // 0x20aa40: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x20aa40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x20aa44: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x20aa44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x20aa48: 0x40f809  jalr        $v0
    ctx->pc = 0x20AA48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x20AA50u);
        ctx->pc = 0x20AA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AA48u;
            // 0x20aa4c: 0x8c650000  lw          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20AA50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20AA50u; }
            if (ctx->pc != 0x20AA50u) { return; }
        }
        }
    }
    ctx->pc = 0x20AA50u;
label_20aa50:
    // 0x20aa50: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x20aa50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20aa54: 0x214102a  slt         $v0, $s0, $s4
    ctx->pc = 0x20aa54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x20aa58: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x20AA58u;
    {
        const bool branch_taken_0x20aa58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AA58u;
            // 0x20aa5c: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20aa58) {
            ctx->pc = 0x20AA38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20aa38;
        }
    }
    ctx->pc = 0x20AA60u;
label_20aa60:
    // 0x20aa60: 0x2402004c  addiu       $v0, $zero, 0x4C
    ctx->pc = 0x20aa60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x20aa64: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20aa64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa68: 0x2621018  mult        $v0, $s3, $v0
    ctx->pc = 0x20aa68u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x20aa6c: 0x8ec54748  lw          $a1, 0x4748($s6)
    ctx->pc = 0x20aa6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 18248)));
    // 0x20aa70: 0x8c644778  lw          $a0, 0x4778($v1)
    ctx->pc = 0x20aa70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18296)));
    // 0x20aa74: 0x3c038007  lui         $v1, 0x8007
    ctx->pc = 0x20aa74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32775 << 16));
    // 0x20aa78: 0x8c66476c  lw          $a2, 0x476C($v1)
    ctx->pc = 0x20aa78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 18284)));
    // 0x20aa7c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x20aa7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x20aa80: 0xac440038  sw          $a0, 0x38($v0)
    ctx->pc = 0x20aa80u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 4));
    // 0x20aa84: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x20aa84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20aa88: 0xac540034  sw          $s4, 0x34($v0)
    ctx->pc = 0x20aa88u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 20));
    // 0x20aa8c: 0xac55000c  sw          $s5, 0xC($v0)
    ctx->pc = 0x20aa8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 21));
    // 0x20aa90: 0xac550030  sw          $s5, 0x30($v0)
    ctx->pc = 0x20aa90u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 21));
    // 0x20aa94: 0xac450014  sw          $a1, 0x14($v0)
    ctx->pc = 0x20aa94u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 5));
    // 0x20aa98: 0xa440001a  sh          $zero, 0x1A($v0)
    ctx->pc = 0x20aa98u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 26), (uint16_t)GPR_U32(ctx, 0));
    // 0x20aa9c: 0xa4400018  sh          $zero, 0x18($v0)
    ctx->pc = 0x20aa9cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 24), (uint16_t)GPR_U32(ctx, 0));
    // 0x20aaa0: 0xac400024  sw          $zero, 0x24($v0)
    ctx->pc = 0x20aaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 0));
    // 0x20aaa4: 0xac40001c  sw          $zero, 0x1C($v0)
    ctx->pc = 0x20aaa4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x20aaa8: 0xc0f809  jalr        $a2
    ctx->pc = 0x20AAA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x20AAB0u);
        ctx->pc = 0x20AAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AAA8u;
            // 0x20aaac: 0xac400020  sw          $zero, 0x20($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x20AAB0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20AAB0u; }
            if (ctx->pc != 0x20AAB0u) { return; }
        }
        }
    }
    ctx->pc = 0x20AAB0u;
label_20aab0:
    // 0x20aab0: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20aab0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20aab4: 0x8c434768  lw          $v1, 0x4768($v0)
    ctx->pc = 0x20aab4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 18280)));
    // 0x20aab8: 0x60f809  jalr        $v1
    ctx->pc = 0x20AAB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x20AAC0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x20AAC0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x20AAC0u; }
            if (ctx->pc != 0x20AAC0u) { return; }
        }
        }
    }
    ctx->pc = 0x20AAC0u;
label_20aac0:
    // 0x20aac0: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x20aac0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20aac4: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x20aac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x20aac8: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x20aac8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x20aacc: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x20aaccu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x20aad0: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x20aad0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x20aad4: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x20aad4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x20aad8: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x20aad8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x20aadc: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x20aadcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x20aae0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x20aae0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x20aae4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x20aae4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20aae8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x20aae8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20aaec: 0x3e00008  jr          $ra
    ctx->pc = 0x20AAECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20AAF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AAECu;
            // 0x20aaf0: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A980u: goto label_20a980;
            case 0x20A994u: goto label_20a994;
            case 0x20A998u: goto label_20a998;
            case 0x20A9C8u: goto label_20a9c8;
            case 0x20A9D0u: goto label_20a9d0;
            case 0x20A9D8u: goto label_20a9d8;
            case 0x20A9E4u: goto label_20a9e4;
            case 0x20A9E8u: goto label_20a9e8;
            case 0x20AA04u: goto label_20aa04;
            case 0x20AA14u: goto label_20aa14;
            case 0x20AA24u: goto label_20aa24;
            case 0x20AA38u: goto label_20aa38;
            case 0x20AA50u: goto label_20aa50;
            case 0x20AA60u: goto label_20aa60;
            case 0x20AAB0u: goto label_20aab0;
            case 0x20AAC0u: goto label_20aac0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20AAF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
