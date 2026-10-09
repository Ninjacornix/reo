#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177CB0
// Address: 0x177cb0 - 0x177d90
void sub_00177CB0_0x177cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177CB0_0x177cb0");
#endif

    switch (ctx->pc) {
        case 0x177cccu: goto label_177ccc;
        case 0x177cf0u: goto label_177cf0;
        default: break;
    }

    ctx->pc = 0x177cb0u;

    // 0x177cb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177cb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x177cb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177cb8: 0x240601c0  addiu       $a2, $zero, 0x1C0
    ctx->pc = 0x177cb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 448));
    // 0x177cbc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177cc0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x177cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x177cc4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x177CC4u;
    SET_GPR_U32(ctx, 31, 0x177CCCu);
    ctx->pc = 0x177CC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177CC4u;
            // 0x177cc8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CCCu; }
        if (ctx->pc != 0x177CCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CCCu; }
        if (ctx->pc != 0x177CCCu) { return; }
    }
    ctx->pc = 0x177CCCu;
label_177ccc:
    // 0x177ccc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x177cccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177cd0: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x177cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x177cd4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x177cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x177cd8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x177cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x177cdc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x177cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ce0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x177ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x177ce4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x177ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x177ce8: 0xc05df64  jal         func_177D90
    ctx->pc = 0x177CE8u;
    SET_GPR_U32(ctx, 31, 0x177CF0u);
    ctx->pc = 0x177CECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177CE8u;
            // 0x177cec: 0xae000008  sw          $zero, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177D90u;
    if (runtime->hasFunction(0x177D90u)) {
        auto targetFn = runtime->lookupFunction(0x177D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CF0u; }
        if (ctx->pc != 0x177CF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CF0u; }
        if (ctx->pc != 0x177CF0u) { return; }
    }
    ctx->pc = 0x177CF0u;
label_177cf0:
    // 0x177cf0: 0xfe000108  sd          $zero, 0x108($s0)
    ctx->pc = 0x177cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 264), GPR_U64(ctx, 0));
    // 0x177cf4: 0x3c03000f  lui         $v1, 0xF
    ctx->pc = 0x177cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)15 << 16));
    // 0x177cf8: 0x34634240  ori         $v1, $v1, 0x4240
    ctx->pc = 0x177cf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16960);
    // 0x177cfc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x177cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177d00: 0x2404412b  addiu       $a0, $zero, 0x412B
    ctx->pc = 0x177d00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16683));
    // 0x177d04: 0x3c050003  lui         $a1, 0x3
    ctx->pc = 0x177d04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)3 << 16));
    // 0x177d08: 0x34a50d40  ori         $a1, $a1, 0xD40
    ctx->pc = 0x177d08u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3392);
    // 0x177d0c: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x177d0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x177d10: 0xfe020130  sd          $v0, 0x130($s0)
    ctx->pc = 0x177d10u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 304), GPR_U64(ctx, 2));
    // 0x177d14: 0xfe040138  sd          $a0, 0x138($s0)
    ctx->pc = 0x177d14u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 312), GPR_U64(ctx, 4));
    // 0x177d18: 0xfe050148  sd          $a1, 0x148($s0)
    ctx->pc = 0x177d18u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 328), GPR_U64(ctx, 5));
    // 0x177d1c: 0xfe030170  sd          $v1, 0x170($s0)
    ctx->pc = 0x177d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 368), GPR_U64(ctx, 3));
    // 0x177d20: 0xfe060178  sd          $a2, 0x178($s0)
    ctx->pc = 0x177d20u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 6));
    // 0x177d24: 0xae0001b8  sw          $zero, 0x1B8($s0)
    ctx->pc = 0x177d24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 440), GPR_U32(ctx, 0));
    // 0x177d28: 0xfe020110  sd          $v0, 0x110($s0)
    ctx->pc = 0x177d28u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 272), GPR_U64(ctx, 2));
    // 0x177d2c: 0xfe000118  sd          $zero, 0x118($s0)
    ctx->pc = 0x177d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 280), GPR_U64(ctx, 0));
    // 0x177d30: 0xfe020120  sd          $v0, 0x120($s0)
    ctx->pc = 0x177d30u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 288), GPR_U64(ctx, 2));
    // 0x177d34: 0xfe000128  sd          $zero, 0x128($s0)
    ctx->pc = 0x177d34u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 296), GPR_U64(ctx, 0));
    // 0x177d38: 0xfe030140  sd          $v1, 0x140($s0)
    ctx->pc = 0x177d38u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 320), GPR_U64(ctx, 3));
    // 0x177d3c: 0xfe030150  sd          $v1, 0x150($s0)
    ctx->pc = 0x177d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 336), GPR_U64(ctx, 3));
    // 0x177d40: 0xfe000158  sd          $zero, 0x158($s0)
    ctx->pc = 0x177d40u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 344), GPR_U64(ctx, 0));
    // 0x177d44: 0xfe030160  sd          $v1, 0x160($s0)
    ctx->pc = 0x177d44u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 352), GPR_U64(ctx, 3));
    // 0x177d48: 0xfe000168  sd          $zero, 0x168($s0)
    ctx->pc = 0x177d48u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 360), GPR_U64(ctx, 0));
    // 0x177d4c: 0xfe000180  sd          $zero, 0x180($s0)
    ctx->pc = 0x177d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 0));
    // 0x177d50: 0xfe000188  sd          $zero, 0x188($s0)
    ctx->pc = 0x177d50u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 392), GPR_U64(ctx, 0));
    // 0x177d54: 0xae000190  sw          $zero, 0x190($s0)
    ctx->pc = 0x177d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 0));
    // 0x177d58: 0xae000194  sw          $zero, 0x194($s0)
    ctx->pc = 0x177d58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 0));
    // 0x177d5c: 0xae000198  sw          $zero, 0x198($s0)
    ctx->pc = 0x177d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 0));
    // 0x177d60: 0xae00019c  sw          $zero, 0x19C($s0)
    ctx->pc = 0x177d60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 0));
    // 0x177d64: 0xae0001a0  sw          $zero, 0x1A0($s0)
    ctx->pc = 0x177d64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 0));
    // 0x177d68: 0xae0001a4  sw          $zero, 0x1A4($s0)
    ctx->pc = 0x177d68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x177d6c: 0xae0001a8  sw          $zero, 0x1A8($s0)
    ctx->pc = 0x177d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x177d70: 0xae0001ac  sw          $zero, 0x1AC($s0)
    ctx->pc = 0x177d70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x177d74: 0xae0001b0  sw          $zero, 0x1B0($s0)
    ctx->pc = 0x177d74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 432), GPR_U32(ctx, 0));
    // 0x177d78: 0xae0001b4  sw          $zero, 0x1B4($s0)
    ctx->pc = 0x177d78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 436), GPR_U32(ctx, 0));
    // 0x177d7c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x177d7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177d80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177d80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177d84: 0x805e110  j           func_178440
    ctx->pc = 0x177D84u;
    ctx->pc = 0x177D88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177D84u;
            // 0x177d88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178440u;
    if (runtime->hasFunction(0x178440u)) {
        auto targetFn = runtime->lookupFunction(0x178440u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00178440_0x178440(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177D8Cu;
    // 0x177d8c: 0x0  nop
    ctx->pc = 0x177d8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
