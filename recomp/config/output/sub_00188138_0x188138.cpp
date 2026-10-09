#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188138
// Address: 0x188138 - 0x188348
void sub_00188138_0x188138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188138_0x188138");
#endif

    switch (ctx->pc) {
        case 0x188198u: goto label_188198;
        case 0x1881c8u: goto label_1881c8;
        case 0x188224u: goto label_188224;
        case 0x188238u: goto label_188238;
        case 0x188240u: goto label_188240;
        case 0x188278u: goto label_188278;
        case 0x188290u: goto label_188290;
        case 0x1882b0u: goto label_1882b0;
        case 0x1882c4u: goto label_1882c4;
        case 0x1882d4u: goto label_1882d4;
        default: break;
    }

    ctx->pc = 0x188138u;

label_188138:
    // 0x188138: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x188138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18813c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x18813cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188140: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x188140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x188144: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x188144u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188148: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x188148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x18814c: 0x14b0c0  sll         $s6, $s4, 3
    ctx->pc = 0x18814cu;
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x188150: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x188150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x188154: 0x2453b8c8  addiu       $s3, $v0, -0x4738
    ctx->pc = 0x188154u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x188158: 0x2d41023  subu        $v0, $s6, $s4
    ctx->pc = 0x188158u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 20)));
    // 0x18815c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x18815cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x188160: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x188160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x188164: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x188164u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188168: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x188168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x18816c: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x18816cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188170: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x188170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x188174: 0x100f02d  daddu       $fp, $t0, $zero
    ctx->pc = 0x188174u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188178: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18817c: 0x29080  sll         $s2, $v0, 2
    ctx->pc = 0x18817cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x188180: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x188180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x188184: 0x2721021  addu        $v0, $s3, $s2
    ctx->pc = 0x188184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x188188: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x188188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x18818c: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x18818cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x188190: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x188190u;
    SET_GPR_U32(ctx, 31, 0x188198u);
    ctx->pc = 0x188194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188190u;
            // 0x188194: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188198u; }
        if (ctx->pc != 0x188198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188198u; }
        if (ctx->pc != 0x188198u) { return; }
    }
    ctx->pc = 0x188198u;
label_188198:
    // 0x188198: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x188198u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x18819c: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x18819Cu;
    {
        const bool branch_taken_0x18819c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x18819c) {
            ctx->pc = 0x1881A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18819Cu;
            // 0x1881a0: 0x3c020029  lui         $v0, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1881B0u;
            goto label_1881b0;
        }
    }
    ctx->pc = 0x1881A4u;
    // 0x1881a4: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1881A4u;
    {
        const bool branch_taken_0x1881a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1881A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1881A4u;
            // 0x1881a8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1881a4) {
            ctx->pc = 0x1882E8u;
            goto label_1882e8;
        }
    }
    ctx->pc = 0x1881ACu;
    // 0x1881ac: 0x0  nop
    ctx->pc = 0x1881acu;
    // NOP
label_1881b0:
    // 0x1881b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1881b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1881b4: 0x2450b900  addiu       $s0, $v0, -0x4700
    ctx->pc = 0x1881b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949120));
    // 0x1881b8: 0x24062080  addiu       $a2, $zero, 0x2080
    ctx->pc = 0x1881b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x1881bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1881bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1881c0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1881C0u;
    SET_GPR_U32(ctx, 31, 0x1881C8u);
    ctx->pc = 0x1881C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1881C0u;
            // 0x1881c4: 0x24112080  addiu       $s1, $zero, 0x2080 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1881C8u; }
        if (ctx->pc != 0x1881C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1881C8u; }
        if (ctx->pc != 0x1881C8u) { return; }
    }
    ctx->pc = 0x1881C8u;
