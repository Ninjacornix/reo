#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E120
// Address: 0x17e120 - 0x17e320
void sub_0017E120_0x17e120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E120_0x17e120");
#endif

    switch (ctx->pc) {
        case 0x17e148u: goto label_17e148;
        case 0x17e194u: goto label_17e194;
        case 0x17e1a8u: goto label_17e1a8;
        case 0x17e1f8u: goto label_17e1f8;
        case 0x17e2dcu: goto label_17e2dc;
        case 0x17e2fcu: goto label_17e2fc;
        default: break;
    }

    ctx->pc = 0x17e120u;

    // 0x17e120: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e124: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17e124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17e128: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17e128u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e12c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e12cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e130: 0x26500400  addiu       $s0, $s2, 0x400
    ctx->pc = 0x17e130u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 1024));
    // 0x17e134: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x17e134u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e138: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17e138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17e13c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17e13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17e140: 0xc05f6bc  jal         func_17DAF0
    ctx->pc = 0x17E140u;
    SET_GPR_U32(ctx, 31, 0x17E148u);
    ctx->pc = 0x17E144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E140u;
            // 0x17e144: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DAF0u;
    if (runtime->hasFunction(0x17DAF0u)) {
        auto targetFn = runtime->lookupFunction(0x17DAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E148u; }
        if (ctx->pc != 0x17E148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017DAF0_0x17daf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E148u; }
        if (ctx->pc != 0x17E148u) { return; }
    }
    ctx->pc = 0x17E148u;
label_17e148:
    // 0x17e148: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17e148u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e14c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17e14cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e150: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e150u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e154: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17e154u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e158: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17e158u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e15c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17e15cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e160: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17e160u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e164: 0x805f85c  j           func_17E170
    ctx->pc = 0x17E164u;
    ctx->pc = 0x17E168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E164u;
            // 0x17e168: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E170u;
    goto label_17e170;
    ctx->pc = 0x17E16Cu;
    // 0x17e16c: 0x0  nop
    ctx->pc = 0x17e16cu;
    // NOP
label_17e170:
    // 0x17e170: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e174: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e178: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17e178u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e17c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17e17cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17e180: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17e180u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e184: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17e184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17e188: 0xe7b40018  swc1        $f20, 0x18($sp)
    ctx->pc = 0x17e188u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x17e18c: 0xc05f8ea  jal         func_17E3A8
    ctx->pc = 0x17E18Cu;
    SET_GPR_U32(ctx, 31, 0x17E194u);
    ctx->pc = 0x17E190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E18Cu;
            // 0x17e190: 0xc4940040  lwc1        $f20, 0x40($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E3A8u;
    if (runtime->hasFunction(0x17E3A8u)) {
        auto targetFn = runtime->lookupFunction(0x17E3A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E194u; }
        if (ctx->pc != 0x17E194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E3A8_0x17e3a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E194u; }
        if (ctx->pc != 0x17E194u) { return; }
    }
    ctx->pc = 0x17E194u;
label_17e194:
    // 0x17e194: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17e194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e198: 0x1443000f  bne         $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x17E198u;
    {
        const bool branch_taken_0x17e198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17E19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E198u;
            // 0x17e19c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e198) {
            ctx->pc = 0x17E1D8u;
            goto label_17e1d8;
        }
    }
    ctx->pc = 0x17E1A0u;
    // 0x17e1a0: 0x3c077fff  lui         $a3, 0x7FFF
    ctx->pc = 0x17e1a0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)32767 << 16));
    // 0x17e1a4: 0x34e7ff80  ori         $a3, $a3, 0xFF80
    ctx->pc = 0x17e1a4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65408);
label_17e1a8:
    // 0x17e1a8: 0x62080  sll         $a0, $a2, 2
    ctx->pc = 0x17e1a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x17e1ac: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x17e1acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x17e1b0: 0x911821  addu        $v1, $a0, $s1
    ctx->pc = 0x17e1b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x17e1b4: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x17e1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x17e1b8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x17e1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17e1bc: 0x28c50100  slti        $a1, $a2, 0x100
    ctx->pc = 0x17e1bcu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17e1c0: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x17e1c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x17e1c4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x17e1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x17e1c8: 0x14a0fff7  bnez        $a1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x17E1C8u;
    {
        const bool branch_taken_0x17e1c8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x17E1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E1C8u;
            // 0x17e1cc: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e1c8) {
            ctx->pc = 0x17E1A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17e1a8;
        }
    }
    ctx->pc = 0x17E1D0u;
    // 0x17e1d0: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x17E1D0u;
    {
        const bool branch_taken_0x17e1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E1D0u;
            // 0x17e1d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e1d0) {
            ctx->pc = 0x17E2A0u;
            goto label_17e2a0;
        }
    }
    ctx->pc = 0x17E1D8u;
