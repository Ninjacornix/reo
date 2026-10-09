#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140BF0
// Address: 0x140bf0 - 0x140dd0
void sub_00140BF0_0x140bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140BF0_0x140bf0");
#endif

    switch (ctx->pc) {
        case 0x140c54u: goto label_140c54;
        case 0x140d08u: goto label_140d08;
        default: break;
    }

    ctx->pc = 0x140bf0u;

    // 0x140bf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140bf4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x140bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x140bf8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140bfc: 0x24a54600  addiu       $a1, $a1, 0x4600
    ctx->pc = 0x140bfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17920));
    // 0x140c00: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140c00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x140c04: 0x24040023  addiu       $a0, $zero, 0x23
    ctx->pc = 0x140c04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x140c08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140c0c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x140c0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140c10: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140c10u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c14: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140c14u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c18: 0x804e518  j           func_139460
    ctx->pc = 0x140C18u;
    ctx->pc = 0x140C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140C18u;
            // 0x140c1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140C20u;
    // 0x140c20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140c24: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x140c24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x140c28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140c2c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140c2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140c30: 0x24a54600  addiu       $a1, $a1, 0x4600
    ctx->pc = 0x140c30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17920));
    // 0x140c34: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140c34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140c38: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140c3c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140c3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c40: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140c40u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x140c44: 0x24040024  addiu       $a0, $zero, 0x24
    ctx->pc = 0x140c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x140c48: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x140c48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140c4c: 0xc04e518  jal         func_139460
    ctx->pc = 0x140C4Cu;
    SET_GPR_U32(ctx, 31, 0x140C54u);
    ctx->pc = 0x140C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140C4Cu;
            // 0x140c50: 0x24080004  addiu       $t0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140C54u; }
        if (ctx->pc != 0x140C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140C54u; }
        if (ctx->pc != 0x140C54u) { return; }
    }
    ctx->pc = 0x140C54u;
label_140c54:
    // 0x140c54: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x140c54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x140c58: 0x8e07000c  lw          $a3, 0xC($s0)
    ctx->pc = 0x140c58u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x140c5c: 0x246345c0  addiu       $v1, $v1, 0x45C0
    ctx->pc = 0x140c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17856));
    // 0x140c60: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x140c60u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140c64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x140c64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c68: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x140c68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x140c6c: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x140c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x140c70: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140c70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140c74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140c74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140c78: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x140c78u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
    // 0x140c7c: 0xac640004  sw          $a0, 0x4($v1)
    ctx->pc = 0x140c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x140c80: 0xac650008  sw          $a1, 0x8($v1)
    ctx->pc = 0x140c80u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 5));
    // 0x140c84: 0xac67000c  sw          $a3, 0xC($v1)
    ctx->pc = 0x140c84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 7));
    // 0x140c88: 0x3e00008  jr          $ra
    ctx->pc = 0x140C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140C88u;
            // 0x140c8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140C54u: goto label_140c54;
            case 0x140D08u: goto label_140d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140C90u;
    // 0x140c90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140c94: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x140c94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x140c98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140c9c: 0x24a54600  addiu       $a1, $a1, 0x4600
    ctx->pc = 0x140c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17920));
    // 0x140ca0: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x140ca4: 0x24040025  addiu       $a0, $zero, 0x25
    ctx->pc = 0x140ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x140ca8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140ca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140cac: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x140cacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140cb0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140cb0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cb4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140cb4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cb8: 0x804e518  j           func_139460
    ctx->pc = 0x140CB8u;
    ctx->pc = 0x140CBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140CB8u;
            // 0x140cbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140CC0u;
    // 0x140cc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140cc4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140cc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140ccc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140cccu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140cd0: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140cd4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140cd8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x140cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x140cdc: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140cdcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140ce0: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140ce4: 0x24040026  addiu       $a0, $zero, 0x26
    ctx->pc = 0x140ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
    // 0x140ce8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140cec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140cecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cf0: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140cf4: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140cf4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140cf8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x140cf8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cfc: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140cfcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d00: 0xc04e518  jal         func_139460
    ctx->pc = 0x140D00u;
    SET_GPR_U32(ctx, 31, 0x140D08u);
    ctx->pc = 0x140D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140D00u;
            // 0x140d04: 0x24080002  addiu       $t0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140D08u; }
        if (ctx->pc != 0x140D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140D08u; }
        if (ctx->pc != 0x140D08u) { return; }
    }
    ctx->pc = 0x140D08u;
label_140d08:
    // 0x140d08: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x140d08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140d0c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x140d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x140d10: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x140d10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x140d14: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x140d14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x140d18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140d18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140d1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140d1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140d20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140d20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140d24: 0x3e00008  jr          $ra
    ctx->pc = 0x140D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140D24u;
            // 0x140d28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140C54u: goto label_140c54;
            case 0x140D08u: goto label_140d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140D2Cu;
    // 0x140d2c: 0x0  nop
    ctx->pc = 0x140d2cu;
    // NOP
    // 0x140d30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140d34: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x140d34u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140d3c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140d40: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140d44: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x140d44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x140d48: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x140d48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x140d4c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140d4cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d50: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140d50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140d54: 0x24040027  addiu       $a0, $zero, 0x27
    ctx->pc = 0x140d54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x140d58: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140d58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140d5c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140d5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d60: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x140d60u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x140d64: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140d64u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d68: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140d68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140d6c: 0x8d230004  lw          $v1, 0x4($t1)
    ctx->pc = 0x140d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x140d70: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x140d70u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x140d74: 0x804e518  j           func_139460
    ctx->pc = 0x140D74u;
    ctx->pc = 0x140D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140D74u;
            // 0x140d78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140D7Cu;
    // 0x140d7c: 0x0  nop
    ctx->pc = 0x140d7cu;
    // NOP
    // 0x140d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140d84: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x140d84u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140d8c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140d90: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140d94: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x140d94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x140d98: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x140d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x140d9c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140d9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140da0: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140da0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140da4: 0x24040028  addiu       $a0, $zero, 0x28
    ctx->pc = 0x140da4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x140da8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140da8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140dac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140dacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140db0: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x140db0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x140db4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140db4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140db8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140db8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140dbc: 0x8d230004  lw          $v1, 0x4($t1)
    ctx->pc = 0x140dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x140dc0: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x140dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x140dc4: 0x804e518  j           func_139460
    ctx->pc = 0x140DC4u;
    ctx->pc = 0x140DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140DC4u;
            // 0x140dc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140DCCu;
    // 0x140dcc: 0x0  nop
    ctx->pc = 0x140dccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
