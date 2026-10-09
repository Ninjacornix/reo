#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B96D0
// Address: 0x1b96d0 - 0x1b9810
void sub_001B96D0_0x1b96d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B96D0_0x1b96d0");
#endif

    switch (ctx->pc) {
        case 0x1b96fcu: goto label_1b96fc;
        case 0x1b97a8u: goto label_1b97a8;
        case 0x1b9800u: goto label_1b9800;
        default: break;
    }

    ctx->pc = 0x1b96d0u;

    // 0x1b96d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b96d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b96d4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b96d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b96d8: 0x3c07003c  lui         $a3, 0x3C
    ctx->pc = 0x1b96d8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)60 << 16));
    // 0x1b96dc: 0x3c06003c  lui         $a2, 0x3C
    ctx->pc = 0x1b96dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)60 << 16));
    // 0x1b96e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b96e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b96e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b96e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b96e8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b96e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b96ec: 0x24844c50  addiu       $a0, $a0, 0x4C50
    ctx->pc = 0x1b96ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19536));
    // 0x1b96f0: 0x24e72750  addiu       $a3, $a3, 0x2750
    ctx->pc = 0x1b96f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10064));
    // 0x1b96f4: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1B96F4u;
    {
        const bool branch_taken_0x1b96f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B96F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B96F4u;
            // 0x1b96f8: 0x24c63000  addiu       $a2, $a2, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 12288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b96f4) {
            ctx->pc = 0x1B97C8u;
            goto label_1b97c8;
        }
    }
    ctx->pc = 0x1B96FCu;
label_1b96fc:
    // 0x1b96fc: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b96fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1b9700: 0x1024023  subu        $t0, $t0, $v0
    ctx->pc = 0x1b9700u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1b9704: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1b9704u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b9708: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x1b9708u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b970c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b970cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9710: 0xe84821  addu        $t1, $a3, $t0
    ctx->pc = 0x1b9710u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1b9714: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x1b9714u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b9718: 0xa1200000  sb          $zero, 0x0($t1)
    ctx->pc = 0x1b9718u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b971c: 0x24680d00  addiu       $t0, $v1, 0xD00
    ctx->pc = 0x1b971cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 3328));
    // 0x1b9720: 0xa1200007  sb          $zero, 0x7($t1)
    ctx->pc = 0x1b9720u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 7), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9724: 0xa1200006  sb          $zero, 0x6($t1)
    ctx->pc = 0x1b9724u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 6), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9728: 0xa1200005  sb          $zero, 0x5($t1)
    ctx->pc = 0x1b9728u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 5), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b972c: 0xa1200004  sb          $zero, 0x4($t1)
    ctx->pc = 0x1b972cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9730: 0x90630d00  lbu         $v1, 0xD00($v1)
    ctx->pc = 0x1b9730u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3328)));
    // 0x1b9734: 0x10600023  beqz        $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1B9734u;
    {
        const bool branch_taken_0x1b9734 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9734) {
            ctx->pc = 0x1B97C4u;
            goto label_1b97c4;
        }
    }
    ctx->pc = 0x1B973Cu;
    // 0x1b973c: 0xa1250000  sb          $a1, 0x0($t1)
    ctx->pc = 0x1b973cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b9740: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x1b9740u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x1b9744: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x1b9744u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x1b9748: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x1b9748u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b974c: 0xa1230001  sb          $v1, 0x1($t1)
    ctx->pc = 0x1b974cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9750: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x1b9750u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x1b9754: 0xa1230002  sb          $v1, 0x2($t1)
    ctx->pc = 0x1b9754u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9758: 0x95030004  lhu         $v1, 0x4($t0)
    ctx->pc = 0x1b9758u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1b975c: 0x3063000f  andi        $v1, $v1, 0xF
    ctx->pc = 0x1b975cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1b9760: 0xa1230003  sb          $v1, 0x3($t1)
    ctx->pc = 0x1b9760u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9764: 0xad280024  sw          $t0, 0x24($t1)
    ctx->pc = 0x1b9764u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 36), GPR_U32(ctx, 8));
    // 0x1b9768: 0x81230003  lb          $v1, 0x3($t1)
    ctx->pc = 0x1b9768u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
    // 0x1b976c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b976cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9770: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b9770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b9774: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b9774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9778: 0xad230028  sw          $v1, 0x28($t1)
    ctx->pc = 0x1b9778u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 40), GPR_U32(ctx, 3));
    // 0x1b977c: 0x91030001  lbu         $v1, 0x1($t0)
    ctx->pc = 0x1b977cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x1b9780: 0xa5230038  sh          $v1, 0x38($t1)
    ctx->pc = 0x1b9780u;
    WRITE16(ADD32(GPR_U32(ctx, 9), 56), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9784: 0xc5020008  lwc1        $f2, 0x8($t0)
    ctx->pc = 0x1b9784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b9788: 0xc501000c  lwc1        $f1, 0xC($t0)
    ctx->pc = 0x1b9788u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b978c: 0xc5000010  lwc1        $f0, 0x10($t0)
    ctx->pc = 0x1b978cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9790: 0xe522002c  swc1        $f2, 0x2C($t1)
    ctx->pc = 0x1b9790u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 44), bits); }
    // 0x1b9794: 0xe5210030  swc1        $f1, 0x30($t1)
    ctx->pc = 0x1b9794u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 48), bits); }
    // 0x1b9798: 0xe5200034  swc1        $f0, 0x34($t1)
    ctx->pc = 0x1b9798u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 52), bits); }
    // 0x1b979c: 0x8d230028  lw          $v1, 0x28($t1)
    ctx->pc = 0x1b979cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 40)));
    // 0x1b97a0: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B97A0u;
    {
        const bool branch_taken_0x1b97a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b97a0) {
            ctx->pc = 0x1B97C4u;
            goto label_1b97c4;
        }
    }
    ctx->pc = 0x1B97A8u;
