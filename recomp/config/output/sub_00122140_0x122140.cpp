#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122140
// Address: 0x122140 - 0x1223d0
void sub_00122140_0x122140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122140_0x122140");
#endif

    switch (ctx->pc) {
        case 0x122200u: goto label_122200;
        default: break;
    }

    ctx->pc = 0x122140u;

    // 0x122140: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x122140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x122144: 0x46006346  mov.s       $f13, $f12
    ctx->pc = 0x122144u;
    ctx->f[13] = FPU_MOV_S(ctx->f[12]);
    // 0x122148: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x122148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12214c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12214cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x122150: 0x44116800  mfc1        $s1, $f13
    ctx->pc = 0x122150u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x122154: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x122154u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x122158: 0x3c02507f  lui         $v0, 0x507F
    ctx->pc = 0x122158u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20607 << 16));
    // 0x12215c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x12215cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x122160: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x122164: 0x2238024  and         $s0, $s1, $v1
    ctx->pc = 0x122164u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x122168: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x122168u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12216c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x12216Cu;
    {
        const bool branch_taken_0x12216c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12216Cu;
            // 0x122170: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12216c) {
            ctx->pc = 0x1221A8u;
            goto label_1221a8;
        }
    }
    ctx->pc = 0x122174u;
    // 0x122174: 0x1a200006  blez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x122174u;
    {
        const bool branch_taken_0x122174 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x122178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122174u;
            // 0x122178: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122174) {
            ctx->pc = 0x122190u;
            goto label_122190;
        }
    }
    ctx->pc = 0x12217Cu;
    // 0x12217c: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x12217cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x122180: 0xc44192c4  lwc1        $f1, -0x6D3C($v0)
    ctx->pc = 0x122180u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294939332)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x122184: 0xc46092d4  lwc1        $f0, -0x6D2C($v1)
    ctx->pc = 0x122184u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4294939348)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x122188: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x122188u;
    {
        const bool branch_taken_0x122188 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12218Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122188u;
            // 0x12218c: 0x46000800  add.s       $f0, $f1, $f0 (Delay Slot)
        ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122188) {
            ctx->pc = 0x1223B8u;
            goto label_1223b8;
        }
    }
    ctx->pc = 0x122190u;
label_122190:
    // 0x122190: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x122190u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x122194: 0xc44092c4  lwc1        $f0, -0x6D3C($v0)
    ctx->pc = 0x122194u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294939332)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x122198: 0xc46192d4  lwc1        $f1, -0x6D2C($v1)
    ctx->pc = 0x122198u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4294939348)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x12219c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x12219cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x1221a0: 0x10000085  b           . + 4 + (0x85 << 2)
    ctx->pc = 0x1221A0u;
    {
        const bool branch_taken_0x1221a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1221A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1221A0u;
            // 0x1221a4: 0x46010001  sub.s       $f0, $f0, $f1 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1221a0) {
            ctx->pc = 0x1223B8u;
            goto label_1223b8;
        }
    }
    ctx->pc = 0x1221A8u;
