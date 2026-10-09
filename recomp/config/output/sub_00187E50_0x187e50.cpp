#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187E50
// Address: 0x187e50 - 0x187ff8
void sub_00187E50_0x187e50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187E50_0x187e50");
#endif

    switch (ctx->pc) {
        case 0x187ea4u: goto label_187ea4;
        case 0x187ee4u: goto label_187ee4;
        case 0x187f04u: goto label_187f04;
        case 0x187f78u: goto label_187f78;
        case 0x187f88u: goto label_187f88;
        case 0x187f9cu: goto label_187f9c;
        case 0x187fc0u: goto label_187fc0;
        default: break;
    }

    ctx->pc = 0x187e50u;

    // 0x187e50: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x187e50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x187e54: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187e54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x187e58: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x187e58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x187e5c: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x187e5cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187e60: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x187e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x187e64: 0x1688c0  sll         $s1, $s6, 3
    ctx->pc = 0x187e64u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 22), 3));
    // 0x187e68: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x187e68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x187e6c: 0x2454b8c8  addiu       $s4, $v0, -0x4738
    ctx->pc = 0x187e6cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x187e70: 0x2361023  subu        $v0, $s1, $s6
    ctx->pc = 0x187e70u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 22)));
    // 0x187e74: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x187e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x187e78: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x187e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x187e7c: 0x26830004  addiu       $v1, $s4, 0x4
    ctx->pc = 0x187e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
    // 0x187e80: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x187e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x187e84: 0x29080  sll         $s2, $v0, 2
    ctx->pc = 0x187e84u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x187e88: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x187e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x187e8c: 0x243f021  addu        $fp, $s2, $v1
    ctx->pc = 0x187e8cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x187e90: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x187e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x187e94: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x187e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x187e98: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x187e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x187e9c: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x187E9Cu;
    SET_GPR_U32(ctx, 31, 0x187EA4u);
    ctx->pc = 0x187EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187E9Cu;
            // 0x187ea0: 0x8fc40000  lw          $a0, 0x0($fp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187EA4u; }
        if (ctx->pc != 0x187EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187EA4u; }
        if (ctx->pc != 0x187EA4u) { return; }
    }
    ctx->pc = 0x187EA4u;
label_187ea4:
    // 0x187ea4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x187ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x187ea8: 0x54430003  bnel        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x187EA8u;
    {
        const bool branch_taken_0x187ea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x187ea8) {
            ctx->pc = 0x187EACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187EA8u;
            // 0x187eac: 0x26820008  addiu       $v0, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187EB8u;
            goto label_187eb8;
        }
    }
    ctx->pc = 0x187EB0u;
    // 0x187eb0: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x187EB0u;
    {
        const bool branch_taken_0x187eb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187EB0u;
            // 0x187eb4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187eb0) {
            ctx->pc = 0x187FC4u;
            goto label_187fc4;
        }
    }
    ctx->pc = 0x187EB8u;
label_187eb8:
    // 0x187eb8: 0x242a821  addu        $s5, $s2, $v0
    ctx->pc = 0x187eb8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x187ebc: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x187ebcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x187ec0: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x187EC0u;
    {
        const bool branch_taken_0x187ec0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x187EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187EC0u;
            // 0x187ec4: 0x2682000c  addiu       $v0, $s4, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187ec0) {
            ctx->pc = 0x187ED8u;
            goto label_187ed8;
        }
    }
    ctx->pc = 0x187EC8u;
    // 0x187ec8: 0x2429821  addu        $s3, $s2, $v0
    ctx->pc = 0x187ec8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x187ecc: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x187eccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x187ed0: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x187ED0u;
    {
        const bool branch_taken_0x187ed0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x187ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187ED0u;
            // 0x187ed4: 0x3c170029  lui         $s7, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187ed0) {
            ctx->pc = 0x187EF0u;
            goto label_187ef0;
        }
    }
    ctx->pc = 0x187ED8u;
