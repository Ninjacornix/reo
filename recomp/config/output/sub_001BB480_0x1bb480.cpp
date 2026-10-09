#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB480
// Address: 0x1bb480 - 0x1bb5b4
void sub_001BB480_0x1bb480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB480_0x1bb480");
#endif

    switch (ctx->pc) {
        case 0x1bb4b0u: goto label_1bb4b0;
        default: break;
    }

    ctx->pc = 0x1bb480u;

    // 0x1bb480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb484: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb488: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1bb488u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1bb48c: 0x14600013  bnez        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BB48Cu;
    {
        const bool branch_taken_0x1bb48c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB48Cu;
            // 0x1bb490: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb48c) {
            ctx->pc = 0x1BB4DCu;
            goto label_1bb4dc;
        }
    }
    ctx->pc = 0x1BB494u;
    // 0x1bb494: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb494u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb498: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bb498u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb49c: 0xa0820008  sb          $v0, 0x8($a0)
    ctx->pc = 0x1bb49cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bb4a0: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1bb4a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1bb4a4: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb4a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BB4A8u;
    SET_GPR_U32(ctx, 31, 0x1BB4B0u);
    ctx->pc = 0x1BB4ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4A8u;
            // 0x1bb4ac: 0x24846650  addiu       $a0, $a0, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB4B0u; }
        if (ctx->pc != 0x1BB4B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB4B0u; }
        if (ctx->pc != 0x1BB4B0u) { return; }
    }
    ctx->pc = 0x1BB4B0u;
label_1bb4b0:
    // 0x1bb4b0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4b4: 0x24030280  addiu       $v1, $zero, 0x280
    ctx->pc = 0x1bb4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bb4b8: 0xa4206664  sh          $zero, 0x6664($at)
    ctx->pc = 0x1bb4b8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26212), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bb4bc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4c0: 0xa4236668  sh          $v1, 0x6668($at)
    ctx->pc = 0x1bb4c0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26216), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bb4c4: 0x240301e0  addiu       $v1, $zero, 0x1E0
    ctx->pc = 0x1bb4c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 480));
    // 0x1bb4c8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4cc: 0xa423666a  sh          $v1, 0x666A($at)
    ctx->pc = 0x1bb4ccu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26218), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bb4d0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4d4: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1BB4D4u;
    {
        const bool branch_taken_0x1bb4d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4D4u;
            // 0x1bb4d8: 0xa4206666  sh          $zero, 0x6666($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 26214), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4d4) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB4DCu;
label_1bb4dc:
    // 0x1bb4dc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bb4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb4e0: 0x90246650  lbu         $a0, 0x6650($at)
    ctx->pc = 0x1bb4e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb4e4: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1BB4E4u;
    {
        const bool branch_taken_0x1bb4e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB4E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4E4u;
            // 0x1bb4e8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4e4) {
            ctx->pc = 0x1BB54Cu;
            goto label_1bb54c;
        }
    }
    ctx->pc = 0x1BB4ECu;
    // 0x1bb4ec: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB4ECu;
    {
        const bool branch_taken_0x1bb4ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB4F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4ECu;
            // 0x1bb4f0: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4ec) {
            ctx->pc = 0x1BB504u;
            goto label_1bb504;
        }
    }
    ctx->pc = 0x1BB4F4u;
    // 0x1bb4f4: 0x1080002c  beqz        $a0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1BB4F4u;
    {
        const bool branch_taken_0x1bb4f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb4f4) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB4FCu;
    // 0x1bb4fc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1BB4FCu;
    {
        const bool branch_taken_0x1bb4fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4FCu;
            // 0x1bb500: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4fc) {
            ctx->pc = 0x1BB594u;
            goto label_1bb594;
        }
    }
    ctx->pc = 0x1BB504u;
label_1bb504:
    // 0x1bb504: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bb504u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bb508: 0xc422665c  lwc1        $f2, 0x665C($at)
    ctx->pc = 0x1bb508u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26204)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1bb50c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1bb50cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb510: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb514: 0xc4216660  lwc1        $f1, 0x6660($at)
    ctx->pc = 0x1bb514u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26208)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1bb518: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1bb518u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1bb51c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb520: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1bb520u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1bb524: 0x45010020  bc1t        . + 4 + (0x20 << 2)
    ctx->pc = 0x1BB524u;
    {
        const bool branch_taken_0x1bb524 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1BB528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB524u;
            // 0x1bb528: 0xe421665c  swc1        $f1, 0x665C($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb524) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB52Cu;
    // 0x1bb52c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb52cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb530: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1bb530u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1bb534: 0xe420665c  swc1        $f0, 0x665C($at)
    ctx->pc = 0x1bb534u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
    // 0x1bb538: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb538u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb53c: 0xa0236650  sb          $v1, 0x6650($at)
    ctx->pc = 0x1bb53cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bb540: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb540u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb544: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BB544u;
    {
        const bool branch_taken_0x1bb544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB544u;
            // 0x1bb548: 0xac236654  sw          $v1, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb544) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB54Cu;
label_1bb54c:
    // 0x1bb54c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb54cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb550: 0xc422665c  lwc1        $f2, 0x665C($at)
    ctx->pc = 0x1bb550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26204)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1bb554: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1bb554u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb558: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb558u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb55c: 0xc4216660  lwc1        $f1, 0x6660($at)
    ctx->pc = 0x1bb55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26208)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1bb560: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1bb560u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1bb564: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb568: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1bb568u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1bb56c: 0x4500000e  bc1f        . + 4 + (0xE << 2)
    ctx->pc = 0x1BB56Cu;
    {
        const bool branch_taken_0x1bb56c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1BB570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB56Cu;
            // 0x1bb570: 0xe421665c  swc1        $f1, 0x665C($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb56c) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB574u;
    // 0x1bb574: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb574u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb578: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1bb578u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1bb57c: 0xe420665c  swc1        $f0, 0x665C($at)
    ctx->pc = 0x1bb57cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
    // 0x1bb580: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb580u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb584: 0xac236654  sw          $v1, 0x6654($at)
    ctx->pc = 0x1bb584u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
    // 0x1bb588: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb588u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb58c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BB58Cu;
    {
        const bool branch_taken_0x1bb58c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB58Cu;
            // 0x1bb590: 0xa0206650  sb          $zero, 0x6650($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb58c) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB594u;
label_1bb594:
    // 0x1bb594: 0x8c236654  lw          $v1, 0x6654($at)
    ctx->pc = 0x1bb594u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26196)));
    // 0x1bb598: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BB598u;
    {
        const bool branch_taken_0x1bb598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb598) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB5A0u;
    // 0x1bb5a0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb5a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5a4: 0xa0206650  sb          $zero, 0x6650($at)
    ctx->pc = 0x1bb5a4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 0));
label_1bb5a8:
    // 0x1bb5a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb5a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb5ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB5ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB5ACu;
            // 0x1bb5b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB5B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
