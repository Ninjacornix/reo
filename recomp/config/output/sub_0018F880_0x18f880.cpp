#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F880
// Address: 0x18f880 - 0x18f970
void sub_0018F880_0x18f880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F880_0x18f880");
#endif

    switch (ctx->pc) {
        case 0x18f8bcu: goto label_18f8bc;
        case 0x18f8c8u: goto label_18f8c8;
        case 0x18f8e0u: goto label_18f8e0;
        case 0x18f8fcu: goto label_18f8fc;
        case 0x18f94cu: goto label_18f94c;
        default: break;
    }

    ctx->pc = 0x18f880u;

    // 0x18f880: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x18f880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x18f884: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x18f884u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x18f888: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x18f888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x18f88c: 0x41180  sll         $v0, $a0, 6
    ctx->pc = 0x18f88cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x18f890: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18f890u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18f894: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x18f894u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x18f898: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18f898u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18f89c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x18f89cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f8a0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18f8a0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18f8a4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x18f8a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f8a8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18f8a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18f8ac: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x18f8acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f8b0: 0x100802d  daddu       $s0, $t0, $zero
    ctx->pc = 0x18f8b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f8b4: 0xc063e5c  jal         func_18F970
    ctx->pc = 0x18F8B4u;
    SET_GPR_U32(ctx, 31, 0x18F8BCu);
    ctx->pc = 0x18F8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F8B4u;
            // 0x18f8b8: 0x412021  addu        $a0, $v0, $at (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F970u;
    if (runtime->hasFunction(0x18F970u)) {
        auto targetFn = runtime->lookupFunction(0x18F970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8BCu; }
        if (ctx->pc != 0x18F8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F970_0x18f970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8BCu; }
        if (ctx->pc != 0x18F8BCu) { return; }
    }
    ctx->pc = 0x18F8BCu;
label_18f8bc:
    // 0x18f8bc: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x18f8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x18f8c0: 0xc063df8  jal         func_18F7E0
    ctx->pc = 0x18F8C0u;
    SET_GPR_U32(ctx, 31, 0x18F8C8u);
    ctx->pc = 0x18F8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F8C0u;
            // 0x18f8c4: 0x34443f00  ori         $a0, $v0, 0x3F00 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F7E0u;
    if (runtime->hasFunction(0x18F7E0u)) {
        auto targetFn = runtime->lookupFunction(0x18F7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8C8u; }
        if (ctx->pc != 0x18F8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F7E0_0x18f7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8C8u; }
        if (ctx->pc != 0x18F8C8u) { return; }
    }
    ctx->pc = 0x18F8C8u;
label_18f8c8:
    // 0x18f8c8: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x18f8c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x18f8cc: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f8ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f8d0: 0x24844d40  addiu       $a0, $a0, 0x4D40
    ctx->pc = 0x18f8d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19776));
    // 0x18f8d4: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x18f8d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x18f8d8: 0xc0644a0  jal         func_191280
    ctx->pc = 0x18F8D8u;
    SET_GPR_U32(ctx, 31, 0x18F8E0u);
    ctx->pc = 0x18F8DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F8D8u;
            // 0x18f8dc: 0x34463f80  ori         $a2, $v0, 0x3F80 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16256);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8E0u; }
        if (ctx->pc != 0x18F8E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8E0u; }
        if (ctx->pc != 0x18F8E0u) { return; }
    }
    ctx->pc = 0x18F8E0u;
label_18f8e0:
    // 0x18f8e0: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f8e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f8e4: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x18f8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x18f8e8: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x18f8e8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x18f8ec: 0x24844d80  addiu       $a0, $a0, 0x4D80
    ctx->pc = 0x18f8ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19840));
    // 0x18f8f0: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x18f8f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x18f8f4: 0xc0644a0  jal         func_191280
    ctx->pc = 0x18F8F4u;
    SET_GPR_U32(ctx, 31, 0x18F8FCu);
    ctx->pc = 0x18F8F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F8F4u;
            // 0x18f8f8: 0x24c64dc0  addiu       $a2, $a2, 0x4DC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8FCu; }
        if (ctx->pc != 0x18F8FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F8FCu; }
        if (ctx->pc != 0x18F8FCu) { return; }
    }
    ctx->pc = 0x18F8FCu;
label_18f8fc:
    // 0x18f8fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18f8fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18f900: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x18f900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x18f904: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x18F904u;
    {
        const bool branch_taken_0x18f904 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18F908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F904u;
            // 0x18f908: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f904) {
            ctx->pc = 0x18F938u;
            goto label_18f938;
        }
    }
    ctx->pc = 0x18F90Cu;
    // 0x18f90c: 0x6410003  bgez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x18F90Cu;
    {
        const bool branch_taken_0x18f90c = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x18F910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F90Cu;
            // 0x18f910: 0x121043  sra         $v0, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f90c) {
            ctx->pc = 0x18F91Cu;
            goto label_18f91c;
        }
    }
    ctx->pc = 0x18F914u;
    // 0x18f914: 0x26420001  addiu       $v0, $s2, 0x1
    ctx->pc = 0x18f914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x18f918: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18f918u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18f91c:
    // 0x18f91c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x18f91cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f920: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18F920u;
    {
        const bool branch_taken_0x18f920 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x18F924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F920u;
            // 0x18f924: 0x101043  sra         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f920) {
            ctx->pc = 0x18F930u;
            goto label_18f930;
        }
    }
    ctx->pc = 0x18F928u;
    // 0x18f928: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x18f928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x18f92c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18f92cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18f930:
    // 0x18f930: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x18f930u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f934: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x18f934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_18f938:
    // 0x18f938: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x18f938u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f93c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18f93cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f940: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x18f940u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f944: 0xc065d24  jal         func_197490
    ctx->pc = 0x18F944u;
    SET_GPR_U32(ctx, 31, 0x18F94Cu);
    ctx->pc = 0x18F948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F944u;
            // 0x18f948: 0x24080002  addiu       $t0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197490u;
    if (runtime->hasFunction(0x197490u)) {
        auto targetFn = runtime->lookupFunction(0x197490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F94Cu; }
        if (ctx->pc != 0x18F94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197490_0x197490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F94Cu; }
        if (ctx->pc != 0x18F94Cu) { return; }
    }
    ctx->pc = 0x18F94Cu;
label_18f94c:
    // 0x18f94c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x18f94cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18f950: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18f950u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18f954: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18f954u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18f958: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18f958u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18f95c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18f95cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18f960: 0x3e00008  jr          $ra
    ctx->pc = 0x18F960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18F964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F960u;
            // 0x18f964: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F8BCu: goto label_18f8bc;
            case 0x18F8C8u: goto label_18f8c8;
            case 0x18F8E0u: goto label_18f8e0;
            case 0x18F8FCu: goto label_18f8fc;
            case 0x18F91Cu: goto label_18f91c;
            case 0x18F930u: goto label_18f930;
            case 0x18F938u: goto label_18f938;
            case 0x18F94Cu: goto label_18f94c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F968u;
    // 0x18f968: 0x0  nop
    ctx->pc = 0x18f968u;
    // NOP
    // 0x18f96c: 0x0  nop
    ctx->pc = 0x18f96cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
