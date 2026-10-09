#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018BD60
// Address: 0x18bd60 - 0x18bf40
void sub_0018BD60_0x18bd60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018BD60_0x18bd60");
#endif

    switch (ctx->pc) {
        case 0x18bdc0u: goto label_18bdc0;
        case 0x18be68u: goto label_18be68;
        default: break;
    }

    ctx->pc = 0x18bd60u;

    // 0x18bd60: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x18bd60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x18bd64: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x18bd64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x18bd68: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x18bd68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x18bd6c: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x18bd6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x18bd70: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x18bd70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x18bd74: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x18bd74u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x18bd78: 0x160b02d  daddu       $s6, $t3, $zero
    ctx->pc = 0x18bd78u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bd7c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x18bd7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18bd80: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x18bd80u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bd84: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18bd84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18bd88: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x18bd88u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bd8c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18bd8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18bd90: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x18bd90u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bd94: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18bd94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18bd98: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x18bd98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bd9c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18bd9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18bda0: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x18bda0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bda4: 0x8fb700a0  lw          $s7, 0xA0($sp)
    ctx->pc = 0x18bda4u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18bda8: 0x8fbe00c0  lw          $fp, 0xC0($sp)
    ctx->pc = 0x18bda8u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x18bdac: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x18BDACu;
    {
        const bool branch_taken_0x18bdac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BDACu;
            // 0x18bdb0: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bdac) {
            ctx->pc = 0x18BDF4u;
            goto label_18bdf4;
        }
    }
    ctx->pc = 0x18BDB4u;
    // 0x18bdb4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18bdb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18bdb8: 0xc066134  jal         func_1984D0
    ctx->pc = 0x18BDB8u;
    SET_GPR_U32(ctx, 31, 0x18BDC0u);
    ctx->pc = 0x18BDBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BDB8u;
            // 0x18bdbc: 0x8c2bfe68  lw          $t3, -0x198($at) (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1984D0u;
    if (runtime->hasFunction(0x1984D0u)) {
        auto targetFn = runtime->lookupFunction(0x1984D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BDC0u; }
        if (ctx->pc != 0x18BDC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001984D0_0x1984d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BDC0u; }
        if (ctx->pc != 0x18BDC0u) { return; }
    }
    ctx->pc = 0x18BDC0u;
label_18bdc0:
    // 0x18bdc0: 0x2404003b  addiu       $a0, $zero, 0x3B
    ctx->pc = 0x18bdc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18bdc4: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x18bdc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x18bdc8: 0xfea40008  sd          $a0, 0x8($s5)
    ctx->pc = 0x18bdc8u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 8), GPR_U64(ctx, 4));
    // 0x18bdcc: 0xfe830008  sd          $v1, 0x8($s4)
    ctx->pc = 0x18bdccu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 8), GPR_U64(ctx, 3));
    // 0x18bdd0: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x18bdd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x18bdd4: 0xfe640008  sd          $a0, 0x8($s3)
    ctx->pc = 0x18bdd4u;
    WRITE64(ADD32(GPR_U32(ctx, 19), 8), GPR_U64(ctx, 4));
    // 0x18bdd8: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x18bdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18bddc: 0xfe430008  sd          $v1, 0x8($s2)
    ctx->pc = 0x18bddcu;
    WRITE64(ADD32(GPR_U32(ctx, 18), 8), GPR_U64(ctx, 3));
    // 0x18bde0: 0x24040034  addiu       $a0, $zero, 0x34
    ctx->pc = 0x18bde0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x18bde4: 0x24030036  addiu       $v1, $zero, 0x36
    ctx->pc = 0x18bde4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x18bde8: 0xfe240008  sd          $a0, 0x8($s1)
    ctx->pc = 0x18bde8u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 8), GPR_U64(ctx, 4));
    // 0x18bdec: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x18BDECu;
    {
        const bool branch_taken_0x18bdec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BDF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BDECu;
            // 0x18bdf0: 0xfe030008  sd          $v1, 0x8($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bdec) {
            ctx->pc = 0x18BE3Cu;
            goto label_18be3c;
        }
    }
    ctx->pc = 0x18BDF4u;
