#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F8A8
// Address: 0x13f8a8 - 0x13f9f0
void sub_0013F8A8_0x13f8a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F8A8_0x13f8a8");
#endif

    switch (ctx->pc) {
        case 0x13f8d0u: goto label_13f8d0;
        case 0x13f8f0u: goto label_13f8f0;
        case 0x13f970u: goto label_13f970;
        case 0x13f978u: goto label_13f978;
        case 0x13f9acu: goto label_13f9ac;
        case 0x13f9c4u: goto label_13f9c4;
        default: break;
    }

    ctx->pc = 0x13f8a8u;

    // 0x13f8a8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13f8a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f8ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f8b0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13f8b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8b4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f8b8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13f8b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8bc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13f8bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f8c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f8c4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13f8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13f8c8: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F8C8u;
    SET_GPR_U32(ctx, 31, 0x13F8D0u);
    ctx->pc = 0x13F8CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F8C8u;
            // 0x13f8cc: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F8D0u; }
        if (ctx->pc != 0x13F8D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F8D0u; }
        if (ctx->pc != 0x13F8D0u) { return; }
    }
    ctx->pc = 0x13F8D0u;
label_13f8d0:
    // 0x13f8d0: 0x3c050022  lui         $a1, 0x22
    ctx->pc = 0x13f8d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)34 << 16));
    // 0x13f8d4: 0x24a24c60  addiu       $v0, $a1, 0x4C60
    ctx->pc = 0x13f8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 19552));
    // 0x13f8d8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x13f8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x13f8dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x13f8dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13f8e0: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13F8E0u;
    {
        const bool branch_taken_0x13f8e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F8E0u;
            // 0x13f8e4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f8e0) {
            ctx->pc = 0x13F914u;
            goto label_13f914;
        }
    }
    ctx->pc = 0x13F8E8u;
    // 0x13f8e8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x13f8e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8ec: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x13f8ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_13f8f0:
    // 0x13f8f0: 0x28820100  slti        $v0, $a0, 0x100
    ctx->pc = 0x13f8f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x13f8f4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13F8F4u;
    {
        const bool branch_taken_0x13f8f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F8F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F8F4u;
            // 0x13f8f8: 0x24630040  addiu       $v1, $v1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f8f4) {
            ctx->pc = 0x13F914u;
            goto label_13f914;
        }
    }
    ctx->pc = 0x13F8FCu;
    // 0x13f8fc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13f8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13f900: 0x0  nop
    ctx->pc = 0x13f900u;
    // NOP
    // 0x13f904: 0x0  nop
    ctx->pc = 0x13f904u;
    // NOP
    // 0x13f908: 0x0  nop
    ctx->pc = 0x13f908u;
    // NOP
    // 0x13f90c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13F90Cu;
    {
        const bool branch_taken_0x13f90c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13f90c) {
            ctx->pc = 0x13F910u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F90Cu;
            // 0x13f910: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F8F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13f8f0;
        }
    }
    ctx->pc = 0x13F914u;
label_13f914:
    // 0x13f914: 0x24020100  addiu       $v0, $zero, 0x100
    ctx->pc = 0x13f914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x13f918: 0x10820015  beq         $a0, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x13F918u;
    {
        const bool branch_taken_0x13f918 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x13F91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F918u;
            // 0x13f91c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f918) {
            ctx->pc = 0x13F970u;
            goto label_13f970;
        }
    }
    ctx->pc = 0x13F920u;
    // 0x13f920: 0x24a24c60  addiu       $v0, $a1, 0x4C60
    ctx->pc = 0x13f920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 19552));
    // 0x13f924: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13f924u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13f928: 0x42180  sll         $a0, $a0, 6
    ctx->pc = 0x13f928u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x13f92c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13f92cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13f930: 0x3c060014  lui         $a2, 0x14
    ctx->pc = 0x13f930u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)20 << 16));
    // 0x13f934: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x13f934u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f938: 0x24634c28  addiu       $v1, $v1, 0x4C28
    ctx->pc = 0x13f938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19496));
    // 0x13f93c: 0x24a5da58  addiu       $a1, $a1, -0x25A8
    ctx->pc = 0x13f93cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294957656));
    // 0x13f940: 0x24c6f7d8  addiu       $a2, $a2, -0x828
    ctx->pc = 0x13f940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294965208));
    // 0x13f944: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13f944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13f948: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x13f948u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x13f94c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13f94cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f950: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x13f950u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x13f954: 0xae11001c  sw          $s1, 0x1C($s0)
    ctx->pc = 0x13f954u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x13f958: 0xae120020  sw          $s2, 0x20($s0)
    ctx->pc = 0x13f958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x13f95c: 0xae130024  sw          $s3, 0x24($s0)
    ctx->pc = 0x13f95cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 19));
    // 0x13f960: 0xae050008  sw          $a1, 0x8($s0)
    ctx->pc = 0x13f960u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x13f964: 0xae060038  sw          $a2, 0x38($s0)
    ctx->pc = 0x13f964u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 6));
    // 0x13f968: 0xc04fe7c  jal         func_13F9F0
    ctx->pc = 0x13F968u;
    SET_GPR_U32(ctx, 31, 0x13F970u);
    ctx->pc = 0x13F96Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F968u;
            // 0x13f96c: 0xae10003c  sw          $s0, 0x3C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F9F0u;
    if (runtime->hasFunction(0x13F9F0u)) {
        auto targetFn = runtime->lookupFunction(0x13F9F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F970u; }
        if (ctx->pc != 0x13F970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F9F0_0x13f9f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F970u; }
        if (ctx->pc != 0x13F970u) { return; }
    }
    ctx->pc = 0x13F970u;
