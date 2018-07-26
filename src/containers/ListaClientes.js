import React from "react";

const ListaClientes = () => {
    return (
        <div>
            <table className="table">
                <thead className="thead-light">
                    <tr>
                        <th scope="col">ID</th>
                        <th scope="col">Nome</th>
                        <th scope="col">Endereço</th>
                        <th scope="col">Telefone</th>
                        <th scope="col">Data de nascimento</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <th scope="row">1</th>
                        <td>Cristiano Coelho</td>
                        <td>
                            Rua Pouso Alegre, 235, bairro Capelinha, Betim-MG
                            CEP: 32678-738
                        </td>
                        <td>(31)98587-7928</td>
                        <td>15/03/1994</td>
                    </tr>
                </tbody>
            </table>
        </div>
    );
};

export default ListaClientes;
