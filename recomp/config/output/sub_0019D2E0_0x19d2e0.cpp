#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D2E0
// Address: 0x19d2e0 - 0x19d3f0
void sub_0019D2E0_0x19d2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D2E0_0x19d2e0");
#endif

    switch (ctx->pc) {
        case 0x19d31cu: goto label_19d31c;
        case 0x19d364u: goto label_19d364;
        case 0x19d384u: goto label_19d384;
        case 0x19d38cu: goto label_19d38c;
        case 0x19d398u: goto label_19d398;
        case 0x19d3a8u: goto label_19d3a8;
        case 0x19d3c4u: goto label_19d3c4;
        default: break;
    }

    ctx->pc = 0x19d2e0u;

    // 0x19d2e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x19d2e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x19d2e4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x19d2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x19d2e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19d2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19d2ec: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x19d2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x19d2f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19d2f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19d2f4: 0x24424e80  addiu       $v0, $v0, 0x4E80
    ctx->pc = 0x19d2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20096));
    // 0x19d2f8: 0xafa4002c  sw          $a0, 0x2C($sp)
    ctx->pc = 0x19d2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 4));
    // 0x19d2fc: 0x8fa4002c  lw          $a0, 0x2C($sp)
    ctx->pc = 0x19d2fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x19d300: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x19d300u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x19d304: 0x31c02  srl         $v1, $v1, 16
    ctx->pc = 0x19d304u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x19d308: 0x2464ffff  addiu       $a0, $v1, -0x1
    ctx->pc = 0x19d308u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19d30c: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x19d30cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x19d310: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x19d310u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19d314: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x19d314u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x19d318: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x19d318u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_19d31c:
    // 0x19d31c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x19d31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x19d320: 0x10a2000e  beq         $a1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x19D320u;
    {
        const bool branch_taken_0x19d320 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x19D324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D320u;
            // 0x19d324: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d320) {
            ctx->pc = 0x19D35Cu;
            goto label_19d35c;
        }
    }
    ctx->pc = 0x19D328u;
    // 0x19d328: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x19d328u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19d32c: 0x10a2000a  beq         $a1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x19D32Cu;
    {
        const bool branch_taken_0x19d32c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x19d32c) {
            ctx->pc = 0x19D358u;
            goto label_19d358;
        }
    }
    ctx->pc = 0x19D334u;
    // 0x19d334: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x19d334u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x19d338: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x19D338u;
    {
        const bool branch_taken_0x19d338 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x19d338) {
            ctx->pc = 0x19D358u;
            goto label_19d358;
        }
    }
    ctx->pc = 0x19D340u;
    // 0x19d340: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x19d340u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19d344: 0x10a2001f  beq         $a1, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x19D344u;
    {
        const bool branch_taken_0x19d344 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x19d344) {
            ctx->pc = 0x19D3C4u;
            goto label_19d3c4;
        }
    }
    ctx->pc = 0x19D34Cu;
    // 0x19d34c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d34cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d350: 0x10a2001c  beq         $a1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x19D350u;
    {
        const bool branch_taken_0x19d350 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x19d350) {
            ctx->pc = 0x19D3C4u;
            goto label_19d3c4;
        }
    }
    ctx->pc = 0x19D358u;
label_19d358:
    // 0x19d358: 0x27a4002c  addiu       $a0, $sp, 0x2C
    ctx->pc = 0x19d358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
label_19d35c:
    // 0x19d35c: 0xc067bc0  jal         func_19EF00
    ctx->pc = 0x19D35Cu;
    SET_GPR_U32(ctx, 31, 0x19D364u);
    ctx->pc = 0x19D360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D35Cu;
            // 0x19d360: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EF00u;
    if (runtime->hasFunction(0x19EF00u)) {
        auto targetFn = runtime->lookupFunction(0x19EF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D364u; }
        if (ctx->pc != 0x19D364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EF00_0x19ef00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D364u; }
        if (ctx->pc != 0x19D364u) { return; }
    }
    ctx->pc = 0x19D364u;