label_1881c8:
    // 0x1881c8: 0xae150000  sw          $s5, 0x0($s0)
    ctx->pc = 0x1881c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 21));
    // 0x1881cc: 0x2722821  addu        $a1, $s3, $s2
    ctx->pc = 0x1881ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x1881d0: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x1881d0u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x1881d4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1881d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1881d8: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1881d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1881dc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1881dcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1881e0: 0x8c470008  lw          $a3, 0x8($v0)
    ctx->pc = 0x1881e0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1881e4: 0x8c68000c  lw          $t0, 0xC($v1)
    ctx->pc = 0x1881e4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1881e8: 0x2484d980  addiu       $a0, $a0, -0x2680
    ctx->pc = 0x1881e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957440));
    // 0x1881ec: 0x8ca20010  lw          $v0, 0x10($a1)
    ctx->pc = 0x1881ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1881f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1881f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1881f4: 0xae1e0024  sw          $fp, 0x24($s0)
    ctx->pc = 0x1881f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 30));
    // 0x1881f8: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1881f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1881fc: 0xae070008  sw          $a3, 0x8($s0)
    ctx->pc = 0x1881fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x188200: 0xae08000c  sw          $t0, 0xC($s0)
    ctx->pc = 0x188200u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 8));
    // 0x188204: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x188204u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x188208: 0xafb10000  sw          $s1, 0x0($sp)
    ctx->pc = 0x188208u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 17));
    // 0x18820c: 0xae170004  sw          $s7, 0x4($s0)
    ctx->pc = 0x18820cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 23));
    // 0x188210: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x188210u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x188214: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x188214u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x188218: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x188218u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x18821c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x18821Cu;
    SET_GPR_U32(ctx, 31, 0x188224u);
    ctx->pc = 0x188220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18821Cu;
            // 0x188220: 0xae000020  sw          $zero, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188224u; }
        if (ctx->pc != 0x188224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188224u; }
        if (ctx->pc != 0x188224u) { return; }
    }
    ctx->pc = 0x188224u;
label_188224:
    // 0x188224: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x188224u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188228: 0xae43fd24  sw          $v1, -0x2DC($s2)
    ctx->pc = 0x188228u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294966564), GPR_U32(ctx, 3));
    // 0x18822c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x18822Cu;
    {
        const bool branch_taken_0x18822c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18822Cu;
            // 0x188230: 0x3c110018  lui         $s1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)24 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18822c) {
            ctx->pc = 0x188240u;
            goto label_188240;
        }
    }
    ctx->pc = 0x188234u;
    // 0x188234: 0x0  nop
    ctx->pc = 0x188234u;
    // NOP
label_188238:
    // 0x188238: 0xc045a12  jal         func_116848
    ctx->pc = 0x188238u;
    SET_GPR_U32(ctx, 31, 0x188240u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188240u; }
        if (ctx->pc != 0x188240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188240u; }
        if (ctx->pc != 0x188240u) { return; }
    }
    ctx->pc = 0x188240u;
label_188240:
    // 0x188240: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188240u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188244: 0x8e45fd24  lw          $a1, -0x2DC($s2)
    ctx->pc = 0x188244u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294966564)));
    // 0x188248: 0x2443b8c8  addiu       $v1, $v0, -0x4738
    ctx->pc = 0x188248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x18824c: 0x2d41023  subu        $v0, $s6, $s4
    ctx->pc = 0x18824cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 20)));
    // 0x188250: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x188250u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x188254: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x188254u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x188258: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x188258u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18825c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x18825cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188260: 0x2453b900  addiu       $s3, $v0, -0x4700
    ctx->pc = 0x188260u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949120));
    // 0x188264: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x188264u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x188268: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x188268u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18826c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x18826cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188270: 0xc062560  jal         func_189580
    ctx->pc = 0x188270u;
    SET_GPR_U32(ctx, 31, 0x188278u);
    ctx->pc = 0x188274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188270u;
            // 0x188274: 0x26287808  addiu       $t0, $s1, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188278u; }
        if (ctx->pc != 0x188278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188278u; }
        if (ctx->pc != 0x188278u) { return; }
    }
    ctx->pc = 0x188278u;
label_188278:
    // 0x188278: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188278u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x18827c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18827cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188280: 0x1443ffed  bne         $v0, $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x188280u;
    {
        const bool branch_taken_0x188280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x188284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188280u;
            // 0x188284: 0x24841838  addiu       $a0, $a0, 0x1838 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188280) {
            ctx->pc = 0x188238u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188238;
        }
    }
    ctx->pc = 0x188288u;
    // 0x188288: 0xc061de6  jal         func_187798
    ctx->pc = 0x188288u;
    SET_GPR_U32(ctx, 31, 0x188290u);
    ctx->pc = 0x18828Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188288u;
            // 0x18828c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187798u;
    if (runtime->hasFunction(0x187798u)) {
        auto targetFn = runtime->lookupFunction(0x187798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188290u; }
        if (ctx->pc != 0x188290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187798_0x187798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188290u; }
        if (ctx->pc != 0x188290u) { return; }
    }
    ctx->pc = 0x188290u;