label_187ed8:
    // 0x187ed8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x187ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x187edc: 0xc045a12  jal         func_116848
    ctx->pc = 0x187EDCu;
    SET_GPR_U32(ctx, 31, 0x187EE4u);
    ctx->pc = 0x187EE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187EDCu;
            // 0x187ee0: 0x24841828  addiu       $a0, $a0, 0x1828 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187EE4u; }
        if (ctx->pc != 0x187EE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187EE4u; }
        if (ctx->pc != 0x187EE4u) { return; }
    }
    ctx->pc = 0x187EE4u;
label_187ee4:
    // 0x187ee4: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x187EE4u;
    {
        const bool branch_taken_0x187ee4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187EE4u;
            // 0x187ee8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187ee4) {
            ctx->pc = 0x187FC4u;
            goto label_187fc4;
        }
    }
    ctx->pc = 0x187EECu;
    // 0x187eec: 0x0  nop
    ctx->pc = 0x187eecu;
    // NOP
label_187ef0:
    // 0x187ef0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187ef0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187ef4: 0x26f0b900  addiu       $s0, $s7, -0x4700
    ctx->pc = 0x187ef4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949120));
    // 0x187ef8: 0x24062080  addiu       $a2, $zero, 0x2080
    ctx->pc = 0x187ef8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x187efc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x187EFCu;
    SET_GPR_U32(ctx, 31, 0x187F04u);
    ctx->pc = 0x187F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187EFCu;
            // 0x187f00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F04u; }
        if (ctx->pc != 0x187F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F04u; }
        if (ctx->pc != 0x187F04u) { return; }
    }
    ctx->pc = 0x187F04u;
label_187f04:
    // 0x187f04: 0x2921821  addu        $v1, $s4, $s2
    ctx->pc = 0x187f04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x187f08: 0x8e670000  lw          $a3, 0x0($s3)
    ctx->pc = 0x187f08u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x187f0c: 0x3c0982d  daddu       $s3, $fp, $zero
    ctx->pc = 0x187f0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187f10: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x187f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x187f14: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x187f14u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187f18: 0x8ea50000  lw          $a1, 0x0($s5)
    ctx->pc = 0x187f18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x187f1c: 0x3c150018  lui         $s5, 0x18
    ctx->pc = 0x187f1cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)24 << 16));
    // 0x187f20: 0x47001a  div         $zero, $v0, $a3
    ctx->pc = 0x187f20u;
    { int32_t divisor = GPR_S32(ctx, 7);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x187f24: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x187f24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x187f28: 0xae07000c  sw          $a3, 0xC($s0)
    ctx->pc = 0x187f28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 7));
    // 0x187f2c: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x187f2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x187f30: 0xae050008  sw          $a1, 0x8($s0)
    ctx->pc = 0x187f30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x187f34: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187f34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187f38: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x187F38u;
    {
        const bool branch_taken_0x187f38 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x187f38) {
            ctx->pc = 0x187F3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187F38u;
            // 0x187f3c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x187F40u;
            goto label_187f40;
        }
    }
    ctx->pc = 0x187F40u;
label_187f40:
    // 0x187f40: 0x2484d980  addiu       $a0, $a0, -0x2680
    ctx->pc = 0x187f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957440));
    // 0x187f44: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x187f44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x187f48: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x187f48u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x187f4c: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x187f4cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187f50: 0x1812  mflo        $v1
    ctx->pc = 0x187f50u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x187f54: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x187f54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x187f58: 0x2463fffe  addiu       $v1, $v1, -0x2
    ctx->pc = 0x187f58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967294));
    // 0x187f5c: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x187f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x187f60: 0x8d020014  lw          $v0, 0x14($t0)
    ctx->pc = 0x187f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 20)));
    // 0x187f64: 0xae030018  sw          $v1, 0x18($s0)
    ctx->pc = 0x187f64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 3));
    // 0x187f68: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x187f68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x187f6c: 0x24022080  addiu       $v0, $zero, 0x2080
    ctx->pc = 0x187f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x187f70: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x187F70u;
    SET_GPR_U32(ctx, 31, 0x187F78u);
    ctx->pc = 0x187F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187F70u;
            // 0x187f74: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F78u; }
        if (ctx->pc != 0x187F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F78u; }
        if (ctx->pc != 0x187F78u) { return; }
    }
    ctx->pc = 0x187F78u;
