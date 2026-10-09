#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A830
// Address: 0x16a830 - 0x16a9a8
void sub_0016A830_0x16a830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A830_0x16a830");
#endif

    switch (ctx->pc) {
        case 0x16a878u: goto label_16a878;
        case 0x16a8b4u: goto label_16a8b4;
        case 0x16a8c8u: goto label_16a8c8;
        default: break;
    }

    ctx->pc = 0x16a830u;

    // 0x16a830: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16a830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16a834: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a838: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16a838u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a83c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16a83cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x16a840: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a844: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16a844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16a848: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x16a848u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a84c: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x16a84cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x16a850: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x16a850u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a854: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x16a854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x16a858: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x16a858u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a85c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a860: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a864: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16a864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a868: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x16a868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x16a86c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16a86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16a870: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A870u;
    SET_GPR_U32(ctx, 31, 0x16A878u);
    ctx->pc = 0x16A874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A870u;
            // 0x16a874: 0x100882d  daddu       $s1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A878u; }
        if (ctx->pc != 0x16A878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A878u; }
        if (ctx->pc != 0x16A878u) { return; }
    }
    ctx->pc = 0x16A878u;
label_16a878:
    // 0x16a878: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A878u;
    {
        const bool branch_taken_0x16a878 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A87Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A878u;
            // 0x16a87c: 0x26b61ae4  addiu       $s6, $s5, 0x1AE4 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 21), 6884));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a878) {
            ctx->pc = 0x16A888u;
            goto label_16a888;
        }
    }
    ctx->pc = 0x16A880u;
    // 0x16a880: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x16A880u;
    {
        const bool branch_taken_0x16a880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A880u;
            // 0x16a884: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a880) {
            ctx->pc = 0x16A978u;
            goto label_16a978;
        }
    }
    ctx->pc = 0x16A888u;
label_16a888:
    // 0x16a888: 0x2413ffff  addiu       $s3, $zero, -0x1
    ctx->pc = 0x16a888u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16a88c: 0x8ed00008  lw          $s0, 0x8($s6)
    ctx->pc = 0x16a88cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x16a890: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x16a890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x16a894: 0x50530001  beql        $v0, $s3, . + 4 + (0x1 << 2)
    ctx->pc = 0x16A894u;
    {
        const bool branch_taken_0x16a894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        if (branch_taken_0x16a894) {
            ctx->pc = 0x16A898u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A894u;
            // 0x16a898: 0xae12002c  sw          $s2, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A89Cu;
            goto label_16a89c;
        }
    }
    ctx->pc = 0x16A89Cu;
label_16a89c:
    // 0x16a89c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x16a89cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x16a8a0: 0x50530001  beql        $v0, $s3, . + 4 + (0x1 << 2)
    ctx->pc = 0x16A8A0u;
    {
        const bool branch_taken_0x16a8a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        if (branch_taken_0x16a8a0) {
            ctx->pc = 0x16A8A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8A0u;
            // 0x16a8a4: 0xae120024  sw          $s2, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8A8u;
            goto label_16a8a8;
        }
    }
    ctx->pc = 0x16A8A8u;
label_16a8a8:
    // 0x16a8a8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x16a8a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a8ac: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A8ACu;
    SET_GPR_U32(ctx, 31, 0x16A8B4u);
    ctx->pc = 0x16A8B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8ACu;
            // 0x16a8b0: 0x2405001e  addiu       $a1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8B4u; }
        if (ctx->pc != 0x16A8B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8B4u; }
        if (ctx->pc != 0x16A8B4u) { return; }
    }
    ctx->pc = 0x16A8B4u;
label_16a8b4:
    // 0x16a8b4: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x16a8b4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a8b8: 0x1293000e  beq         $s4, $s3, . + 4 + (0xE << 2)
    ctx->pc = 0x16A8B8u;
    {
        const bool branch_taken_0x16a8b8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 19));
        ctx->pc = 0x16A8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8B8u;
            // 0x16a8bc: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8b8) {
            ctx->pc = 0x16A8F4u;
            goto label_16a8f4;
        }
    }
    ctx->pc = 0x16A8C0u;
    // 0x16a8c0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16A8C0u;
    SET_GPR_U32(ctx, 31, 0x16A8C8u);
    ctx->pc = 0x16A8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8C0u;
            // 0x16a8c4: 0x24050037  addiu       $a1, $zero, 0x37 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8C8u; }
        if (ctx->pc != 0x16A8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A8C8u; }
        if (ctx->pc != 0x16A8C8u) { return; }
    }
    ctx->pc = 0x16A8C8u;
