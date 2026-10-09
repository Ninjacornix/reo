#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155A88
// Address: 0x155a88 - 0x155b28
void sub_00155A88_0x155a88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155A88_0x155a88");
#endif

    switch (ctx->pc) {
        case 0x155ac8u: goto label_155ac8;
        case 0x155b04u: goto label_155b04;
        default: break;
    }

    ctx->pc = 0x155a88u;

    // 0x155a88: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x155a88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x155a8c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x155a8cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155a90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155a94: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x155a94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a98: 0x1030c0  sll         $a2, $s0, 3
    ctx->pc = 0x155a98u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x155a9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x155a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x155aa0: 0xd01023  subu        $v0, $a2, $s0
    ctx->pc = 0x155aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x155aa4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x155aa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x155aa8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x155aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x155aac: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x155aacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x155ab0: 0xe2182b  sltu        $v1, $a3, $v0
    ctx->pc = 0x155ab0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x155ab4: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x155AB4u;
    {
        const bool branch_taken_0x155ab4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x155AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155AB4u;
            // 0x155ab8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155ab4) {
            ctx->pc = 0x155AE4u;
            goto label_155ae4;
        }
    }
    ctx->pc = 0x155ABCu;
    // 0x155abc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x155abcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155ac0: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x155ac0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155ac4: 0x0  nop
    ctx->pc = 0x155ac4u;
    // NOP
label_155ac8:
    // 0x155ac8: 0x2484f900  addiu       $a0, $a0, -0x700
    ctx->pc = 0x155ac8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965504));
    // 0x155acc: 0x2463fff8  addiu       $v1, $v1, -0x8
    ctx->pc = 0x155accu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967288));
    // 0x155ad0: 0xe4102b  sltu        $v0, $a3, $a0
    ctx->pc = 0x155ad0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x155ad4: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x155ad4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x155ad8: 0x0  nop
    ctx->pc = 0x155ad8u;
    // NOP
    // 0x155adc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x155ADCu;
    {
        const bool branch_taken_0x155adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155ADCu;
            // 0x155ae0: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155adc) {
            ctx->pc = 0x155AC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155ac8;
        }
    }
    ctx->pc = 0x155AE4u;
label_155ae4:
    // 0x155ae4: 0x2623003f  addiu       $v1, $s1, 0x3F
    ctx->pc = 0x155ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 63));
    // 0x155ae8: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x155ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x155aec: 0x628824  and         $s1, $v1, $v0
    ctx->pc = 0x155aecu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x155af0: 0xd03023  subu        $a2, $a2, $s0
    ctx->pc = 0x155af0u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x155af4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x155af4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155af8: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x155af8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x155afc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x155AFCu;
    SET_GPR_U32(ctx, 31, 0x155B04u);
    ctx->pc = 0x155B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155AFCu;
            // 0x155b00: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155B04u; }
        if (ctx->pc != 0x155B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155B04u; }
        if (ctx->pc != 0x155B04u) { return; }
    }
    ctx->pc = 0x155B04u;
label_155b04:
    // 0x155b04: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x155b04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x155b08: 0x24634c10  addiu       $v1, $v1, 0x4C10
    ctx->pc = 0x155b08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19472));
    // 0x155b0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x155b0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155b10: 0xac710044  sw          $s1, 0x44($v1)
    ctx->pc = 0x155b10u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 68), GPR_U32(ctx, 17));
    // 0x155b14: 0xac700040  sw          $s0, 0x40($v1)
    ctx->pc = 0x155b14u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 16));
    // 0x155b18: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155b18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155b1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155b1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155b20: 0x3e00008  jr          $ra
    ctx->pc = 0x155B20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155B20u;
            // 0x155b24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155AC8u: goto label_155ac8;
            case 0x155AE4u: goto label_155ae4;
            case 0x155B04u: goto label_155b04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155B28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
