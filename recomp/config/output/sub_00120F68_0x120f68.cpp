#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00120F68
// Address: 0x120f68 - 0x1210b8
void sub_00120F68_0x120f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00120F68_0x120f68");
#endif

    ctx->pc = 0x120f68u;

    // 0x120f68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x120f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x120f6c: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x120f6cu;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x120f70: 0xe7a00000  swc1        $f0, 0x0($sp)
    ctx->pc = 0x120f70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x120f74: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x120f74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x120f78: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x120f78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x120f7c: 0x46006024  .word       0x46006024                   # cvt.w.s     $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x120f7cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[12]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x120f80: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x120f80u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x120f84: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x120f84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x120f88: 0x3c0231ff  lui         $v0, 0x31FF
    ctx->pc = 0x120f88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)12799 << 16));
    // 0x120f8c: 0xc31824  and         $v1, $a2, $v1
    ctx->pc = 0x120f8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x120f90: 0x3c043e99  lui         $a0, 0x3E99
    ctx->pc = 0x120f90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16025 << 16));
    // 0x120f94: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120f94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120f98: 0x34849999  ori         $a0, $a0, 0x9999
    ctx->pc = 0x120f98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)39321);
    // 0x120f9c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x120f9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x120fa0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x120FA0u;
    {
        const bool branch_taken_0x120fa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120FA0u;
            // 0x120fa4: 0x83202a  slt         $a0, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120fa0) {
            ctx->pc = 0x120FB8u;
            goto label_120fb8;
        }
    }
    ctx->pc = 0x120FA8u;
    // 0x120fa8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x120fa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x120fac: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120facu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120fb0: 0x10a0003f  beqz        $a1, . + 4 + (0x3F << 2)
    ctx->pc = 0x120FB0u;
    {
        const bool branch_taken_0x120fb0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x120fb0) {
            ctx->pc = 0x1210B0u;
            goto label_1210b0;
        }
    }
    ctx->pc = 0x120FB8u;
label_120fb8:
    // 0x120fb8: 0x460c6102  mul.s       $f4, $f12, $f12
    ctx->pc = 0x120fb8u;
    ctx->f[4] = FPU_MUL_S(ctx->f[12], ctx->f[12]);
    // 0x120fbc: 0x3c01ad47  lui         $at, 0xAD47
    ctx->pc = 0x120fbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44359 << 16));
    // 0x120fc0: 0x3421d74e  ori         $at, $at, 0xD74E
    ctx->pc = 0x120fc0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)55118);
    // 0x120fc4: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120fc4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120fc8: 0x3c01310f  lui         $at, 0x310F
    ctx->pc = 0x120fc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)12559 << 16));
    // 0x120fcc: 0x342174f5  ori         $at, $at, 0x74F5
    ctx->pc = 0x120fccu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)29941);
    // 0x120fd0: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120fd0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120fd4: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x120fd4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x120fd8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x120fd8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x120fdc: 0x3c01b493  lui         $at, 0xB493
    ctx->pc = 0x120fdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)46227 << 16));
    // 0x120fe0: 0x3421f27b  ori         $at, $at, 0xF27B
    ctx->pc = 0x120fe0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62075);
    // 0x120fe4: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120fe4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120fe8: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x120fe8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x120fec: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x120fecu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x120ff0: 0x3c0137d0  lui         $at, 0x37D0
    ctx->pc = 0x120ff0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14288 << 16));
    // 0x120ff4: 0x34210d00  ori         $at, $at, 0xD00
    ctx->pc = 0x120ff4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3328);
    // 0x120ff8: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120ff8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120ffc: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x120ffcu;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x121000: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x121000u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x121004: 0x3c01bab6  lui         $at, 0xBAB6
    ctx->pc = 0x121004u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)47798 << 16));
    // 0x121008: 0x34210b60  ori         $at, $at, 0xB60
    ctx->pc = 0x121008u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)2912);
    // 0x12100c: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x12100cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121010: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x121010u;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x121014: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x121014u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x121018: 0x3c013d2a  lui         $at, 0x3D2A
    ctx->pc = 0x121018u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15658 << 16));
    // 0x12101c: 0x3421aaaa  ori         $at, $at, 0xAAAA
    ctx->pc = 0x12101cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)43690);
    // 0x121020: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x121020u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121024: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x121024u;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x121028: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x121028u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x12102c: 0x1480000c  bnez        $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x12102Cu;
    {
        const bool branch_taken_0x12102c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x121030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12102Cu;
            // 0x121030: 0x46002042  mul.s       $f1, $f4, $f0 (Delay Slot)
        ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12102c) {
            ctx->pc = 0x121060u;
            goto label_121060;
        }
    }
    ctx->pc = 0x121034u;
    // 0x121034: 0x46012042  mul.s       $f1, $f4, $f1
    ctx->pc = 0x121034u;
    ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[1]);
    // 0x121038: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x121038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x12103c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12103cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x121040: 0x460d6082  mul.s       $f2, $f12, $f13
    ctx->pc = 0x121040u;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[13]);
    // 0x121044: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x121044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x121048: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x121048u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x12104c: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x12104cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x121050: 0x46020841  sub.s       $f1, $f1, $f2
    ctx->pc = 0x121050u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[2]);
    // 0x121054: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x121054u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x121058: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x121058u;
    {
        const bool branch_taken_0x121058 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12105Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121058u;
            // 0x12105c: 0x46001801  sub.s       $f0, $f3, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[3], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x121058) {
            ctx->pc = 0x1210B0u;
            goto label_1210b0;
        }
    }
    ctx->pc = 0x121060u;
