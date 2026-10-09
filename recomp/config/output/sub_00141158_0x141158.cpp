#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141158
// Address: 0x141158 - 0x141268
void sub_00141158_0x141158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141158_0x141158");
#endif

    switch (ctx->pc) {
        case 0x141198u: goto label_141198;
        case 0x1411a0u: goto label_1411a0;
        case 0x1411c0u: goto label_1411c0;
        case 0x141214u: goto label_141214;
        case 0x141238u: goto label_141238;
        default: break;
    }

    ctx->pc = 0x141158u;

    // 0x141158: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x141158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x14115c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x14115cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x141160: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x141160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x141164: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x141164u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141168: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x141168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x14116c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14116cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141170: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x141170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x141174: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x141174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x141178: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x141178u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14117c: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x14117cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x141180: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x141180u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141184: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x141184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x141188: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x141188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x14118c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x14118cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x141190: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x141190u;
    SET_GPR_U32(ctx, 31, 0x141198u);
    ctx->pc = 0x141194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141190u;
            // 0x141194: 0x26d50010  addiu       $s5, $s6, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141198u; }
        if (ctx->pc != 0x141198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141198u; }
        if (ctx->pc != 0x141198u) { return; }
    }
    ctx->pc = 0x141198u;
label_141198:
    // 0x141198: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x14119c: 0x24519a90  addiu       $s1, $v0, -0x6570
    ctx->pc = 0x14119cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941328));
label_1411a0:
    // 0x1411a0: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1411a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1411a4: 0x5457001f  bnel        $v0, $s7, . + 4 + (0x1F << 2)
    ctx->pc = 0x1411A4u;
    {
        const bool branch_taken_0x1411a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 23));
        if (branch_taken_0x1411a4) {
            ctx->pc = 0x1411A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1411A4u;
            // 0x1411a8: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141224u;
            goto label_141224;
        }
    }
    ctx->pc = 0x1411ACu;
    // 0x1411ac: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x1411acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x1411b0: 0x24140080  addiu       $s4, $zero, 0x80
    ctx->pc = 0x1411b0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1411b4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1411B4u;
    {
        const bool branch_taken_0x1411b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1411B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1411B4u;
            // 0x1411b8: 0x558021  addu        $s0, $v0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1411b4) {
            ctx->pc = 0x1411F0u;
            goto label_1411f0;
        }
    }
    ctx->pc = 0x1411BCu;
    // 0x1411bc: 0x0  nop
    ctx->pc = 0x1411bcu;
    // NOP
label_1411c0:
    // 0x1411c0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1411c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1411c4: 0x9222000c  lbu         $v0, 0xC($s1)
    ctx->pc = 0x1411c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1411c8: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x1411c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1411cc: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1411ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1411d0: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1411d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1411d4: 0x96220002  lhu         $v0, 0x2($s1)
    ctx->pc = 0x1411d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1411d8: 0x6ba30007  ldl         $v1, 0x7($sp)
    ctx->pc = 0x1411d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1411dc: 0x6fa30000  ldr         $v1, 0x0($sp)
    ctx->pc = 0x1411dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1411e0: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x1411e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1411e4: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x1411e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1411e8: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1411e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1411ec: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1411ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_1411f0:
    // 0x1411f0: 0x1254000f  beq         $s2, $s4, . + 4 + (0xF << 2)
    ctx->pc = 0x1411F0u;
    {
        const bool branch_taken_0x1411f0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 20));
        ctx->pc = 0x1411F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1411F0u;
            // 0x1411f4: 0x3c067fff  lui         $a2, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1411f0) {
            ctx->pc = 0x141230u;
            goto label_141230;
        }
    }
    ctx->pc = 0x1411F8u;
    // 0x1411f8: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1411f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1411fc: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1411fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141200: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x141200u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x141204: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141204u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141208: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x141208u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14120c: 0x40f809  jalr        $v0
    ctx->pc = 0x14120Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141214u);
        ctx->pc = 0x141210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14120Cu;
            // 0x141210: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141214u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141214u; }
            if (ctx->pc != 0x141214u) { return; }
        }
        }
    }
    ctx->pc = 0x141214u;
label_141214:
    // 0x141214: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x141214u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x141218: 0x5460ffe9  bnel        $v1, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x141218u;
    {
        const bool branch_taken_0x141218 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x141218) {
            ctx->pc = 0x14121Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141218u;
            // 0x14121c: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1411C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1411c0;
        }
    }
    ctx->pc = 0x141220u;
    // 0x141220: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x141220u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_141224:
    // 0x141224: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x141224u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x141228: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x141228u;
    {
        const bool branch_taken_0x141228 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14122Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141228u;
            // 0x14122c: 0x26310014  addiu       $s1, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141228) {
            ctx->pc = 0x1411A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1411a0;
        }
    }
    ctx->pc = 0x141230u;
label_141230:
    // 0x141230: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x141230u;
    SET_GPR_U32(ctx, 31, 0x141238u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141238u; }
        if (ctx->pc != 0x141238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141238u; }
        if (ctx->pc != 0x141238u) { return; }
    }
    ctx->pc = 0x141238u;
label_141238:
    // 0x141238: 0xaed20000  sw          $s2, 0x0($s6)
    ctx->pc = 0x141238u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 18));
    // 0x14123c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14123cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141240: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x141240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141244: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x141244u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141248: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x141248u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14124c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x14124cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x141250: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x141250u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x141254: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x141254u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x141258: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x141258u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14125c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x14125cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x141260: 0x3e00008  jr          $ra
    ctx->pc = 0x141260u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141260u;
            // 0x141264: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141268u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