label_19d364:
    // 0x19d364: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x19D364u;
    {
        const bool branch_taken_0x19d364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D364u;
            // 0x19d368: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d364) {
            ctx->pc = 0x19D37Cu;
            goto label_19d37c;
        }
    }
    ctx->pc = 0x19D36Cu;
    // 0x19d36c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x19d36cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19d370: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x19D370u;
    {
        const bool branch_taken_0x19d370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D370u;
            // 0x19d374: 0xae050000  sw          $a1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d370) {
            ctx->pc = 0x19D31Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d31c;
        }
    }
    ctx->pc = 0x19D378u;
    // 0x19d378: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19d378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_19d37c:
    // 0x19d37c: 0xc067390  jal         func_19CE40
    ctx->pc = 0x19D37Cu;
    SET_GPR_U32(ctx, 31, 0x19D384u);
    ctx->pc = 0x19CE40u;
    if (runtime->hasFunction(0x19CE40u)) {
        auto targetFn = runtime->lookupFunction(0x19CE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D384u; }
        if (ctx->pc != 0x19D384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CE40_0x19ce40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D384u; }
        if (ctx->pc != 0x19D384u) { return; }
    }
    ctx->pc = 0x19D384u;
label_19d384:
    // 0x19d384: 0xc06322c  jal         func_18C8B0
    ctx->pc = 0x19D384u;
    SET_GPR_U32(ctx, 31, 0x19D38Cu);
    ctx->pc = 0x19D388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D384u;
            // 0x19d388: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C8B0u;
    if (runtime->hasFunction(0x18C8B0u)) {
        auto targetFn = runtime->lookupFunction(0x18C8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D38Cu; }
        if (ctx->pc != 0x19D38Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C8B0_0x18c8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D38Cu; }
        if (ctx->pc != 0x19D38Cu) { return; }
    }
    ctx->pc = 0x19D38Cu;
label_19d38c:
    // 0x19d38c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x19d38cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d390: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19D390u;
    SET_GPR_U32(ctx, 31, 0x19D398u);
    ctx->pc = 0x19D394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D390u;
            // 0x19d394: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D398u; }
        if (ctx->pc != 0x19D398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D398u; }
        if (ctx->pc != 0x19D398u) { return; }
    }
    ctx->pc = 0x19D398u;
label_19d398:
    // 0x19d398: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19d398u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d39c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x19d39cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d3a0: 0xc063340  jal         func_18CD00
    ctx->pc = 0x19D3A0u;
    SET_GPR_U32(ctx, 31, 0x19D3A8u);
    ctx->pc = 0x19D3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D3A0u;
            // 0x19d3a4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CD00u;
    if (runtime->hasFunction(0x18CD00u)) {
        auto targetFn = runtime->lookupFunction(0x18CD00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D3A8u; }
        if (ctx->pc != 0x19D3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CD00_0x18cd00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D3A8u; }
        if (ctx->pc != 0x19D3A8u) { return; }
    }
    ctx->pc = 0x19D3A8u;
label_19d3a8:
    // 0x19d3a8: 0x10293c  dsll32      $a1, $s0, 4
    ctx->pc = 0x19d3a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 4));
    // 0x19d3ac: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x19d3acu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x19d3b0: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x19d3b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x19d3b4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x19d3b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d3b8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19d3b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d3bc: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x19D3BCu;
    SET_GPR_U32(ctx, 31, 0x19D3C4u);
    ctx->pc = 0x19D3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D3BCu;
            // 0x19d3c0: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D3C4u; }
        if (ctx->pc != 0x19D3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D3C4u; }
        if (ctx->pc != 0x19D3C4u) { return; }
    }
    ctx->pc = 0x19D3C4u;
label_19d3c4:
    // 0x19d3c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d3c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d3c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d3cc: 0x8c23bec0  lw          $v1, -0x4140($at)
    ctx->pc = 0x19d3ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950592)));
    // 0x19d3d0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x19d3d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19d3d4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d3d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d3d8: 0xac23bec0  sw          $v1, -0x4140($at)
    ctx->pc = 0x19d3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950592), GPR_U32(ctx, 3));
    // 0x19d3dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19d3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19d3e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19d3e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19d3e4: 0x3e00008  jr          $ra
    ctx->pc = 0x19D3E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D3E4u;
            // 0x19d3e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D31Cu: goto label_19d31c;
            case 0x19D358u: goto label_19d358;
            case 0x19D35Cu: goto label_19d35c;
            case 0x19D364u: goto label_19d364;
            case 0x19D37Cu: goto label_19d37c;
            case 0x19D384u: goto label_19d384;
            case 0x19D38Cu: goto label_19d38c;
            case 0x19D398u: goto label_19d398;
            case 0x19D3A8u: goto label_19d3a8;
            case 0x19D3C4u: goto label_19d3c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D3ECu;
    // 0x19d3ec: 0x0  nop
    ctx->pc = 0x19d3ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