label_16a8c8:
    // 0x16a8c8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x16A8C8u;
    {
        const bool branch_taken_0x16a8c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a8c8) {
            ctx->pc = 0x16A8CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8C8u;
            // 0x16a8cc: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8E8u;
            goto label_16a8e8;
        }
    }
    ctx->pc = 0x16A8D0u;
    // 0x16a8d0: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x16a8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16a8d4: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x16a8d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16a8d8: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A8D8u;
    {
        const bool branch_taken_0x16a8d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a8d8) {
            ctx->pc = 0x16A8DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8D8u;
            // 0x16a8dc: 0xae14002c  sw          $s4, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8F4u;
            goto label_16a8f4;
        }
    }
    ctx->pc = 0x16A8E0u;
    // 0x16a8e0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16A8E0u;
    {
        const bool branch_taken_0x16a8e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8E0u;
            // 0x16a8e4: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8e0) {
            ctx->pc = 0x16A8F8u;
            goto label_16a8f8;
        }
    }
    ctx->pc = 0x16A8E8u;
label_16a8e8:
    // 0x16a8e8: 0x56420003  bnel        $s2, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A8E8u;
    {
        const bool branch_taken_0x16a8e8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x16a8e8) {
            ctx->pc = 0x16A8ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8E8u;
            // 0x16a8ec: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A8F8u;
            goto label_16a8f8;
        }
    }
    ctx->pc = 0x16A8F0u;
    // 0x16a8f0: 0xae14002c  sw          $s4, 0x2C($s0)
    ctx->pc = 0x16a8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 20));
label_16a8f4:
    // 0x16a8f4: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x16a8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_16a8f8:
    // 0x16a8f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16a8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a8fc: 0x1472001e  bne         $v1, $s2, . + 4 + (0x1E << 2)
    ctx->pc = 0x16A8FCu;
    {
        const bool branch_taken_0x16a8fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 18));
        ctx->pc = 0x16A900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A8FCu;
            // 0x16a900: 0xae12001c  sw          $s2, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a8fc) {
            ctx->pc = 0x16A978u;
            goto label_16a978;
        }
    }
    ctx->pc = 0x16A904u;
    // 0x16a904: 0x622000b  bltzl       $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x16A904u;
    {
        const bool branch_taken_0x16a904 = (GPR_S64(ctx, 17) < 0);
        if (branch_taken_0x16a904) {
            ctx->pc = 0x16A908u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A904u;
            // 0x16a908: 0x8ec50018  lw          $a1, 0x18($s6) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A934u;
            goto label_16a934;
        }
    }
    ctx->pc = 0x16A90Cu;
    // 0x16a90c: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x16a90cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x16a910: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x16a910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x16a914: 0x223202a  slt         $a0, $s1, $v1
    ctx->pc = 0x16a914u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x16a918: 0x222282a  slt         $a1, $s1, $v0
    ctx->pc = 0x16a918u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16a91c: 0x224180b  movn        $v1, $s1, $a0
    ctx->pc = 0x16a91cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 17));
    // 0x16a920: 0x225100b  movn        $v0, $s1, $a1
    ctx->pc = 0x16a920u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 17));
    // 0x16a924: 0x2238823  subu        $s1, $s1, $v1
    ctx->pc = 0x16a924u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x16a928: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x16a928u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x16a92c: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x16a92cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x16a930: 0x8ec50018  lw          $a1, 0x18($s6)
    ctx->pc = 0x16a930u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
label_16a934:
    // 0x16a934: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x16a934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a938: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x16a938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a93c: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16a93cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a940: 0x3c0382d  daddu       $a3, $fp, $zero
    ctx->pc = 0x16a940u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a944: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x16a944u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a948: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x16a948u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a94c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a94cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a950: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a950u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a954: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a954u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a958: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a958u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a95c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a95cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a960: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16a960u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a964: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16a964u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a968: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16a968u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a96c: 0x805aba8  j           func_16AEA0
    ctx->pc = 0x16A96Cu;
    ctx->pc = 0x16A970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A96Cu;
            // 0x16a970: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AEA0u;
    if (runtime->hasFunction(0x16AEA0u)) {
        auto targetFn = runtime->lookupFunction(0x16AEA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016AEA0_0x16aea0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16A974u;
    // 0x16a974: 0x0  nop
    ctx->pc = 0x16a974u;
    // NOP
label_16a978:
    // 0x16a978: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a978u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a97c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a97cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a980: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a980u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a984: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a984u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a988: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a988u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a98c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16a98cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a990: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16a990u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a994: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16a994u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a998: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x16a998u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a99c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16a99cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a9a0: 0x3e00008  jr          $ra
    ctx->pc = 0x16A9A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A9A0u;
            // 0x16a9a4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A878u: goto label_16a878;
            case 0x16A888u: goto label_16a888;
            case 0x16A89Cu: goto label_16a89c;
            case 0x16A8A8u: goto label_16a8a8;
            case 0x16A8B4u: goto label_16a8b4;
            case 0x16A8C8u: goto label_16a8c8;
            case 0x16A8E8u: goto label_16a8e8;
            case 0x16A8F4u: goto label_16a8f4;
            case 0x16A8F8u: goto label_16a8f8;
            case 0x16A934u: goto label_16a934;
            case 0x16A978u: goto label_16a978;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A9A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