label_1221a8:
    // 0x1221a8: 0x3c023edf  lui         $v0, 0x3EDF
    ctx->pc = 0x1221a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16095 << 16));
    // 0x1221ac: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1221acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1221b0: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x1221b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1221b4: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1221B4u;
    {
        const bool branch_taken_0x1221b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1221B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1221B4u;
            // 0x1221b8: 0x3c0230ff  lui         $v0, 0x30FF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)12543 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1221b4) {
            ctx->pc = 0x1221F8u;
            goto label_1221f8;
        }
    }
    ctx->pc = 0x1221BCu;
    // 0x1221bc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1221bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1221c0: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x1221c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1221c4: 0x14400045  bnez        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1221C4u;
    {
        const bool branch_taken_0x1221c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1221C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1221C4u;
            // 0x1221c8: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1221c4) {
            ctx->pc = 0x1222DCu;
            goto label_1222dc;
        }
    }
    ctx->pc = 0x1221CCu;
    // 0x1221cc: 0x3c017149  lui         $at, 0x7149
    ctx->pc = 0x1221ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)29001 << 16));
    // 0x1221d0: 0x3421f2c9  ori         $at, $at, 0xF2C9
    ctx->pc = 0x1221d0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62153);
    // 0x1221d4: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1221d4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1221d8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1221d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1221dc: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1221dcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1221e0: 0x46016840  add.s       $f1, $f13, $f1
    ctx->pc = 0x1221e0u;
    ctx->f[1] = FPU_ADD_S(ctx->f[13], ctx->f[1]);
    // 0x1221e4: 0x46011034  c.lt.s      $f2, $f1
    ctx->pc = 0x1221e4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[2], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1221e8: 0x45010073  bc1t        . + 4 + (0x73 << 2)
    ctx->pc = 0x1221E8u;
    {
        const bool branch_taken_0x1221e8 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1221ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1221E8u;
            // 0x1221ec: 0x46006806  mov.s       $f0, $f13 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1221e8) {
            ctx->pc = 0x1223B8u;
            goto label_1223b8;
        }
    }
    ctx->pc = 0x1221F0u;
    // 0x1221f0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1221F0u;
    {
        const bool branch_taken_0x1221f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1221F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1221F0u;
            // 0x1221f4: 0x460d6b02  mul.s       $f12, $f13, $f13 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[13], ctx->f[13]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1221f0) {
            ctx->pc = 0x1222E0u;
            goto label_1222e0;
        }
    }
    ctx->pc = 0x1221F8u;
label_1221f8:
    // 0x1221f8: 0xc04892a  jal         func_1224A8
    ctx->pc = 0x1221F8u;
    SET_GPR_U32(ctx, 31, 0x122200u);
    ctx->pc = 0x1224A8u;
    if (runtime->hasFunction(0x1224A8u)) {
        auto targetFn = runtime->lookupFunction(0x1224A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122200u; }
        if (ctx->pc != 0x122200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001224A8_0x1224a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122200u; }
        if (ctx->pc != 0x122200u) { return; }
    }
    ctx->pc = 0x122200u;
label_122200:
    // 0x122200: 0x3c023f97  lui         $v0, 0x3F97
    ctx->pc = 0x122200u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16279 << 16));
    // 0x122204: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x122208: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x122208u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12220c: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x12220Cu;
    {
        const bool branch_taken_0x12220c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x122210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12220Cu;
            // 0x122210: 0x46000346  mov.s       $f13, $f0 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12220c) {
            ctx->pc = 0x122280u;
            goto label_122280;
        }
    }
    ctx->pc = 0x122214u;
    // 0x122214: 0x3c023f2f  lui         $v0, 0x3F2F
    ctx->pc = 0x122214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16175 << 16));
    // 0x122218: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x12221c: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x12221cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x122220: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x122220u;
    {
        const bool branch_taken_0x122220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x122220) {
            ctx->pc = 0x122258u;
            goto label_122258;
        }
    }
    ctx->pc = 0x122228u;
    // 0x122228: 0x460d6800  add.s       $f0, $f13, $f13
    ctx->pc = 0x122228u;
    ctx->f[0] = FPU_ADD_S(ctx->f[13], ctx->f[13]);
    // 0x12222c: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x12222cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x122230: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x122230u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x122234: 0x3c014000  lui         $at, 0x4000
    ctx->pc = 0x122234u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16384 << 16));
    // 0x122238: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x122238u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x12223c: 0x46016840  add.s       $f1, $f13, $f1
    ctx->pc = 0x12223cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[13], ctx->f[1]);
    // 0x122240: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x122240u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x122244: 0x0  nop
    ctx->pc = 0x122244u;
    // NOP
    // 0x122248: 0x0  nop
    ctx->pc = 0x122248u;
    // NOP
    // 0x12224c: 0x46010343  div.s       $f13, $f0, $f1
    ctx->pc = 0x12224cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[13] = std::bit_cast<float>(__maxf); } else ctx->f[13] = ctx->f[0] / ctx->f[1];
    // 0x122250: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x122250u;
    {
        const bool branch_taken_0x122250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122250u;
            // 0x122254: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122250) {
            ctx->pc = 0x1222DCu;
            goto label_1222dc;
        }
    }
    ctx->pc = 0x122258u;
