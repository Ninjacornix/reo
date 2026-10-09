#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173EA8
// Address: 0x173ea8 - 0x173f28
void sub_00173EA8_0x173ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173EA8_0x173ea8");
#endif

    switch (ctx->pc) {
        case 0x173eccu: goto label_173ecc;
        default: break;
    }

    ctx->pc = 0x173ea8u;

    // 0x173ea8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173eac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173eb0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x173eb0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173eb4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173eb8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x173eb8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173ebc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x173ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x173ec0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x173ec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173ec4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173EC4u;
    SET_GPR_U32(ctx, 31, 0x173ECCu);
    ctx->pc = 0x173EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173EC4u;
            // 0x173ec8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173ECCu; }
        if (ctx->pc != 0x173ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173ECCu; }
        if (ctx->pc != 0x173ECCu) { return; }
    }
    ctx->pc = 0x173ECCu;
label_173ecc:
    // 0x173ecc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173eccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173ed0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x173ed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173ed4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x173ed4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173ed8: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x173ed8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173edc: 0x34a50135  ori         $a1, $a1, 0x135
    ctx->pc = 0x173edcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)309);
    // 0x173ee0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x173EE0u;
    {
        const bool branch_taken_0x173ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173EE0u;
            // 0x173ee4: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173ee0) {
            ctx->pc = 0x173F08u;
            goto label_173f08;
        }
    }
    ctx->pc = 0x173EE8u;
    // 0x173ee8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173ee8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173eec: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173eecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173ef0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173ef0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173ef4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x173ef4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173ef8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x173ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173efc: 0x805a704  j           func_169C10
    ctx->pc = 0x173EFCu;
    ctx->pc = 0x173F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173EFCu;
            // 0x173f00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173F04u;
    // 0x173f04: 0x0  nop
    ctx->pc = 0x173f04u;
    // NOP
label_173f08:
    // 0x173f08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173f08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173f0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x173f0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173f10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173f10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173f14: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x173f14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173f18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x173f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173f1c: 0x805def8  j           func_177BE0
    ctx->pc = 0x173F1Cu;
    ctx->pc = 0x173F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F1Cu;
            // 0x173f20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177BE0_0x177be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173F24u;
    // 0x173f24: 0x0  nop
    ctx->pc = 0x173f24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
