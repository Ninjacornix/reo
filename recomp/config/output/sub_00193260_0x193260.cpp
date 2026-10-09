#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193260
// Address: 0x193260 - 0x193380
void sub_00193260_0x193260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193260_0x193260");
#endif

    switch (ctx->pc) {
        case 0x1932b8u: goto label_1932b8;
        case 0x1932c0u: goto label_1932c0;
        case 0x193304u: goto label_193304;
        case 0x193310u: goto label_193310;
        case 0x19331cu: goto label_19331c;
        case 0x193338u: goto label_193338;
        case 0x193354u: goto label_193354;
        default: break;
    }

    ctx->pc = 0x193260u;

label_193260:
    // 0x193260: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x193260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x193264: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x193264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x193268: 0x7fb10030  sq          $s1, 0x30($sp)
    ctx->pc = 0x193268u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 17));
    // 0x19326c: 0x7fb00020  sq          $s0, 0x20($sp)
    ctx->pc = 0x19326cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 16));
    // 0x193270: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x193270u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193274: 0xe7b90014  swc1        $f25, 0x14($sp)
    ctx->pc = 0x193274u;
    { float f = ctx->f[25]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x193278: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x193278u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19327c: 0xe7b80010  swc1        $f24, 0x10($sp)
    ctx->pc = 0x19327cu;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x193280: 0xe7b7000c  swc1        $f23, 0xC($sp)
    ctx->pc = 0x193280u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 12), bits); }
    // 0x193284: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x193284u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x193288: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x193288u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x19328c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x19328cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193290: 0xc4960104  lwc1        $f22, 0x104($a0)
    ctx->pc = 0x193290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 260)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193294: 0xc4950108  lwc1        $f21, 0x108($a0)
    ctx->pc = 0x193294u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 264)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x193298: 0xc494010c  lwc1        $f20, 0x10C($a0)
    ctx->pc = 0x193298u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 268)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x19329c: 0x46006646  mov.s       $f25, $f12
    ctx->pc = 0x19329cu;
    ctx->f[25] = FPU_MOV_S(ctx->f[12]);
    // 0x1932a0: 0x46006e06  mov.s       $f24, $f13
    ctx->pc = 0x1932a0u;
    ctx->f[24] = FPU_MOV_S(ctx->f[13]);
    // 0x1932a4: 0x460075c6  mov.s       $f23, $f14
    ctx->pc = 0x1932a4u;
    ctx->f[23] = FPU_MOV_S(ctx->f[14]);
    // 0x1932a8: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x1932a8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x1932ac: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x1932acu;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x1932b0: 0xc063f98  jal         func_18FE60
    ctx->pc = 0x1932B0u;
    SET_GPR_U32(ctx, 31, 0x1932B8u);
    ctx->pc = 0x1932B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1932B0u;
            // 0x1932b4: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE60u;
    if (runtime->hasFunction(0x18FE60u)) {
        auto targetFn = runtime->lookupFunction(0x18FE60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1932B8u; }
        if (ctx->pc != 0x1932B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE60_0x18fe60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1932B8u; }
        if (ctx->pc != 0x1932B8u) { return; }
    }
    ctx->pc = 0x1932B8u;
label_1932b8:
    // 0x1932b8: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x1932B8u;
    SET_GPR_U32(ctx, 31, 0x1932C0u);
    ctx->pc = 0x1932BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1932B8u;
            // 0x1932bc: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1932C0u; }
        if (ctx->pc != 0x1932C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1932C0u; }
        if (ctx->pc != 0x1932C0u) { return; }
    }
    ctx->pc = 0x1932C0u;
label_1932c0:
    // 0x1932c0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1932c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x1932c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1932c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1932c8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1932c8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1932cc: 0x26250040  addiu       $a1, $s1, 0x40
    ctx->pc = 0x1932ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
    // 0x1932d0: 0x46190803  div.s       $f0, $f1, $f25
    ctx->pc = 0x1932d0u;
    if (ctx->f[25] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[25])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[25];
    // 0x1932d4: 0xe7a00050  swc1        $f0, 0x50($sp)
    ctx->pc = 0x1932d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x1932d8: 0x46180803  div.s       $f0, $f1, $f24
    ctx->pc = 0x1932d8u;
    if (ctx->f[24] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[24])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[24];
    // 0x1932dc: 0xe7a00064  swc1        $f0, 0x64($sp)
    ctx->pc = 0x1932dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x1932e0: 0x46170803  div.s       $f0, $f1, $f23
    ctx->pc = 0x1932e0u;
    if (ctx->f[23] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[23])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[23];
    // 0x1932e4: 0xe7a00078  swc1        $f0, 0x78($sp)
    ctx->pc = 0x1932e4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x1932e8: 0xc6200070  lwc1        $f0, 0x70($s1)
    ctx->pc = 0x1932e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1932ec: 0xe7a00080  swc1        $f0, 0x80($sp)
    ctx->pc = 0x1932ecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x1932f0: 0xc6200074  lwc1        $f0, 0x74($s1)
    ctx->pc = 0x1932f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 116)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1932f4: 0xe7a00084  swc1        $f0, 0x84($sp)
    ctx->pc = 0x1932f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x1932f8: 0xc6200078  lwc1        $f0, 0x78($s1)
    ctx->pc = 0x1932f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1932fc: 0xc0644f8  jal         func_1913E0
    ctx->pc = 0x1932FCu;
    SET_GPR_U32(ctx, 31, 0x193304u);
    ctx->pc = 0x193300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1932FCu;
            // 0x193300: 0xe7a00088  swc1        $f0, 0x88($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1913E0u;
    if (runtime->hasFunction(0x1913E0u)) {
        auto targetFn = runtime->lookupFunction(0x1913E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193304u; }
        if (ctx->pc != 0x193304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001913E0_0x1913e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193304u; }
        if (ctx->pc != 0x193304u) { return; }
    }
    ctx->pc = 0x193304u;