label_122258:
    // 0x122258: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x122258u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x12225c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12225cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x122260: 0x46006840  add.s       $f1, $f13, $f0
    ctx->pc = 0x122260u;
    ctx->f[1] = FPU_ADD_S(ctx->f[13], ctx->f[0]);
    // 0x122264: 0x46006801  sub.s       $f0, $f13, $f0
    ctx->pc = 0x122264u;
    ctx->f[0] = FPU_SUB_S(ctx->f[13], ctx->f[0]);
    // 0x122268: 0x0  nop
    ctx->pc = 0x122268u;
    // NOP
    // 0x12226c: 0x0  nop
    ctx->pc = 0x12226cu;
    // NOP
    // 0x122270: 0x46010343  div.s       $f13, $f0, $f1
    ctx->pc = 0x122270u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[13] = std::bit_cast<float>(__maxf); } else ctx->f[13] = ctx->f[0] / ctx->f[1];
    // 0x122274: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x122274u;
    {
        const bool branch_taken_0x122274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122274u;
            // 0x122278: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122274) {
            ctx->pc = 0x1222DCu;
            goto label_1222dc;
        }
    }
    ctx->pc = 0x12227Cu;
    // 0x12227c: 0x0  nop
    ctx->pc = 0x12227cu;
    // NOP
label_122280:
    // 0x122280: 0x3c02401b  lui         $v0, 0x401B
    ctx->pc = 0x122280u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16411 << 16));
    // 0x122284: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x122284u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x122288: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x122288u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12228c: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x12228Cu;
    {
        const bool branch_taken_0x12228c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12228c) {
            ctx->pc = 0x122290u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12228Cu;
            // 0x122290: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1222C8u;
            goto label_1222c8;
        }
    }
    ctx->pc = 0x122294u;
    // 0x122294: 0x3c013fc0  lui         $at, 0x3FC0
    ctx->pc = 0x122294u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16320 << 16));
    // 0x122298: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x122298u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x12229c: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x12229cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1222a0: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1222a0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1222a4: 0x46006842  mul.s       $f1, $f13, $f0
    ctx->pc = 0x1222a4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[0]);
    // 0x1222a8: 0x46006801  sub.s       $f0, $f13, $f0
    ctx->pc = 0x1222a8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[13], ctx->f[0]);
    // 0x1222ac: 0x46020840  add.s       $f1, $f1, $f2
    ctx->pc = 0x1222acu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x1222b0: 0x0  nop
    ctx->pc = 0x1222b0u;
    // NOP
    // 0x1222b4: 0x0  nop
    ctx->pc = 0x1222b4u;
    // NOP
    // 0x1222b8: 0x46010343  div.s       $f13, $f0, $f1
    ctx->pc = 0x1222b8u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[13] = std::bit_cast<float>(__maxf); } else ctx->f[13] = ctx->f[0] / ctx->f[1];
    // 0x1222bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1222BCu;
    {
        const bool branch_taken_0x1222bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1222C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1222BCu;
            // 0x1222c0: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1222bc) {
            ctx->pc = 0x1222DCu;
            goto label_1222dc;
        }
    }
    ctx->pc = 0x1222C4u;
    // 0x1222c4: 0x0  nop
    ctx->pc = 0x1222c4u;
    // NOP
label_1222c8:
    // 0x1222c8: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x1222c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x1222cc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1222ccu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1222d0: 0x0  nop
    ctx->pc = 0x1222d0u;
    // NOP
    // 0x1222d4: 0x0  nop
    ctx->pc = 0x1222d4u;
    // NOP
    // 0x1222d8: 0x460d0343  div.s       $f13, $f0, $f13
    ctx->pc = 0x1222d8u;
    if (ctx->f[13] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[13])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[13] = std::bit_cast<float>(__maxf); } else ctx->f[13] = ctx->f[0] / ctx->f[13];
