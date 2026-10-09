#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D400
// Address: 0x11d400 - 0x11d534
void sub_0011D400_0x11d400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D400_0x11d400");
#endif

    switch (ctx->pc) {
        case 0x11d414u: goto label_11d414;
        default: break;
    }

    ctx->pc = 0x11d400u;

    // 0x11d400: 0x3c010021  lui         $at, 0x21
    ctx->pc = 0x11d400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)33 << 16));
    // 0x11d404: 0x8c21a138  lw          $at, -0x5EC8($at)
    ctx->pc = 0x11d404u;
    SET_GPR_S32(ctx, 1, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294943032)));
    // 0x11d408: 0x3c1d0026  lui         $sp, 0x26
    ctx->pc = 0x11d408u;
    SET_GPR_S32(ctx, 29, (int32_t)((uint32_t)38 << 16));
    // 0x11d40c: 0x20f809  jalr        $at
    ctx->pc = 0x11D40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x11D414u);
        ctx->pc = 0x11D410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D40Cu;
            // 0x11d410: 0x27bdf6c0  addiu       $sp, $sp, -0x940 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294964928));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11D414u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D414u: goto label_11d414;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11D414u; }
            if (ctx->pc != 0x11D414u) { return; }
        }
        }
    }
    ctx->pc = 0x11D414u;