label_17e1d8:
    // 0x17e1d8: 0x3c014eff  lui         $at, 0x4EFF
    ctx->pc = 0x17e1d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20223 << 16));
    // 0x17e1dc: 0x3421ffff  ori         $at, $at, 0xFFFF
    ctx->pc = 0x17e1dcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65535);
    // 0x17e1e0: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x17e1e0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x17e1e4: 0x3c014b7f  lui         $at, 0x4B7F
    ctx->pc = 0x17e1e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)19327 << 16));
    // 0x17e1e8: 0x3421ffff  ori         $at, $at, 0xFFFF
    ctx->pc = 0x17e1e8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65535);
    // 0x17e1ec: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x17e1ecu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x17e1f0: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x17e1f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e1f4: 0x3c098000  lui         $t1, 0x8000
    ctx->pc = 0x17e1f4u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32768 << 16));
label_17e1f8:
    // 0x17e1f8: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x17e1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x17e1fc: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x17e1fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x17e200: 0x511821  addu        $v1, $v0, $s1
    ctx->pc = 0x17e200u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x17e204: 0x28c70100  slti        $a3, $a2, 0x100
    ctx->pc = 0x17e204u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17e208: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x17e208u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17e20c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E20Cu;
    {
        const bool branch_taken_0x17e20c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x17E210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E20Cu;
            // 0x17e210: 0x502821  addu        $a1, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e20c) {
            ctx->pc = 0x17E21Cu;
            goto label_17e21c;
        }
    }
    ctx->pc = 0x17E214u;
    // 0x17e214: 0xac680000  sw          $t0, 0x0($v1)
    ctx->pc = 0x17e214u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 8));
    // 0x17e218: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x17e218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_17e21c:
    // 0x17e21c: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17E21Cu;
    {
        const bool branch_taken_0x17e21c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x17E220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E21Cu;
            // 0x17e220: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e21c) {
            ctx->pc = 0x17E238u;
            goto label_17e238;
        }
    }
    ctx->pc = 0x17E224u;
    // 0x17e224: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x17e224u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17e228: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x17e228u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x17e22c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x17E22Cu;
    {
        const bool branch_taken_0x17e22c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E22Cu;
            // 0x17e230: 0x4600a002  mul.s       $f0, $f20, $f0 (Delay Slot)
        ctx->f[0] = FPU_MUL_S(ctx->f[20], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e22c) {
            ctx->pc = 0x17E250u;
            goto label_17e250;
        }
    }
    ctx->pc = 0x17E234u;
    // 0x17e234: 0x0  nop
    ctx->pc = 0x17e234u;
    // NOP
label_17e238:
    // 0x17e238: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x17e238u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x17e23c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x17e23cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x17e240: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x17e240u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17e244: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x17e244u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x17e248: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x17e248u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
    // 0x17e24c: 0x4600a002  mul.s       $f0, $f20, $f0
    ctx->pc = 0x17e24cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[20], ctx->f[0]);
label_17e250:
    // 0x17e250: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x17e250u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x17e254: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17e254u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17e258: 0x0  nop
    ctx->pc = 0x17e258u;
    // NOP
    // 0x17e25c: 0x0  nop
    ctx->pc = 0x17e25cu;
    // NOP
    // 0x17e260: 0x46030003  div.s       $f0, $f0, $f3
    ctx->pc = 0x17e260u;
    if (ctx->f[3] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[3])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[3];
    // 0x17e264: 0x0  nop
    ctx->pc = 0x17e264u;
    // NOP
    // 0x17e268: 0x0  nop
    ctx->pc = 0x17e268u;
    // NOP
    // 0x17e26c: 0x46001003  div.s       $f0, $f2, $f0
    ctx->pc = 0x17e26cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[0];
    // 0x17e270: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x17e270u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17e274: 0x46000124  .word       0x46000124                   # cvt.w.s     $f4, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17e274u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[4], &tmp, sizeof(tmp)); }
    // 0x17e278: 0x44022000  mfc1        $v0, $f4
    ctx->pc = 0x17e278u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[4], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17e27c: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x17E27Cu;
    {
        const bool branch_taken_0x17e27c = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x17e27c) {
            ctx->pc = 0x17E294u;
            goto label_17e294;
        }
    }
    ctx->pc = 0x17E284u;
    // 0x17e284: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x17e284u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x17e288: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17e288u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x17e28c: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x17e28cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17e290: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x17e290u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