label_187f78:
    // 0x187f78: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x187f78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x187f7c: 0xae43fd24  sw          $v1, -0x2DC($s2)
    ctx->pc = 0x187f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294966564), GPR_U32(ctx, 3));
    // 0x187f80: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x187f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x187f84: 0x0  nop
    ctx->pc = 0x187f84u;
    // NOP
label_187f88:
    // 0x187f88: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x187f88u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187f8c: 0x8e45fd24  lw          $a1, -0x2DC($s2)
    ctx->pc = 0x187f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294966564)));
    // 0x187f90: 0x26e7b900  addiu       $a3, $s7, -0x4700
    ctx->pc = 0x187f90u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949120));
    // 0x187f94: 0xc062560  jal         func_189580
    ctx->pc = 0x187F94u;
    SET_GPR_U32(ctx, 31, 0x187F9Cu);
    ctx->pc = 0x187F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187F94u;
            // 0x187f98: 0x26a87808  addiu       $t0, $s5, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 21), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F9Cu; }
        if (ctx->pc != 0x187F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187F9Cu; }
        if (ctx->pc != 0x187F9Cu) { return; }
    }
    ctx->pc = 0x187F9Cu;
label_187f9c:
    // 0x187f9c: 0x5454fffa  bnel        $v0, $s4, . + 4 + (-0x6 << 2)
    ctx->pc = 0x187F9Cu;
    {
        const bool branch_taken_0x187f9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0x187f9c) {
            ctx->pc = 0x187FA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187F9Cu;
            // 0x187fa0: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187F88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187f88;
        }
    }
    ctx->pc = 0x187FA4u;
    // 0x187fa4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x187fa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x187fa8: 0x2361023  subu        $v0, $s1, $s6
    ctx->pc = 0x187fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 22)));
    // 0x187fac: 0x2483b8c8  addiu       $v1, $a0, -0x4738
    ctx->pc = 0x187facu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x187fb0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x187fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x187fb4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x187fb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187fb8: 0xc061db2  jal         func_1876C8
    ctx->pc = 0x187FB8u;
    SET_GPR_U32(ctx, 31, 0x187FC0u);
    ctx->pc = 0x187FBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187FB8u;
            // 0x187fbc: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1876C8u;
    if (runtime->hasFunction(0x1876C8u)) {
        auto targetFn = runtime->lookupFunction(0x1876C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187FC0u; }
        if (ctx->pc != 0x187FC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187FC0u; }
        if (ctx->pc != 0x187FC0u) { return; }
    }
    ctx->pc = 0x187FC0u;
label_187fc0:
    // 0x187fc0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x187fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
label_187fc4:
    // 0x187fc4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x187fc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187fc8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x187fc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x187fcc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x187fccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187fd0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x187fd0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x187fd4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x187fd4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187fd8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x187fd8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x187fdc: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x187fdcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x187fe0: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x187fe0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x187fe4: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x187fe4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x187fe8: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x187fe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x187fec: 0x3e00008  jr          $ra
    ctx->pc = 0x187FECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187FECu;
            // 0x187ff0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187EA4u: goto label_187ea4;
            case 0x187EB8u: goto label_187eb8;
            case 0x187ED8u: goto label_187ed8;
            case 0x187EE4u: goto label_187ee4;
            case 0x187EF0u: goto label_187ef0;
            case 0x187F04u: goto label_187f04;
            case 0x187F40u: goto label_187f40;
            case 0x187F78u: goto label_187f78;
            case 0x187F88u: goto label_187f88;
            case 0x187F9Cu: goto label_187f9c;
            case 0x187FC0u: goto label_187fc0;
            case 0x187FC4u: goto label_187fc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187FF4u;
    // 0x187ff4: 0x0  nop
    ctx->pc = 0x187ff4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
