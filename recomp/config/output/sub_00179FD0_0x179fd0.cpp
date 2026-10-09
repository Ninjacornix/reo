#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179FD0
// Address: 0x179fd0 - 0x17a040
void sub_00179FD0_0x179fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179FD0_0x179fd0");
#endif

    switch (ctx->pc) {
        case 0x179ff4u: goto label_179ff4;
        case 0x17a008u: goto label_17a008;
        default: break;
    }

    ctx->pc = 0x179fd0u;

    // 0x179fd0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179fd4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179fd8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179fd8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179fdc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179fdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179fe0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179fe4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179fe8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179fec: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179FECu;
    SET_GPR_U32(ctx, 31, 0x179FF4u);
    ctx->pc = 0x179FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179FECu;
            // 0x179ff0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FF4u; }
        if (ctx->pc != 0x179FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FF4u; }
        if (ctx->pc != 0x179FF4u) { return; }
    }
    ctx->pc = 0x179FF4u;
label_179ff4:
    // 0x179ff4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179ff4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ff8: 0x1220000b  beqz        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x179FF8u;
    {
        const bool branch_taken_0x179ff8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FF8u;
            // 0x179ffc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ff8) {
            ctx->pc = 0x17A028u;
            goto label_17a028;
        }
    }
    ctx->pc = 0x17A000u;
    // 0x17a000: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A000u;
    SET_GPR_U32(ctx, 31, 0x17A008u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A008u; }
        if (ctx->pc != 0x17A008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A008u; }
        if (ctx->pc != 0x17A008u) { return; }
    }
    ctx->pc = 0x17A008u;
label_17a008:
    // 0x17a008: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x17a008u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x17a00c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17A00Cu;
    {
        const bool branch_taken_0x17a00c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A00Cu;
            // 0x17a010: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a00c) {
            ctx->pc = 0x17A028u;
            goto label_17a028;
        }
    }
    ctx->pc = 0x17A014u;
    // 0x17a014: 0x9623001a  lhu         $v1, 0x1A($s1)
    ctx->pc = 0x17a014u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x17a018: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a018u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a01c: 0x3864ffff  xori        $a0, $v1, 0xFFFF
    ctx->pc = 0x17a01cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)65535);
    // 0x17a020: 0x4180a  movz        $v1, $zero, $a0
    ctx->pc = 0x17a020u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x17a024: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a024u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a028:
    // 0x17a028: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a028u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a02c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a02cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a030: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a030u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a034: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a038: 0x3e00008  jr          $ra
    ctx->pc = 0x17A038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A038u;
            // 0x17a03c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