label_121060:
    // 0x121060: 0x3c023f48  lui         $v0, 0x3F48
    ctx->pc = 0x121060u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16200 << 16));
    // 0x121064: 0x3c013e90  lui         $at, 0x3E90
    ctx->pc = 0x121064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16016 << 16));
    // 0x121068: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x121068u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x12106c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x12106cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x121070: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x121070u;
    {
        const bool branch_taken_0x121070 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x121074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121070u;
            // 0x121074: 0x3c02ff00  lui         $v0, 0xFF00 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121070) {
            ctx->pc = 0x121080u;
            goto label_121080;
        }
    }
    ctx->pc = 0x121078u;
    // 0x121078: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x121078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12107c: 0x44832800  mtc1        $v1, $f5
    ctx->pc = 0x12107cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
label_121080:
    // 0x121080: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x121080u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x121084: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x121084u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x121088: 0x46012082  mul.s       $f2, $f4, $f1
    ctx->pc = 0x121088u;
    ctx->f[2] = FPU_MUL_S(ctx->f[4], ctx->f[1]);
    // 0x12108c: 0x460d60c2  mul.s       $f3, $f12, $f13
    ctx->pc = 0x12108cu;
    ctx->f[3] = FPU_MUL_S(ctx->f[12], ctx->f[13]);
    // 0x121090: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x121090u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x121094: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x121094u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121098: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x121098u;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x12109c: 0x46050841  sub.s       $f1, $f1, $f5
    ctx->pc = 0x12109cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[5]);
    // 0x1210a0: 0x46031081  sub.s       $f2, $f2, $f3
    ctx->pc = 0x1210a0u;
    ctx->f[2] = FPU_SUB_S(ctx->f[2], ctx->f[3]);
    // 0x1210a4: 0x46050001  sub.s       $f0, $f0, $f5
    ctx->pc = 0x1210a4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[5]);
    // 0x1210a8: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x1210a8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x1210ac: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1210acu;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
label_1210b0:
    // 0x1210b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1210B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1210B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1210B0u;
            // 0x1210b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x120FB8u: goto label_120fb8;
            case 0x121060u: goto label_121060;
            case 0x121080u: goto label_121080;
            case 0x1210B0u: goto label_1210b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1210B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