label_11d414:
    // 0x11d414: 0x2403ffac  addiu       $v1, $zero, -0x54
    ctx->pc = 0x11d414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967212));
    // 0x11d418: 0xc  syscall     0
    ctx->pc = 0x11d418u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d41c: 0x0  nop
    ctx->pc = 0x11d41cu;
    // NOP
    // 0x11d420: 0x0  nop
    ctx->pc = 0x11d420u;
    // NOP
    // 0x11d424: 0x0  nop
    ctx->pc = 0x11d424u;
    // NOP
    // 0x11d428: 0x0  nop
    ctx->pc = 0x11d428u;
    // NOP
    // 0x11d42c: 0x0  nop
    ctx->pc = 0x11d42cu;
    // NOP
    // 0x11d430: 0x0  nop
    ctx->pc = 0x11d430u;
    // NOP
    // 0x11d434: 0x0  nop
    ctx->pc = 0x11d434u;
    // NOP
    // 0x11d438: 0x0  nop
    ctx->pc = 0x11d438u;
    // NOP
    // 0x11d43c: 0x0  nop
    ctx->pc = 0x11d43cu;
    // NOP
    // 0x11d440: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d440u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d444: 0x241affe4  addiu       $k0, $zero, -0x1C
    ctx->pc = 0x11d444u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967268));
    // 0x11d448: 0x3a0824  and         $at, $at, $k0
    ctx->pc = 0x11d448u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 26));
    // 0x11d44c: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d44cu;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d450: 0x40f  sync.p
    ctx->pc = 0x11d450u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d454: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d454u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d458: 0x8c42f8e8  lw          $v0, -0x718($v0)
    ctx->pc = 0x11d458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294965480)));
    // 0x11d45c: 0x40827000  mtc0        $v0, EPC
    ctx->pc = 0x11d45cu;
    ctx->cop0_epc = GPR_U32(ctx, 2);
    // 0x11d460: 0x40f  sync.p
    ctx->pc = 0x11d460u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d468: 0xdc42f8c0  ld          $v0, -0x740($v0)
    ctx->pc = 0x11d468u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965440)));
    // 0x11d46c: 0x400011  mthi        $v0
    ctx->pc = 0x11d46cu;
    ctx->hi = GPR_U64(ctx, 2);
    // 0x11d470: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d470u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d474: 0xdc42f8c8  ld          $v0, -0x738($v0)
    ctx->pc = 0x11d474u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965448)));
    // 0x11d478: 0x70400011  mthi1       $v0
    ctx->pc = 0x11d478u;
    ctx->hi1 = GPR_U64(ctx, 2);
    // 0x11d47c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d47cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d480: 0xdc42f8d0  ld          $v0, -0x730($v0)
    ctx->pc = 0x11d480u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965456)));
    // 0x11d484: 0x400013  mtlo        $v0
    ctx->pc = 0x11d484u;
    ctx->lo = GPR_U64(ctx, 2);
    // 0x11d488: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d488u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d48c: 0xdc42f8d8  ld          $v0, -0x728($v0)
    ctx->pc = 0x11d48cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965464)));
    // 0x11d490: 0x70400013  mtlo1       $v0
    ctx->pc = 0x11d490u;
    ctx->lo1 = GPR_U64(ctx, 2);
    // 0x11d494: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d494u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d498: 0xdc42f8e0  ld          $v0, -0x720($v0)
    ctx->pc = 0x11d498u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965472)));
    // 0x11d49c: 0x400029  mtsa        $v0
    ctx->pc = 0x11d49cu;
    ctx->sa = GPR_U32(ctx, 2) & 0x7F;
    // 0x11d4a0: 0x40f  sync.p
    ctx->pc = 0x11d4a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d4a4: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d4a4u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d4a8: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d4a8u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d4ac: 0x7b410010  lq          $at, 0x10($k0)
    ctx->pc = 0x11d4acu;
    SET_GPR_VEC(ctx, 1, READ128(ADD32(GPR_U32(ctx, 26), 16)));
    // 0x11d4b0: 0x7b420020  lq          $v0, 0x20($k0)
    ctx->pc = 0x11d4b0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 26), 32)));
    // 0x11d4b4: 0x7b430030  lq          $v1, 0x30($k0)
    ctx->pc = 0x11d4b4u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 26), 48)));
    // 0x11d4b8: 0x7b440040  lq          $a0, 0x40($k0)
    ctx->pc = 0x11d4b8u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 26), 64)));
    // 0x11d4bc: 0x7b450050  lq          $a1, 0x50($k0)
    ctx->pc = 0x11d4bcu;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 26), 80)));
    // 0x11d4c0: 0x7b460060  lq          $a2, 0x60($k0)
    ctx->pc = 0x11d4c0u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 26), 96)));
    // 0x11d4c4: 0x7b470070  lq          $a3, 0x70($k0)
    ctx->pc = 0x11d4c4u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 26), 112)));
    // 0x11d4c8: 0x7b480080  lq          $t0, 0x80($k0)
    ctx->pc = 0x11d4c8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 26), 128)));
    // 0x11d4cc: 0x7b490090  lq          $t1, 0x90($k0)
    ctx->pc = 0x11d4ccu;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 26), 144)));
    // 0x11d4d0: 0x7b4a00a0  lq          $t2, 0xA0($k0)
    ctx->pc = 0x11d4d0u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 26), 160)));
    // 0x11d4d4: 0x7b4b00b0  lq          $t3, 0xB0($k0)
    ctx->pc = 0x11d4d4u;
    SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 26), 176)));
    // 0x11d4d8: 0x7b4c00c0  lq          $t4, 0xC0($k0)
    ctx->pc = 0x11d4d8u;
    SET_GPR_VEC(ctx, 12, READ128(ADD32(GPR_U32(ctx, 26), 192)));
    // 0x11d4dc: 0x7b4d00d0  lq          $t5, 0xD0($k0)
    ctx->pc = 0x11d4dcu;
    SET_GPR_VEC(ctx, 13, READ128(ADD32(GPR_U32(ctx, 26), 208)));
    // 0x11d4e0: 0x7b4e00e0  lq          $t6, 0xE0($k0)
    ctx->pc = 0x11d4e0u;
    SET_GPR_VEC(ctx, 14, READ128(ADD32(GPR_U32(ctx, 26), 224)));
    // 0x11d4e4: 0x7b4f00f0  lq          $t7, 0xF0($k0)
    ctx->pc = 0x11d4e4u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 26), 240)));
    // 0x11d4e8: 0x7b500100  lq          $s0, 0x100($k0)
    ctx->pc = 0x11d4e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 26), 256)));
    // 0x11d4ec: 0x7b510110  lq          $s1, 0x110($k0)
    ctx->pc = 0x11d4ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 26), 272)));
    // 0x11d4f0: 0x7b520120  lq          $s2, 0x120($k0)
    ctx->pc = 0x11d4f0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 26), 288)));
    // 0x11d4f4: 0x7b530130  lq          $s3, 0x130($k0)
    ctx->pc = 0x11d4f4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 26), 304)));
    // 0x11d4f8: 0x7b540140  lq          $s4, 0x140($k0)
    ctx->pc = 0x11d4f8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 26), 320)));
    // 0x11d4fc: 0x7b550150  lq          $s5, 0x150($k0)
    ctx->pc = 0x11d4fcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 26), 336)));
    // 0x11d500: 0x7b560160  lq          $s6, 0x160($k0)
    ctx->pc = 0x11d500u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 26), 352)));
    // 0x11d504: 0x7b570170  lq          $s7, 0x170($k0)
    ctx->pc = 0x11d504u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 26), 368)));
    // 0x11d508: 0x7b580180  lq          $t8, 0x180($k0)
    ctx->pc = 0x11d508u;
    SET_GPR_VEC(ctx, 24, READ128(ADD32(GPR_U32(ctx, 26), 384)));
    // 0x11d50c: 0x7b590190  lq          $t9, 0x190($k0)
    ctx->pc = 0x11d50cu;
    SET_GPR_VEC(ctx, 25, READ128(ADD32(GPR_U32(ctx, 26), 400)));
    // 0x11d510: 0x7b5c01c0  lq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d510u;
    SET_GPR_VEC(ctx, 28, READ128(ADD32(GPR_U32(ctx, 26), 448)));
    // 0x11d514: 0x7b5d01d0  lq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d514u;
    SET_GPR_VEC(ctx, 29, READ128(ADD32(GPR_U32(ctx, 26), 464)));
    // 0x11d518: 0x7b5e01e0  lq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d518u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 26), 480)));
    // 0x11d51c: 0x7b5f01f0  lq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d51cu;
    SET_GPR_VEC(ctx, 31, READ128(ADD32(GPR_U32(ctx, 26), 496)));
    // 0x11d520: 0x401a6000  mfc0        $k0, Status
    ctx->pc = 0x11d520u;
    SET_GPR_S32(ctx, 26, (int32_t)ctx->cop0_status);
    // 0x11d524: 0x375a0013  ori         $k0, $k0, 0x13
    ctx->pc = 0x11d524u;
    SET_GPR_U64(ctx, 26, GPR_U64(ctx, 26) | (uint64_t)(uint16_t)19);
    // 0x11d528: 0x409a6000  mtc0        $k0, Status
    ctx->pc = 0x11d528u;
    ctx->cop0_status = GPR_U32(ctx, 26) & 0xFF57FFFF;
    // 0x11d52c: 0x40f  sync.p
    ctx->pc = 0x11d52cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d530: 0x42000018  eret
    ctx->pc = 0x11d530u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    ctx->pc = GPR_U32(ctx, 31); return;
}