label_188290:
    // 0x188290: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x188290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x188294: 0x10600014  beqz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x188294u;
    {
        const bool branch_taken_0x188294 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x188298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188294u;
            // 0x188298: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188294) {
            ctx->pc = 0x1882E8u;
            goto label_1882e8;
        }
    }
    ctx->pc = 0x18829Cu;
    // 0x18829c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x18829cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1882a0: 0x8fb20004  lw          $s2, 0x4($sp)
    ctx->pc = 0x1882a0u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1882a4: 0x1ae0000f  blez        $s7, . + 4 + (0xF << 2)
    ctx->pc = 0x1882A4u;
    {
        const bool branch_taken_0x1882a4 = (GPR_S64(ctx, 23) <= 0);
        ctx->pc = 0x1882A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1882A4u;
            // 0x1882a8: 0x2451da00  addiu       $s1, $v0, -0x2600 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1882a4) {
            ctx->pc = 0x1882E4u;
            goto label_1882e4;
        }
    }
    ctx->pc = 0x1882ACu;
    // 0x1882ac: 0x2e0802d  daddu       $s0, $s7, $zero
    ctx->pc = 0x1882acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_1882b0:
    // 0x1882b0: 0x8e650008  lw          $a1, 0x8($s3)
    ctx->pc = 0x1882b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1882b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1882b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1882b8: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x1882b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1882bc: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1882BCu;
    SET_GPR_U32(ctx, 31, 0x1882C4u);
    ctx->pc = 0x1882C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1882BCu;
            // 0x1882c0: 0x2252821  addu        $a1, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1882C4u; }
        if (ctx->pc != 0x1882C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1882C4u; }
        if (ctx->pc != 0x1882C4u) { return; }
    }
    ctx->pc = 0x1882C4u;
label_1882c4:
    // 0x1882c4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1882c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1882c8: 0x8e660008  lw          $a2, 0x8($s3)
    ctx->pc = 0x1882c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1882cc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1882CCu;
    SET_GPR_U32(ctx, 31, 0x1882D4u);
    ctx->pc = 0x1882D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1882CCu;
            // 0x1882d0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1882D4u; }
        if (ctx->pc != 0x1882D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1882D4u; }
        if (ctx->pc != 0x1882D4u) { return; }
    }
    ctx->pc = 0x1882D4u;
label_1882d4:
    // 0x1882d4: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1882d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1882d8: 0x2439021  addu        $s2, $s2, $v1
    ctx->pc = 0x1882d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1882dc: 0x1600fff4  bnez        $s0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1882DCu;
    {
        const bool branch_taken_0x1882dc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1882E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1882DCu;
            // 0x1882e0: 0x2238821  addu        $s1, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1882dc) {
            ctx->pc = 0x1882B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1882b0;
        }
    }
    ctx->pc = 0x1882E4u;
label_1882e4:
    // 0x1882e4: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x1882e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_1882e8:
    // 0x1882e8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1882e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1882ec: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1882ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1882f0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1882f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1882f4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1882f4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1882f8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1882f8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1882fc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1882fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x188300: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x188300u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188304: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x188304u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x188308: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x188308u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18830c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x18830cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x188310: 0x3e00008  jr          $ra
    ctx->pc = 0x188310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188310u;
            // 0x188314: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188138u: goto label_188138;
            case 0x188198u: goto label_188198;
            case 0x1881B0u: goto label_1881b0;
            case 0x1881C8u: goto label_1881c8;
            case 0x188224u: goto label_188224;
            case 0x188238u: goto label_188238;
            case 0x188240u: goto label_188240;
            case 0x188278u: goto label_188278;
            case 0x188290u: goto label_188290;
            case 0x1882B0u: goto label_1882b0;
            case 0x1882C4u: goto label_1882c4;
            case 0x1882D4u: goto label_1882d4;
            case 0x1882E4u: goto label_1882e4;
            case 0x1882E8u: goto label_1882e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188318u;
    // 0x188318: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x188318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18831c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x18831cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x188320: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x188320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x188324: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x188324u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x188328: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x188328u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18832c: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x18832cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x188330: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x188330u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x188334: 0x8d08b8dc  lw          $t0, -0x4724($t0)
    ctx->pc = 0x188334u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4294949084)));
    // 0x188338: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x188338u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18833c: 0x806204e  j           func_188138
    ctx->pc = 0x18833Cu;
    ctx->pc = 0x188340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18833Cu;
            // 0x188340: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188138u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_188138;
    ctx->pc = 0x188344u;
    // 0x188344: 0x0  nop
    ctx->pc = 0x188344u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