label_193304:
    // 0x193304: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193308: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193308u;
    SET_GPR_U32(ctx, 31, 0x193310u);
    ctx->pc = 0x19330Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193308u;
            // 0x19330c: 0x27a50050  addiu       $a1, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193310u; }
        if (ctx->pc != 0x193310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193310u; }
        if (ctx->pc != 0x193310u) { return; }
    }
    ctx->pc = 0x193310u;
label_193310:
    // 0x193310: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193310u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193314: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193314u;
    SET_GPR_U32(ctx, 31, 0x19331Cu);
    ctx->pc = 0x193318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193314u;
            // 0x193318: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19331Cu; }
        if (ctx->pc != 0x19331Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19331Cu; }
        if (ctx->pc != 0x19331Cu) { return; }
    }
    ctx->pc = 0x19331Cu;
label_19331c:
    // 0x19331c: 0x8e2400d0  lw          $a0, 0xD0($s1)
    ctx->pc = 0x19331cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x193320: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x193320u;
    {
        const bool branch_taken_0x193320 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x193324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193320u;
            // 0x193324: 0x4600b306  mov.s       $f12, $f22 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[22]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x193320) {
            ctx->pc = 0x193338u;
            goto label_193338;
        }
    }
    ctx->pc = 0x193328u;
    // 0x193328: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x193328u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19332c: 0x4600ab46  mov.s       $f13, $f21
    ctx->pc = 0x19332cu;
    ctx->f[13] = FPU_MOV_S(ctx->f[21]);
    // 0x193330: 0xc064c98  jal         func_193260
    ctx->pc = 0x193330u;
    SET_GPR_U32(ctx, 31, 0x193338u);
    ctx->pc = 0x193334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193330u;
            // 0x193334: 0x4600a386  mov.s       $f14, $f20 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193260u;
    goto label_193260;
    ctx->pc = 0x193338u;
label_193338:
    // 0x193338: 0x8e2400cc  lw          $a0, 0xCC($s1)
    ctx->pc = 0x193338u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x19333c: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x19333Cu;
    {
        const bool branch_taken_0x19333c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x193340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19333Cu;
            // 0x193340: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19333c) {
            ctx->pc = 0x193354u;
            goto label_193354;
        }
    }
    ctx->pc = 0x193344u;
    // 0x193344: 0x4600cb06  mov.s       $f12, $f25
    ctx->pc = 0x193344u;
    ctx->f[12] = FPU_MOV_S(ctx->f[25]);
    // 0x193348: 0x4600c346  mov.s       $f13, $f24
    ctx->pc = 0x193348u;
    ctx->f[13] = FPU_MOV_S(ctx->f[24]);
    // 0x19334c: 0xc064c98  jal         func_193260
    ctx->pc = 0x19334Cu;
    SET_GPR_U32(ctx, 31, 0x193354u);
    ctx->pc = 0x193350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19334Cu;
            // 0x193350: 0x4600bb86  mov.s       $f14, $f23 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[23]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193260u;
    goto label_193260;
    ctx->pc = 0x193354u;
label_193354:
    // 0x193354: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x193354u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x193358: 0xc7b90014  lwc1        $f25, 0x14($sp)
    ctx->pc = 0x193358u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[25] = f; }
    // 0x19335c: 0x7bb10030  lq          $s1, 0x30($sp)
    ctx->pc = 0x19335cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193360: 0xc7b80010  lwc1        $f24, 0x10($sp)
    ctx->pc = 0x193360u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[24] = f; }
    // 0x193364: 0x7bb00020  lq          $s0, 0x20($sp)
    ctx->pc = 0x193364u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193368: 0xc7b7000c  lwc1        $f23, 0xC($sp)
    ctx->pc = 0x193368u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[23] = f; }
    // 0x19336c: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x19336cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193370: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x193370u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x193374: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193374u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193378: 0x3e00008  jr          $ra
    ctx->pc = 0x193378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19337Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193378u;
            // 0x19337c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193260u: goto label_193260;
            case 0x1932B8u: goto label_1932b8;
            case 0x1932C0u: goto label_1932c0;
            case 0x193304u: goto label_193304;
            case 0x193310u: goto label_193310;
            case 0x19331Cu: goto label_19331c;
            case 0x193338u: goto label_193338;
            case 0x193354u: goto label_193354;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