label_1222dc:
    // 0x1222dc: 0x460d6b02  mul.s       $f12, $f13, $f13
    ctx->pc = 0x1222dcu;
    ctx->f[12] = FPU_MUL_S(ctx->f[13], ctx->f[13]);
label_1222e0:
    // 0x1222e0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1222e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1222e4: 0x244292d8  addiu       $v0, $v0, -0x6D28
    ctx->pc = 0x1222e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939352));
    // 0x1222e8: 0xc4470028  lwc1        $f7, 0x28($v0)
    ctx->pc = 0x1222e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1222ec: 0xc4440020  lwc1        $f4, 0x20($v0)
    ctx->pc = 0x1222ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1222f0: 0x460c6002  mul.s       $f0, $f12, $f12
    ctx->pc = 0x1222f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[12]);
    // 0x1222f4: 0xc4450024  lwc1        $f5, 0x24($v0)
    ctx->pc = 0x1222f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x1222f8: 0xc4460018  lwc1        $f6, 0x18($v0)
    ctx->pc = 0x1222f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x1222fc: 0xc441001c  lwc1        $f1, 0x1C($v0)
    ctx->pc = 0x1222fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x122300: 0xc4480010  lwc1        $f8, 0x10($v0)
    ctx->pc = 0x122300u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[8] = f; }
    // 0x122304: 0x460701c2  mul.s       $f7, $f0, $f7
    ctx->pc = 0x122304u;
    ctx->f[7] = FPU_MUL_S(ctx->f[0], ctx->f[7]);
    // 0x122308: 0xc4420014  lwc1        $f2, 0x14($v0)
    ctx->pc = 0x122308u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x12230c: 0x46050142  mul.s       $f5, $f0, $f5
    ctx->pc = 0x12230cu;
    ctx->f[5] = FPU_MUL_S(ctx->f[0], ctx->f[5]);
    // 0x122310: 0xc4490008  lwc1        $f9, 0x8($v0)
    ctx->pc = 0x122310u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[9] = f; }
    // 0x122314: 0xc443000c  lwc1        $f3, 0xC($v0)
    ctx->pc = 0x122314u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x122318: 0xc44a0004  lwc1        $f10, 0x4($v0)
    ctx->pc = 0x122318u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[10] = f; }
    // 0x12231c: 0x46072100  add.s       $f4, $f4, $f7
    ctx->pc = 0x12231cu;
    ctx->f[4] = FPU_ADD_S(ctx->f[4], ctx->f[7]);
    // 0x122320: 0xc44b0000  lwc1        $f11, 0x0($v0)
    ctx->pc = 0x122320u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[11] = f; }
    // 0x122324: 0x46050840  add.s       $f1, $f1, $f5
    ctx->pc = 0x122324u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x122328: 0x46040102  mul.s       $f4, $f0, $f4
    ctx->pc = 0x122328u;
    ctx->f[4] = FPU_MUL_S(ctx->f[0], ctx->f[4]);
    // 0x12232c: 0x46010042  mul.s       $f1, $f0, $f1
    ctx->pc = 0x12232cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x122330: 0x46043180  add.s       $f6, $f6, $f4
    ctx->pc = 0x122330u;
    ctx->f[6] = FPU_ADD_S(ctx->f[6], ctx->f[4]);
    // 0x122334: 0x46011080  add.s       $f2, $f2, $f1
    ctx->pc = 0x122334u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x122338: 0x46060182  mul.s       $f6, $f0, $f6
    ctx->pc = 0x122338u;
    ctx->f[6] = FPU_MUL_S(ctx->f[0], ctx->f[6]);
    // 0x12233c: 0x46020082  mul.s       $f2, $f0, $f2
    ctx->pc = 0x12233cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x122340: 0x46064200  add.s       $f8, $f8, $f6
    ctx->pc = 0x122340u;
    ctx->f[8] = FPU_ADD_S(ctx->f[8], ctx->f[6]);
    // 0x122344: 0x460218c0  add.s       $f3, $f3, $f2
    ctx->pc = 0x122344u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[2]);
    // 0x122348: 0x46080202  mul.s       $f8, $f0, $f8
    ctx->pc = 0x122348u;
    ctx->f[8] = FPU_MUL_S(ctx->f[0], ctx->f[8]);
    // 0x12234c: 0x460300c2  mul.s       $f3, $f0, $f3
    ctx->pc = 0x12234cu;
    ctx->f[3] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x122350: 0x46084a40  add.s       $f9, $f9, $f8
    ctx->pc = 0x122350u;
    ctx->f[9] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x122354: 0x46035280  add.s       $f10, $f10, $f3
    ctx->pc = 0x122354u;
    ctx->f[10] = FPU_ADD_S(ctx->f[10], ctx->f[3]);
    // 0x122358: 0x46090242  mul.s       $f9, $f0, $f9
    ctx->pc = 0x122358u;
    ctx->f[9] = FPU_MUL_S(ctx->f[0], ctx->f[9]);
    // 0x12235c: 0x460a0042  mul.s       $f1, $f0, $f10
    ctx->pc = 0x12235cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[10]);
    // 0x122360: 0x46095ac0  add.s       $f11, $f11, $f9
    ctx->pc = 0x122360u;
    ctx->f[11] = FPU_ADD_S(ctx->f[11], ctx->f[9]);
    // 0x122364: 0x4610006  bgez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x122364u;
    {
        const bool branch_taken_0x122364 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x122368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122364u;
            // 0x122368: 0x460b6002  mul.s       $f0, $f12, $f11 (Delay Slot)
        ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[11]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122364) {
            ctx->pc = 0x122380u;
            goto label_122380;
        }
    }
    ctx->pc = 0x12236Cu;
    // 0x12236c: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x12236cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x122370: 0x46006802  mul.s       $f0, $f13, $f0
    ctx->pc = 0x122370u;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[0]);
    // 0x122374: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x122374u;
    {
        const bool branch_taken_0x122374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x122378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122374u;
            // 0x122378: 0x46006801  sub.s       $f0, $f13, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[13], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x122374) {
            ctx->pc = 0x1223B8u;
            goto label_1223b8;
        }
    }
    ctx->pc = 0x12237Cu;
    // 0x12237c: 0x0  nop
    ctx->pc = 0x12237cu;
    // NOP