label_18bdf4:
    // 0x18bdf4: 0xfea00000  sd          $zero, 0x0($s5)
    ctx->pc = 0x18bdf4u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 0), GPR_U64(ctx, 0));
    // 0x18bdf8: 0x2403003b  addiu       $v1, $zero, 0x3B
    ctx->pc = 0x18bdf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18bdfc: 0xfea30008  sd          $v1, 0x8($s5)
    ctx->pc = 0x18bdfcu;
    WRITE64(ADD32(GPR_U32(ctx, 21), 8), GPR_U64(ctx, 3));
    // 0x18be00: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x18be00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x18be04: 0xfe800000  sd          $zero, 0x0($s4)
    ctx->pc = 0x18be04u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 0));
    // 0x18be08: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x18be08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x18be0c: 0xfe840008  sd          $a0, 0x8($s4)
    ctx->pc = 0x18be0cu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 8), GPR_U64(ctx, 4));
    // 0x18be10: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x18be10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18be14: 0xfe600000  sd          $zero, 0x0($s3)
    ctx->pc = 0x18be14u;
    WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 0));
    // 0x18be18: 0x24040034  addiu       $a0, $zero, 0x34
    ctx->pc = 0x18be18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x18be1c: 0xfe630008  sd          $v1, 0x8($s3)
    ctx->pc = 0x18be1cu;
    WRITE64(ADD32(GPR_U32(ctx, 19), 8), GPR_U64(ctx, 3));
    // 0x18be20: 0xfe400000  sd          $zero, 0x0($s2)
    ctx->pc = 0x18be20u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 0));
    // 0x18be24: 0x24030036  addiu       $v1, $zero, 0x36
    ctx->pc = 0x18be24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x18be28: 0xfe450008  sd          $a1, 0x8($s2)
    ctx->pc = 0x18be28u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 8), GPR_U64(ctx, 5));
    // 0x18be2c: 0xfe200000  sd          $zero, 0x0($s1)
    ctx->pc = 0x18be2cu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 0));
    // 0x18be30: 0xfe240008  sd          $a0, 0x8($s1)
    ctx->pc = 0x18be30u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 8), GPR_U64(ctx, 4));
    // 0x18be34: 0xfe000000  sd          $zero, 0x0($s0)
    ctx->pc = 0x18be34u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 0));
    // 0x18be38: 0xfe030008  sd          $v1, 0x8($s0)
    ctx->pc = 0x18be38u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 3));
label_18be3c:
    // 0x18be3c: 0x12c0001a  beqz        $s6, . + 4 + (0x1A << 2)
    ctx->pc = 0x18BE3Cu;
    {
        const bool branch_taken_0x18be3c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BE3Cu;
            // 0x18be40: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18be3c) {
            ctx->pc = 0x18BEA8u;
            goto label_18bea8;
        }
    }
    ctx->pc = 0x18BE44u;
    // 0x18be44: 0x8fa700a8  lw          $a3, 0xA8($sp)
    ctx->pc = 0x18be44u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18be48: 0x8fa800b0  lw          $t0, 0xB0($sp)
    ctx->pc = 0x18be48u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18be4c: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x18be4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18be50: 0x8fa900b8  lw          $t1, 0xB8($sp)
    ctx->pc = 0x18be50u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x18be54: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x18be54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18be58: 0x8c2bfe68  lw          $t3, -0x198($at)
    ctx->pc = 0x18be58u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x18be5c: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x18be5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18be60: 0xc066134  jal         func_1984D0
    ctx->pc = 0x18BE60u;
    SET_GPR_U32(ctx, 31, 0x18BE68u);
    ctx->pc = 0x18BE64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BE60u;
            // 0x18be64: 0x3c0502d  daddu       $t2, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1984D0u;
    if (runtime->hasFunction(0x1984D0u)) {
        auto targetFn = runtime->lookupFunction(0x1984D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BE68u; }
        if (ctx->pc != 0x18BE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001984D0_0x1984d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BE68u; }
        if (ctx->pc != 0x18BE68u) { return; }
    }
    ctx->pc = 0x18BE68u;
label_18be68:
    // 0x18be68: 0x2404003b  addiu       $a0, $zero, 0x3B
    ctx->pc = 0x18be68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18be6c: 0x24030015  addiu       $v1, $zero, 0x15
    ctx->pc = 0x18be6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x18be70: 0xfea40008  sd          $a0, 0x8($s5)
    ctx->pc = 0x18be70u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 8), GPR_U64(ctx, 4));
    // 0x18be74: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x18be74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x18be78: 0xfee30008  sd          $v1, 0x8($s7)
    ctx->pc = 0x18be78u;
    WRITE64(ADD32(GPR_U32(ctx, 23), 8), GPR_U64(ctx, 3));
    // 0x18be7c: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x18be7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x18be80: 0x8fa300a8  lw          $v1, 0xA8($sp)
    ctx->pc = 0x18be80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18be84: 0xfc650008  sd          $a1, 0x8($v1)
    ctx->pc = 0x18be84u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 5));
    // 0x18be88: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x18be88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18be8c: 0x24050034  addiu       $a1, $zero, 0x34
    ctx->pc = 0x18be8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x18be90: 0xfc640008  sd          $a0, 0x8($v1)
    ctx->pc = 0x18be90u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 4));
    // 0x18be94: 0x8fa300b8  lw          $v1, 0xB8($sp)
    ctx->pc = 0x18be94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x18be98: 0x24040036  addiu       $a0, $zero, 0x36
    ctx->pc = 0x18be98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x18be9c: 0xfc650008  sd          $a1, 0x8($v1)
    ctx->pc = 0x18be9cu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 5));
    // 0x18bea0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18BEA0u;
    {
        const bool branch_taken_0x18bea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BEA0u;
            // 0x18bea4: 0xffc40008  sd          $a0, 0x8($fp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 30), 8), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bea0) {
            ctx->pc = 0x18BF08u;
            goto label_18bf08;
        }
    }
    ctx->pc = 0x18BEA8u;