label_17e294:
    // 0x17e294: 0x14e0ffd8  bnez        $a3, . + 4 + (-0x28 << 2)
    ctx->pc = 0x17E294u;
    {
        const bool branch_taken_0x17e294 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x17E298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E294u;
            // 0x17e298: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e294) {
            ctx->pc = 0x17E1F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17e1f8;
        }
    }
    ctx->pc = 0x17E29Cu;
    // 0x17e29c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e29cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17e2a0:
    // 0x17e2a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17e2a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e2a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17e2a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e2a8: 0xc7b40018  lwc1        $f20, 0x18($sp)
    ctx->pc = 0x17e2a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17e2ac: 0x3e00008  jr          $ra
    ctx->pc = 0x17E2ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E2B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E2ACu;
            // 0x17e2b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E148u: goto label_17e148;
            case 0x17E170u: goto label_17e170;
            case 0x17E194u: goto label_17e194;
            case 0x17E1A8u: goto label_17e1a8;
            case 0x17E1D8u: goto label_17e1d8;
            case 0x17E1F8u: goto label_17e1f8;
            case 0x17E21Cu: goto label_17e21c;
            case 0x17E238u: goto label_17e238;
            case 0x17E250u: goto label_17e250;
            case 0x17E294u: goto label_17e294;
            case 0x17E2A0u: goto label_17e2a0;
            case 0x17E2DCu: goto label_17e2dc;
            case 0x17E2FCu: goto label_17e2fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E2B4u;
    // 0x17e2b4: 0x0  nop
    ctx->pc = 0x17e2b4u;
    // NOP
    // 0x17e2b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e2b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e2bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e2bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e2c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e2c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e2c4: 0xe7b50018  swc1        $f21, 0x18($sp)
    ctx->pc = 0x17e2c4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x17e2c8: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x17e2c8u;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x17e2cc: 0xe7b40010  swc1        $f20, 0x10($sp)
    ctx->pc = 0x17e2ccu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x17e2d0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17e2d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17e2d4: 0xc05f8c8  jal         func_17E320
    ctx->pc = 0x17E2D4u;
    SET_GPR_U32(ctx, 31, 0x17E2DCu);
    ctx->pc = 0x17E2D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E2D4u;
            // 0x17e2d8: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E320u;
    if (runtime->hasFunction(0x17E320u)) {
        auto targetFn = runtime->lookupFunction(0x17E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2DCu; }
        if (ctx->pc != 0x17E2DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E320_0x17e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2DCu; }
        if (ctx->pc != 0x17E2DCu) { return; }
    }
    ctx->pc = 0x17E2DCu;
label_17e2dc:
    // 0x17e2dc: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17e2dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17e2e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17e2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e2e4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17e2e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e2e8: 0x24c61498  addiu       $a2, $a2, 0x1498
    ctx->pc = 0x17e2e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5272));
    // 0x17e2ec: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E2ECu;
    {
        const bool branch_taken_0x17e2ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17E2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E2ECu;
            // 0x17e2f0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e2ec) {
            ctx->pc = 0x17E2FCu;
            goto label_17e2fc;
        }
    }
    ctx->pc = 0x17E2F4u;
    // 0x17e2f4: 0xc05f472  jal         func_17D1C8
    ctx->pc = 0x17E2F4u;
    SET_GPR_U32(ctx, 31, 0x17E2FCu);
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2FCu; }
        if (ctx->pc != 0x17E2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2FCu; }
        if (ctx->pc != 0x17E2FCu) { return; }
    }
    ctx->pc = 0x17E2FCu;
label_17e2fc:
    // 0x17e2fc: 0xe6140040  swc1        $f20, 0x40($s0)
    ctx->pc = 0x17e2fcu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 64), bits); }
    // 0x17e300: 0xe615003c  swc1        $f21, 0x3C($s0)
    ctx->pc = 0x17e300u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 60), bits); }
    // 0x17e304: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17e304u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e308: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e308u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e30c: 0xc7b50018  lwc1        $f21, 0x18($sp)
    ctx->pc = 0x17e30cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17e310: 0xc7b40010  lwc1        $f20, 0x10($sp)
    ctx->pc = 0x17e310u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17e314: 0x3e00008  jr          $ra
    ctx->pc = 0x17E314u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E314u;
            // 0x17e318: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E148u: goto label_17e148;
            case 0x17E170u: goto label_17e170;
            case 0x17E194u: goto label_17e194;
            case 0x17E1A8u: goto label_17e1a8;
            case 0x17E1D8u: goto label_17e1d8;
            case 0x17E1F8u: goto label_17e1f8;
            case 0x17E21Cu: goto label_17e21c;
            case 0x17E238u: goto label_17e238;
            case 0x17E250u: goto label_17e250;
            case 0x17E294u: goto label_17e294;
            case 0x17E2A0u: goto label_17e2a0;
            case 0x17E2DCu: goto label_17e2dc;
            case 0x17E2FCu: goto label_17e2fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E31Cu;
    // 0x17e31c: 0x0  nop
    ctx->pc = 0x17e31cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
