#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166A88
// Address: 0x166a88 - 0x166b40
void sub_00166A88_0x166a88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166A88_0x166a88");
#endif

    switch (ctx->pc) {
        case 0x166adcu: goto label_166adc;
        case 0x166b08u: goto label_166b08;
        default: break;
    }

    ctx->pc = 0x166a88u;

    // 0x166a88: 0x810c0  sll         $v0, $t0, 3
    ctx->pc = 0x166a88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x166a8c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x166a8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x166a90: 0x481023  subu        $v0, $v0, $t0
    ctx->pc = 0x166a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x166a94: 0x81880  sll         $v1, $t0, 2
    ctx->pc = 0x166a94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x166a98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166a9c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166aa0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166aa4: 0xc38821  addu        $s1, $a2, $v1
    ctx->pc = 0x166aa4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x166aa8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x166aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x166aac: 0xe39021  addu        $s2, $a3, $v1
    ctx->pc = 0x166aacu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x166ab0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x166ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x166ab4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x166ab4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166ab8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x166ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x166abc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x166abcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x166ac0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166ac4: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x166ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x166ac8: 0xa28021  addu        $s0, $a1, $v0
    ctx->pc = 0x166ac8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x166acc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x166accu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x166ad0: 0x4302b  sltu        $a2, $zero, $a0
    ctx->pc = 0x166ad0u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x166ad4: 0xc059b2e  jal         func_166CB8
    ctx->pc = 0x166AD4u;
    SET_GPR_U32(ctx, 31, 0x166ADCu);
    ctx->pc = 0x166AD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166AD4u;
            // 0x166ad8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166CB8u;
    if (runtime->hasFunction(0x166CB8u)) {
        auto targetFn = runtime->lookupFunction(0x166CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166ADCu; }
        if (ctx->pc != 0x166ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166CB8_0x166cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166ADCu; }
        if (ctx->pc != 0x166ADCu) { return; }
    }
    ctx->pc = 0x166ADCu;
label_166adc:
    // 0x166adc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x166adcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x166ae0: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x166ae0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x166ae4: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x166ae4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x166ae8: 0x266214e0  addiu       $v0, $s3, 0x14E0
    ctx->pc = 0x166ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 5344));
    // 0x166aec: 0x26731a44  addiu       $s3, $s3, 0x1A44
    ctx->pc = 0x166aecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 6724));
    // 0x166af0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x166af0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x166af4: 0xae040004  sw          $a0, 0x4($s0)
    ctx->pc = 0x166af4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 4));
    // 0x166af8: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x166af8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x166afc: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x166afcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x166b00: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x166b00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x166b04: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x166b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_166b08:
    // 0x166b08: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x166b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x166b0c: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x166b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x166b10: 0x0  nop
    ctx->pc = 0x166b10u;
    // NOP
    // 0x166b14: 0x0  nop
    ctx->pc = 0x166b14u;
    // NOP
    // 0x166b18: 0x0  nop
    ctx->pc = 0x166b18u;
    // NOP
    // 0x166b1c: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x166B1Cu;
    {
        const bool branch_taken_0x166b1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x166B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166B1Cu;
            // 0x166b20: 0x2673ffa4  addiu       $s3, $s3, -0x5C (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967204));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166b1c) {
            ctx->pc = 0x166B08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_166b08;
        }
    }
    ctx->pc = 0x166B24u;
    // 0x166b24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166b24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166b28: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166b28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166b2c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x166b2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166b30: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x166b30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x166b34: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x166b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x166b38: 0x3e00008  jr          $ra
    ctx->pc = 0x166B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166B38u;
            // 0x166b3c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166ADCu: goto label_166adc;
            case 0x166B08u: goto label_166b08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166B40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