label_13f970:
    // 0x13f970: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x13F970u;
    SET_GPR_U32(ctx, 31, 0x13F978u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F978u; }
        if (ctx->pc != 0x13F978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F978u; }
        if (ctx->pc != 0x13F978u) { return; }
    }
    ctx->pc = 0x13F978u;
label_13f978:
    // 0x13f978: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x13f978u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f97c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f97cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f980: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f984: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f984u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f988: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13f988u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f98c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13f98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f990: 0x3e00008  jr          $ra
    ctx->pc = 0x13F990u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F990u;
            // 0x13f994: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8D0u: goto label_13f8d0;
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F978u: goto label_13f978;
            case 0x13F9ACu: goto label_13f9ac;
            case 0x13F9C4u: goto label_13f9c4;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F998u;
    // 0x13f998: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f99c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f99cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f9a0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13f9a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13f9a4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F9A4u;
    SET_GPR_U32(ctx, 31, 0x13F9ACu);
    ctx->pc = 0x13F9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9A4u;
            // 0x13f9a8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9ACu; }
        if (ctx->pc != 0x13F9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9ACu; }
        if (ctx->pc != 0x13F9ACu) { return; }
    }
    ctx->pc = 0x13F9ACu;
label_13f9ac:
    // 0x13f9ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13f9acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f9b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b4: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F9B4u;
    {
        const bool branch_taken_0x13f9b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9B4u;
            // 0x13f9b8: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f9b4) {
            ctx->pc = 0x13F9C8u;
            goto label_13f9c8;
        }
    }
    ctx->pc = 0x13F9BCu;
    // 0x13f9bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F9BCu;
    SET_GPR_U32(ctx, 31, 0x13F9C4u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9C4u; }
        if (ctx->pc != 0x13F9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9C4u; }
        if (ctx->pc != 0x13F9C4u) { return; }
    }
    ctx->pc = 0x13F9C4u;
label_13f9c4:
    // 0x13f9c4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x13f9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_13f9c8:
    // 0x13f9c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f9c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f9cc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13f9ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f9d0: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F9D0u;
    ctx->pc = 0x13F9D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9D0u;
            // 0x13f9d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F9D8u;
    // 0x13f9d8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F9D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9D8u;
            // 0x13f9dc: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8D0u: goto label_13f8d0;
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F978u: goto label_13f978;
            case 0x13F9ACu: goto label_13f9ac;
            case 0x13F9C4u: goto label_13f9c4;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F9E0u;
    // 0x13f9e0: 0xac86003c  sw          $a2, 0x3C($a0)
    ctx->pc = 0x13f9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 6));
    // 0x13f9e4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F9E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9E4u;
            // 0x13f9e8: 0xac850038  sw          $a1, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8D0u: goto label_13f8d0;
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F978u: goto label_13f978;
            case 0x13F9ACu: goto label_13f9ac;
            case 0x13F9C4u: goto label_13f9c4;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F9ECu;
    // 0x13f9ec: 0x0  nop
    ctx->pc = 0x13f9ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