label_18bea8:
    // 0x18bea8: 0xfea00000  sd          $zero, 0x0($s5)
    ctx->pc = 0x18bea8u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 0), GPR_U64(ctx, 0));
    // 0x18beac: 0x2403003b  addiu       $v1, $zero, 0x3B
    ctx->pc = 0x18beacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18beb0: 0xfea30008  sd          $v1, 0x8($s5)
    ctx->pc = 0x18beb0u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 8), GPR_U64(ctx, 3));
    // 0x18beb4: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x18beb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x18beb8: 0x24030015  addiu       $v1, $zero, 0x15
    ctx->pc = 0x18beb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x18bebc: 0xfee00000  sd          $zero, 0x0($s7)
    ctx->pc = 0x18bebcu;
    WRITE64(ADD32(GPR_U32(ctx, 23), 0), GPR_U64(ctx, 0));
    // 0x18bec0: 0xfee30008  sd          $v1, 0x8($s7)
    ctx->pc = 0x18bec0u;
    WRITE64(ADD32(GPR_U32(ctx, 23), 8), GPR_U64(ctx, 3));
    // 0x18bec4: 0x24060009  addiu       $a2, $zero, 0x9
    ctx->pc = 0x18bec4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x18bec8: 0x8fa300a8  lw          $v1, 0xA8($sp)
    ctx->pc = 0x18bec8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18becc: 0x24050035  addiu       $a1, $zero, 0x35
    ctx->pc = 0x18beccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x18bed0: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x18bed0u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x18bed4: 0x8fa300a8  lw          $v1, 0xA8($sp)
    ctx->pc = 0x18bed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18bed8: 0xfc640008  sd          $a0, 0x8($v1)
    ctx->pc = 0x18bed8u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 4));
    // 0x18bedc: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x18bedcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18bee0: 0x24040037  addiu       $a0, $zero, 0x37
    ctx->pc = 0x18bee0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
    // 0x18bee4: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x18bee4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x18bee8: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x18bee8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18beec: 0xfc660008  sd          $a2, 0x8($v1)
    ctx->pc = 0x18beecu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 6));
    // 0x18bef0: 0x8fa300b8  lw          $v1, 0xB8($sp)
    ctx->pc = 0x18bef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x18bef4: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x18bef4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x18bef8: 0x8fa300b8  lw          $v1, 0xB8($sp)
    ctx->pc = 0x18bef8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x18befc: 0xfc650008  sd          $a1, 0x8($v1)
    ctx->pc = 0x18befcu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 5));
    // 0x18bf00: 0xffc00000  sd          $zero, 0x0($fp)
    ctx->pc = 0x18bf00u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 0), GPR_U64(ctx, 0));
    // 0x18bf04: 0xffc40008  sd          $a0, 0x8($fp)
    ctx->pc = 0x18bf04u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 8), GPR_U64(ctx, 4));
label_18bf08:
    // 0x18bf08: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x18bf08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x18bf0c: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x18bf0cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18bf10: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x18bf10u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18bf14: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x18bf14u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18bf18: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x18bf18u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18bf1c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x18bf1cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18bf20: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18bf20u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18bf24: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18bf24u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18bf28: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18bf28u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18bf2c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18bf2cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18bf30: 0x3e00008  jr          $ra
    ctx->pc = 0x18BF30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18BF34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BF30u;
            // 0x18bf34: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18BDC0u: goto label_18bdc0;
            case 0x18BDF4u: goto label_18bdf4;
            case 0x18BE3Cu: goto label_18be3c;
            case 0x18BE68u: goto label_18be68;
            case 0x18BEA8u: goto label_18bea8;
            case 0x18BF08u: goto label_18bf08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18BF38u;
    // 0x18bf38: 0x0  nop
    ctx->pc = 0x18bf38u;
    // NOP
    // 0x18bf3c: 0x0  nop
    ctx->pc = 0x18bf3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
