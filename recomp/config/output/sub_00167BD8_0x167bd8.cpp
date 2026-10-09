#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167BD8
// Address: 0x167bd8 - 0x167ca0
void sub_00167BD8_0x167bd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167BD8_0x167bd8");
#endif

    switch (ctx->pc) {
        case 0x167c7cu: goto label_167c7c;
        default: break;
    }

    ctx->pc = 0x167bd8u;

    // 0x167bd8: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167bdc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x167bdcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x167be0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167be4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x167be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x167be8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167be8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167bec: 0x24881140  addiu       $t0, $a0, 0x1140
    ctx->pc = 0x167becu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x167bf0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167bf4: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x167bf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167bf8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167bfc: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x167bfcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x167c00: 0x8d030004  lw          $v1, 0x4($t0)
    ctx->pc = 0x167c00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x167c04: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x167C04u;
    {
        const bool branch_taken_0x167c04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167C04u;
            // 0x167c08: 0x2406000b  addiu       $a2, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167c04) {
            ctx->pc = 0x167C20u;
            goto label_167c20;
        }
    }
    ctx->pc = 0x167C0Cu;
    // 0x167c0c: 0x8d05004c  lw          $a1, 0x4C($t0)
    ctx->pc = 0x167c0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 76)));
    // 0x167c10: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x167c10u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x167c14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167c18: 0x805def8  j           func_177BE0
    ctx->pc = 0x167C18u;
    ctx->pc = 0x167C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167C18u;
            // 0x167c1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177BE0_0x177be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x167C20u;
label_167c20:
    // 0x167c20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x167c20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167c24: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167c24u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c28: 0x3e00008  jr          $ra
    ctx->pc = 0x167C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167C28u;
            // 0x167c2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167C20u: goto label_167c20;
            case 0x167C7Cu: goto label_167c7c;
            case 0x167C80u: goto label_167c80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167C30u;
    // 0x167c30: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167c34: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x167c34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x167c38: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167c38u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167c3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x167c3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x167c40: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167c40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167c44: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x167c44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c48: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167c4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x167c4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c50: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x167c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x167c54: 0x26081140  addiu       $t0, $s0, 0x1140
    ctx->pc = 0x167c54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 4416));
    // 0x167c58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167c58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167c5c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x167c5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c60: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x167c60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x167c64: 0x8d030004  lw          $v1, 0x4($t0)
    ctx->pc = 0x167c64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x167c68: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x167C68u;
    {
        const bool branch_taken_0x167c68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167C68u;
            // 0x167c6c: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167c68) {
            ctx->pc = 0x167C80u;
            goto label_167c80;
        }
    }
    ctx->pc = 0x167C70u;
    // 0x167c70: 0x8d05004c  lw          $a1, 0x4C($t0)
    ctx->pc = 0x167c70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 76)));
    // 0x167c74: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x167C74u;
    SET_GPR_U32(ctx, 31, 0x167C7Cu);
    ctx->pc = 0x167C78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167C74u;
            // 0x167c78: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167C7Cu; }
        if (ctx->pc != 0x167C7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167C7Cu; }
        if (ctx->pc != 0x167C7Cu) { return; }
    }
    ctx->pc = 0x167C7Cu;
label_167c7c:
    // 0x167c7c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x167c7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_167c80:
    // 0x167c80: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x167c80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167c84: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x167c84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167c88: 0xae030044  sw          $v1, 0x44($s0)
    ctx->pc = 0x167c88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 3));
    // 0x167c8c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x167c8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167c90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x167c90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167c94: 0x3e00008  jr          $ra
    ctx->pc = 0x167C94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167C94u;
            // 0x167c98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167C20u: goto label_167c20;
            case 0x167C7Cu: goto label_167c7c;
            case 0x167C80u: goto label_167c80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167C9Cu;
    // 0x167c9c: 0x0  nop
    ctx->pc = 0x167c9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