label_1b97a8:
    // 0x1b97a8: 0x0  nop
    ctx->pc = 0x1b97a8u;
    // NOP
    // 0x1b97ac: 0x0  nop
    ctx->pc = 0x1b97acu;
    // NOP
    // 0x1b97b0: 0x0  nop
    ctx->pc = 0x1b97b0u;
    // NOP
    // 0x1b97b4: 0x0  nop
    ctx->pc = 0x1b97b4u;
    // NOP
    // 0x1b97b8: 0x0  nop
    ctx->pc = 0x1b97b8u;
    // NOP
    // 0x1b97bc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B97BCu;
    {
        const bool branch_taken_0x1b97bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b97bc) {
            ctx->pc = 0x1B97A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b97a8;
        }
    }
    ctx->pc = 0x1B97C4u;
label_1b97c4:
    // 0x1b97c4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b97c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1b97c8:
    // 0x1b97c8: 0x28430004  slti        $v1, $v0, 0x4
    ctx->pc = 0x1b97c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b97cc: 0x1460ffcb  bnez        $v1, . + 4 + (-0x35 << 2)
    ctx->pc = 0x1B97CCu;
    {
        const bool branch_taken_0x1b97cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B97D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97CCu;
            // 0x1b97d0: 0x24100  sll         $t0, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b97cc) {
            ctx->pc = 0x1B96FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b96fc;
        }
    }
    ctx->pc = 0x1B97D4u;
    // 0x1b97d4: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1b97d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1b97d8: 0x8c263d74  lw          $a2, 0x3D74($at)
    ctx->pc = 0x1b97d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 15732)));
    // 0x1b97dc: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B97DCu;
    {
        const bool branch_taken_0x1b97dc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B97E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97DCu;
            // 0x1b97e0: 0x3c01003c  lui         $at, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b97dc) {
            ctx->pc = 0x1B97E8u;
            goto label_1b97e8;
        }
    }
    ctx->pc = 0x1B97E4u;
    // 0x1b97e4: 0x24060300  addiu       $a2, $zero, 0x300
    ctx->pc = 0x1b97e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1b97e8:
    // 0x1b97e8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b97e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b97ec: 0x90273d73  lbu         $a3, 0x3D73($at)
    ctx->pc = 0x1b97ecu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 15731)));
    // 0x1b97f0: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1b97f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1b97f4: 0x90283d78  lbu         $t0, 0x3D78($at)
    ctx->pc = 0x1b97f4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 15736)));
    // 0x1b97f8: 0xc06b3e0  jal         func_1ACF80
    ctx->pc = 0x1B97F8u;
    SET_GPR_U32(ctx, 31, 0x1B9800u);
    ctx->pc = 0x1B97FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97F8u;
            // 0x1b97fc: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF80u;
    if (runtime->hasFunction(0x1ACF80u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9800u; }
        if (ctx->pc != 0x1B9800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF80_0x1acf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9800u; }
        if (ctx->pc != 0x1B9800u) { return; }
    }
    ctx->pc = 0x1B9800u;
label_1b9800:
    // 0x1b9800: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b9800u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9804: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b9804u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9808: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B980Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9808u;
            // 0x1b980c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9810u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