label_122380:
    // 0x122380: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x122380u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x122384: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x122384u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x122388: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x122388u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x12238c: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x12238cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x122390: 0xc42192c8  lwc1        $f1, -0x6D38($at)
    ctx->pc = 0x122390u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294939336)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x122394: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x122394u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x122398: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x122398u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x12239c: 0xc42292b8  lwc1        $f2, -0x6D48($at)
    ctx->pc = 0x12239cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294939320)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1223a0: 0x46006802  mul.s       $f0, $f13, $f0
    ctx->pc = 0x1223a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[0]);
    // 0x1223a4: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x1223a4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1223a8: 0x460d0001  sub.s       $f0, $f0, $f13
    ctx->pc = 0x1223a8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[13]);
    // 0x1223ac: 0x6210002  bgez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1223ACu;
    {
        const bool branch_taken_0x1223ac = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1223B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1223ACu;
            // 0x1223b0: 0x46001001  sub.s       $f0, $f2, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1223ac) {
            ctx->pc = 0x1223B8u;
            goto label_1223b8;
        }
    }
    ctx->pc = 0x1223B4u;
    // 0x1223b4: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x1223b4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
label_1223b8:
    // 0x1223b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1223b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1223bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1223bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1223c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1223c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1223c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1223C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1223C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1223C4u;
            // 0x1223c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122190u: goto label_122190;
            case 0x1221A8u: goto label_1221a8;
            case 0x1221F8u: goto label_1221f8;
            case 0x122200u: goto label_122200;
            case 0x122258u: goto label_122258;
            case 0x122280u: goto label_122280;
            case 0x1222C8u: goto label_1222c8;
            case 0x1222DCu: goto label_1222dc;
            case 0x1222E0u: goto label_1222e0;
            case 0x122380u: goto label_122380;
            case 0x1223B8u: goto label_1223b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1223CCu;
    // 0x1223cc: 0x0  nop
    ctx->pc = 0x1223ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
